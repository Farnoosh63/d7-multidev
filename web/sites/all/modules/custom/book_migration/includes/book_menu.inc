<?php
/**
 * @file
 * Contains BookLinksMigration.
 */

/**
 * Class for book outline migrations.
 */
class BookLinksMigration extends BookMenuMigration {
  /**
   * Construct the migration.
   *
   * @param array $arguments
   *   An associative array containing:
   *   - node_migrations: a string or array of strings naming the book node
   *     migrations.
   *
   * @throws \MigrateException
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    if (empty($arguments['node_migrations'])) {
      throw new MigrateException(t("No node_migrations provided in BookLinksMigration arguments."));
    }

    $this->addFieldMapping('book_id', 'bid')
      ->sourceMigration($this->node_migrations);
    $this->addFieldMapping('nid', 'nid')
      ->sourceMigration($this->node_migrations);

    // Updating existing menu based on destination mlid
    // rather than importing new menu link if mlid already exists on destination
    // We need these two lines because on briefingBookNodes system of records
    // is destination nid.
    $this->addFieldMapping('mlid', 'mlid');
    $this->systemOfRecord = Migration::DESTINATION;

    // These field values are set by the Book module.
    $this->removeFieldMapping('menu_name');
    $this->removeFieldMapping('module');
  }

  /**
   * {@inheritdoc}
   */
  protected function query() {
    // Manually define the fields because we're removing some that can no longer
    // be mapped - they're set by the Book module.
    $query = parent::query();
    $book_table_alias = $query
      ->condition('module', 'book')
      ->innerJoin('book', 'b', 'b.mlid = m.mlid');
    $all_fields = array(
      $book_table_alias => array('bid', 'nid'),
      'm' => array(
        'plid',
        'link_path',
        'router_path',
        'link_title',
        'options',
        'hidden',
        'external',
        'has_children',
        'expanded',
        'weight',
        'depth',
        'customized',
        'updated',
      ),
    );
    // Add {menu_links}.p1-p9.
    for ($i = 1; $i <= 9; $i++) {
      $all_fields['m'][] = 'p' . $i;
    }

    // Add the desired fields to the query explicitly.
    foreach ($all_fields as $table_alias => $fields) {
      foreach ($fields as $field) {
        $query->addField($table_alias, $field);
      }
    }

    $this->orderQuery($query);

    return $query;
  }

  /**
   * Orders the source query.
   *
   * With the default order, nodes from the same book will be processed one
   * after the other, proceeding in breadth-first order from the root, honoring
   * weights. A child class might want to change this to ensure that nodes in a
   * hierarchy are saved in a different order, or to provide a more efficient
   * query.
   *
   * @param SelectQueryInterface $query
   *   The query object with fields.
   */
  protected function orderQuery(SelectQueryInterface $query) {
    $query->orderBy('bid');
    $query->orderBy('depth');
    $query->orderBy('weight');
  }

  /**
   * {@inheritdoc}
   */
  protected function isValidMenuName($name) {
    return (substr($name, 0, 9) == 'book-toc-');
  }

  /**
   * {@inheritdoc}
   */
  protected function createDestination() {
    return new MigrateDestinationBookOutline();
  }

}
