<?php
/**
 * Implement hook_migrate_api().
 * Tells migrate module which migrate api we are going to use.
 */
function book_migration_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'book_migration' => array(
        'title' => t('Migrate book content type within Drupal'),
      ),
      'migrations' => array(),
    ),
  );

  $common_arguments = array(
    'source_connection' => 'drupal_7',
    'source_version' => 7,
    'group_name' => 'book_migration',
  );

  $node_arguments = array(
    'BriefingBookNodes' => array(
      'class_name' => 'BookNodeMigration',
      'description' => t('Migration of book content type'),
      'source_type' => 'book',
      'destination_type' => 'book',
    ),
    'BriefingBookFiles' => array(
      'class_name' => 'BookFileMigration',
      'description' => t('Migration of book Files content type'),
      'source_type' => 'book',
      'destination_type' => 'book',
      'source_dir' => 'https://live-d7-ci-multidev.pantheonsite.io/sites/default/files/',
    ),
    'BookMigrateOutline' => array(
      'class_name' => 'BookLinksMigration',
      'description' => t("Migration of book outlines"),
      'source_type' => 'book',
      'destination_type' => 'book',
      'node_migrations' => array(
        'BriefingBookNodes',
      ),
    ),
  );

  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  return $api;
}
