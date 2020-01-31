<?php
/**
 * Implement hook_migrate_api().
 * Tells migrate module which migrate api we are going to use.
 */
function book_migration_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'BriefingBookMigration' => array(
        'title' => t('Id of Book nodes'), // shows on /admin/content/migrate
      )
    ),
    // BriefingBookNodes is the name we use for drush mreg command
    'migrations' => array(
      'BriefingBookNodes' => array(
        'class_name' => 'TitleBookMigration',
        'group_name' => 'BriefingBookMigration',
      )
    )
  );
}
