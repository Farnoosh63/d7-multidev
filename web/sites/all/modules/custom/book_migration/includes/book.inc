<?php

/**
 * @file
 * Migration for book data
 */

class TitleBookMigration extends BookMigration {

  public function __construct($arguments) {

    if (!empty($arguments['default_language'])) {
      $this->defaultLanguage = $arguments['default_language'];
    }

    parent::__construct($arguments);
    $this->description = t('Import book data from pantheon database');

    // source
    $query = $this->getConnection()->select('node', 'n')
      ->fields('n', array('nid', 'title'))
      ->condition('type', 'book')
      ->isNotNull('n.nid');

    $this->source = new MigrateSourceSQL($query);

    // destination
    $this->destination = new MigrateDestinationNode('book');

    // mapping
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'nid' => array(
          'type' => 'INT',
          'length' => 10,
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Node ID.',
          'alias' => 'n',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('title', 'title');
  }

}
