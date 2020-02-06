<?php

  /**
   * @file
   * Migration for book data
   */

  class BookNodeMigration extends DrupalNode7Migration {

    public function __construct(array $arguments) {

      parent::__construct($arguments);
      $this->description = t('Import book node fields from pantheon database');
      $this->team = [
        new MigrateTeamMember('Farnoosh Johnson', 'fjohnson@urban.org', t('Implementor')),

      ];

      // Taxonomy Term
      $this->addFieldMapping('field_topics', 'field_topics');
      $this->addFieldMapping('field_topics:source_type')
        ->defaultValue('tid');

      // primary topic field reference entity
      $this->addFieldMapping('field_primary_topic', 'field_primary_topic');

      // Subtitle
      $this->addFieldMapping('field_sub_title', 'field_sub_title');

      // File
      $this->addFieldMapping('field_pdf', 'field_pdf')
        ->sourceMigration('BriefingBookFiles');
      $this->addFieldMapping('field_pdf:file_class')
        ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_pdf:preserve_files')
        ->defaultValue(TRUE);

      // Field Q&A TODO: field mapping wont import to destination
      $this->addFieldMapping('field_q_a:field_question_value', 'field_q_a:field_question_value');
      $this->addFieldMapping('field_q_a', 'field_q_a');
      $this->addFieldMapping('field_q_a:id', 'field_q_a:id');


    }

    /**
     * Implementation of Migration::prepareRow().
     *
     *
     * @param $row
     */
    public function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
//      drush_print_r($row);

    }




  }

  /**
   * Handling File import to a Drupal 7 source.
   *
   * The following optional arguments may be passed:
   * source_dir
   * destination_dir
   * please see https://www.drupal.org/node/1540106#source_dir
   */
  class BookFileMigration extends DrupalFile7Migration {

    public function __construct(array $arguments) {

      parent::__construct($arguments);

      $this->description = t('Import book file field from pantheon database');

      }

  }


