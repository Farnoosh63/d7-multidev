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
      $this->addFieldMapping('field_topics:create_term')
        ->defaultValue(FALSE);

      // Primary topic field reference entity
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
      $this->addFieldMapping('field_pdf:description', 'field_pdf:description')
        ->defaultValue('');

      // Q&A multifield
      $this->addFieldMapping('field_q_a:field_question', 'field_q_a:field_question_value');
      $this->addFieldMapping('field_q_a:field_answer', 'field_q_a');

      // Further reading multifield
      $this->addFieldMapping('field_further_reading:field_source','field_further_reading');
      $this->addFieldMapping('field_further_reading:field_source:format','field_further_reading:field_source_format');

      $this->addFieldMapping('field_further_reading:field_link','field_further_reading:field_link_url');
      $this->addFieldMapping('field_further_reading:field_link:title','field_further_reading:field_link_title');
      $this->addFieldMapping('field_further_reading:field_link:attributes','field_further_reading:field_link_attributes');
      $this->addFieldMapping('field_further_reading:field_link_date','field_further_reading:field_link_date_value');

      // Highlights
      $this->addFieldMapping('field_highlights','field_highlights');
      $this->addFieldMapping('field_highlights:format','field_highlights:format');

      // References
      $this->addFieldMapping('field_long_references','field_long_references');
      $this->addFieldMapping('field_long_references:format','field_long_references:format');
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

      // load html from body value
//      $doc = new DOMDocument();
//      $doc->loadHTML($row->body[0]);
//      $body_html = $doc->saveHTML();
//      $inline_img = $body_html->find("fid");
//      drush_print_r($doc->saveHTML());
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
