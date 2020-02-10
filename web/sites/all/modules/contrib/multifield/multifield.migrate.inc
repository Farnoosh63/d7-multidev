<?php

/**
 * @file
 * Migrate integration for the Multifield module.
 *
 * Contains the MultifieldMigrateFieldHandler class.
 *
 * Requires Migrate 2.8. To migrate into fields inside of a multifield, use the
 * field name as the subfield.
 *
 * If using a multi-value  multifield, the individual subfields that are
 * migrated must be identical in size. In the example below, label, slug and
 * description should all the same sized arrays. See
 * https://www.drupal.org/node/1159234 for a more thorough description of multi-
 * valued migrations.
 *
 * @code
 * $this->addFieldMapping('field_my_multifield:field_label', 'label');
 * $this->addFieldMapping('field_my_multifield:field_slug', 'slug');
 * $this->addFieldMapping('field_my_multifield:field_description', 'description');
 * @endcode
 *
 * Within each subfield, you can use the field type's usual subfields, just like
 * you would if the field were not nested inside a multifield. For example, to
 * set the summary and text format on a long text field:
 *
 * @code
 * $this->addFieldMapping('field_my_multifield:field_description', 'description');
 * $this->addFieldMapping('field_my_multifield:field_description:summary', 'short_description');
 * $this->addFieldMapping('field_my_multifield:field_description:format')
 *   ->defaultValue('plain_text');
 * @endcode
 */

/**
 * Implements hook_migrate_api().
 */
function multifield_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array('MultifieldMigrateFieldHandler'),
  );
}

/**
 * Migrate field handler class for multifield fields.
 */
class MultifieldMigrateFieldHandler extends MigrateFieldHandler {

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    // Register this as the handler for all multifield types.
    $field_types = module_invoke('multifield', 'field_info');
    $this->registerTypes(array_keys($field_types));
  }

  /**
   * {@inheritdoc}
   */
  public function fields($type, $instance, $migration = NULL) {
    // Display the field label and name for each field in a multifield.
    $handler = new MigrateFieldsEntityHandler();
    $field = field_info_field($instance['field_name']);
    $machine_name = multifield_extract_multifield_machine_name($field);
    $fields = $handler->fields('multifield', $machine_name, $migration);
    if (field_is_translatable($instance['entity_type'], $field)) {
      $fields['language'] = t(
        'Subfield: <a href="@doc">Language for the field</a>',
        array('@doc' => 'http://drupal.org/node/1224042#language')
      );
    }
    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    // Get the subfield arguments.
    $arguments = $entity->{$field_info['field_name']}['arguments'];
    $subfield_arguments = array();


    // Collate the subfield values.
    $items = array();
    foreach ($arguments as $field_name => $field_values) {
      // Extract subfield arguments (e.g. preserve_files, file_function).
      if (is_array($field_values) && array_key_exists('arguments', $field_values)) {
        $subfield_arguments[$field_name] = $field_values['arguments'];
        unset($field_values['arguments']);
      }

      // Normalize values to arrays.
      if (!is_array($field_values)) {
        $field_values = array($field_values);
      }

      // Add each field value to a separate multifield.
      foreach ($field_values as $delta => $value) {
        if (!isset($items[$delta])) {
          $items[$delta] = array();
        }

        $items[$delta][$field_name] = array($value);
      }
    }

    // Remove multifield values that are completely empty.
    foreach ($items as $delta => $value) {
      $is_empty = TRUE;

      foreach ($value as $field_name => $v) {
        if (reset($v) !== NULL) {
          $is_empty = FALSE;
        }
      }

      if ($is_empty) {
        unset($items[$delta]);
      }
    }

    $return = array();

    // Migrate each set of subfields.
    // @see MigrateFieldsEntityHandler::prepare()
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    $machine_name = multifield_extract_multifield_machine_name($field_info);
    $subinstances = field_info_instances('multifield', $machine_name);
    foreach ($items as $delta => $item) {
      $pseudo_entity = _multifield_field_item_to_entity($machine_name, $item);
      foreach ($subinstances as $subfield_name => $subinstance) {
        if (property_exists($pseudo_entity, $subfield_name)) {
          $subfield = field_info_field($subfield_name);
          // The fourth value passed should be an array with an 'arguments' key
          // containing $subfield_arguments.
          $values = array();
          foreach ($pseudo_entity->{$subfield_name} as $key => $subfield_data) {
            $values[] = $pseudo_entity->{$subfield_name}[$key];
          }
          if (isset($subfield_arguments) && array_key_exists($subfield_name, $subfield_arguments)) {
            // Get subfield arguments corresponding to current delta
            foreach ($subfield_arguments[$subfield_name] as $subfield_argument_key => $subfield_argument) {
              if (is_array($subfield_argument)) {
                $values['arguments'][$subfield_argument_key][] = $subfield_argument[$delta];
              }
              else {
                $values['arguments'][$subfield_argument_key][] = $subfield_argument;
              }
            }
          }
          $pseudo_entity->$subfield_name = migrate_field_handler_invoke_all($pseudo_entity, $subfield, $subinstance, $values);
        }
      }
      $return[$language][$delta] = _multifield_field_entity_to_item($pseudo_entity);
    }

    return !empty($return) ? $return : NULL;
  }
}
