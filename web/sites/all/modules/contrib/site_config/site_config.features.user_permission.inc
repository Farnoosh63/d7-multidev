<?php

/**
 * @file
 * site_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function site_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  return $permissions;
}
