<?php

/**
 * @file
 * site_config.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function site_config_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book_main|node|book|form';
  $field_group->group_name = 'group_book_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '0',
    'children' => array(
      0 => 'group_bp_content',
      1 => 'group_bp_downloads',
      2 => 'group_bp_info',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-book-main field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_book_main|node|book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bp_content|node|book|form';
  $field_group->group_name = 'group_bp_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'book';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_book_main';
  $field_group->data = array(
    'label' => 'Book Page Content',
    'weight' => '11',
    'children' => array(
      0 => 'body',
      1 => 'field_q_a',
      2 => 'field_further_reading',
      3 => 'field_highlights',
      4 => 'field_long_references',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bp-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_bp_content|node|book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bp_downloads|node|book|form';
  $field_group->group_name = 'group_bp_downloads';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'book';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_book_main';
  $field_group->data = array(
    'label' => 'Book Downloads',
    'weight' => '12',
    'children' => array(
      0 => 'field_pdf',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bp-downloads field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_bp_downloads|node|book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bp_info|node|book|form';
  $field_group->group_name = 'group_bp_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'book';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_book_main';
  $field_group->data = array(
    'label' => 'Book Page Info',
    'weight' => '10',
    'children' => array(
      0 => 'field_sub_title',
      1 => 'field_topics',
      2 => 'field_primary_topic',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bp-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_bp_info|node|book|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Book Downloads');
  t('Book Page Content');
  t('Book Page Info');
  t('Main');

  return $field_groups;
}
