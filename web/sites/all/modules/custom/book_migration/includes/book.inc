<?php

/**
 * @file
 * Migration for book data
 */

class TitleBookMigration extends BookMigration {

  /**
   * @param array $arguments
   */
  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->description = t('Import book data from pantheon database');

    // source
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->addFieldMapping('language', 'language')
      ->defaultValue($this->defaultLanguage);
    $this->addFieldMapping('body', 'body_value');
    $this->addFieldMapping('body:summary', 'body_summary');
    $this->addFieldMapping('body:format', 'body_format');

  }



  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', 'drupal_7')
      ->select('node', 'n')
      ->fields('n', array('nid', 'vid', 'language', 'title', 'uid',
        'status', 'created', 'changed', 'comment', 'promote', 'sticky',
        'tnid', 'translate'))
      ->condition('n.type', 'book')
      ->orderBy($this->newOnly ? 'n.nid' : 'n.changed');

    // Join field_data_body and node tables
    if (Database::getConnection('default', 'drupal_7')
      ->schema()->tableExists('field_data_body')) {
      $query->leftJoin('field_data_body', 'fdb', 'n.nid=fdb.entity_id');
      $query->addField('fdb', 'body_value');
      $query->addField('fdb', 'body_summary');
      $query->addField('fdb', 'body_format');
    }
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }
}
