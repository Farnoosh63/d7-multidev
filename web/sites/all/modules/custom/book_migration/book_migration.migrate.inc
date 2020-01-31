<?php
/**
 * Implement hook_migrate_api().
 * Tells migrate module which migrate api we are going to use.
 */
function book_migration_migrate_api() {
  return array(
    'api' => 2,
  );
}
