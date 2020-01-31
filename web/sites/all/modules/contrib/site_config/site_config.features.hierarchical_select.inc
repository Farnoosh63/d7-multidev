<?php

/**
 * @file
 * site_config.features.hierarchical_select.inc
 */

/**
 * Implements hook_hierarchical_select_default_configs().
 */
function site_config_hierarchical_select_default_configs() {
$configs = array();
$config = array(
  'save_lineage' => '1',
  'enforce_deepest' => '0',
  'resizable' => '1',
  'level_labels' => array(
    'status' => 0,
    'labels' => array(
      '0' => '',
      '1' => '',
    ),
  ),
  'dropbox' => array(
    'status' => 1,
    'title' => 'All selections',
    'limit' => '0',
    'reset_hs' => '1',
    'sort' => 1,
  ),
  'editability' => array(
    'status' => 0,
    'item_types' => array(
      '0' => '',
      '1' => '',
    ),
    'allowed_levels' => array(
      '0' => 1,
      '1' => 1,
    ),
    'allow_new_levels' => 0,
    'max_levels' => '1',
  ),
  'entity_count' => array(
    'enabled' => 0,
    'require_entity' => 0,
    'settings' => array(
      'count_children' => 0,
      'entity_types' => array(
        'node' => array(
          'count_node' => array(
            'article' => 0,
            'page' => 0,
            'book' => 0,
          ),
        ),
      ),
    ),
  ),
  'animation_delay' => 400,
  'special_items' => array(),
  'render_flat_select' => 0,
  'config_id' => 'taxonomy-field_topics',
);

$configs['taxonomy-field_topics'] = $config;
return $configs;
}
