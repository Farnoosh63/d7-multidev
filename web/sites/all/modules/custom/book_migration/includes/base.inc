<?php
  abstract class BookMigration extends BookDrupalMigration {

    /**
     * Default language to apply to the node and it's body field.
     *
     * @var string
     */
    protected $defaultLanguage = LANGUAGE_NONE;

    /**
     * @param array $arguments
     */
    public function __construct($arguments) {

      if (!empty($arguments['default_language'])) {
        $this->defaultLanguage = $arguments['default_language'];
      }
      $this->sourceVersion = '7';
      parent::__construct($arguments);

      $this->team = [
        new MigrateTeamMember('Farnoosh Johnson', 'fjohnson@urban.org', t('Implementor')),

      ];

      $this->sourceFields = [
        'nid'          => t('Node ID'),
        'title'        => t('Title'),
        'uid'          => t('Authored by (uid)'),
        'created'      => t('Created timestamp'),
        'changed'      => t('Modified timestamp'),
        'status'       => t('Published'),
        'promote'      => t('Promoted to front page'),
        'sticky'       => t('Sticky at top of lists'),
        'language'     => t('Language (fr, en, ...)'),
        'tnid'         => t('The translation set id for this node'),
      ];


      $this->destination = new MigrateDestinationNode('book');

      $this->map = new MigrateSQLMap($this->machineName,
        array(
          'nid' => array('type' => 'int',
                         'unsigned' => TRUE,
                         'not null' => TRUE,
                         'description' => 'Source node ID',
                         'alias' => 'n',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
      );

      // Setup common mappings
      $this->addSimpleMappings(array('title', 'status', 'created', 'changed',
        'comment', 'promote', 'sticky'));
    }

    // connection to the source database
    public function getConnection($connection = 'drupal_7') {
      return Database::getConnection('default', $connection);
    }
    /**
     * Called after the query data is fetched - we'll use this to populate the
     * source row with the CCK fields.
     */
    public function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }

      // Add the path to the source row, if relevant
      if ($this->moduleExists('path')) {
        if ($path) {
          $row->path = $path;
        }
      }
    }

  }
