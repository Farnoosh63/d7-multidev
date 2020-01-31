<?php
  abstract class BookMigration extends Migration {

    public function __construct($arguments) {
      parent::__construct($arguments);

      $this->team = array(
        new MigrateTeamMember('Farnoosh Johnson', 'fjohnson@urban.org', t('Implementor')),

      );
    }

    // connection to the source database
  public function getConnection($connection = 'pantheon') {
    return Database::getConnection('default', $connection);
  }

}
