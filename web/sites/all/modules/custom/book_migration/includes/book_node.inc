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
      $this->addFieldMapping('field_q_a:field_answer:format', 'field_q_a:field_answer_format');
      $this->addFieldMapping('field_q_a:field_question:format', 'field_q_a:field_question_format');

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

      // Since the fid in destination is not the same as fid in source,
      // we are going to update the fid in destination in body
      module_load_include('inc', 'media_wysiwyg', 'filter');
      $row->body = preg_replace_callback(MEDIA_WYSIWYG_TOKEN_REGEX,
        function ($matches) use ($row) {
          return self::replaceSourceFidCallback($matches, $row);
        }, $row->body
      );

    }


    /**
     * Replace-Callback to replace fid in media filter tag
     */
    static protected function replaceSourceFidCallback(array $match, $row) {
      $media_token = str_replace("[[", "", $match);
      $media_token = str_replace("]]", "", $media_token);
      $media_token = $media_token[0];

      $media_token = drupal_json_decode($media_token);

      if (!$media_token) {
        return $match[0];
      }

      // Replace the source fid with destination fid.
      $migration = Migration::currentMigration();
      if ($media_token['fid'] && $dest_fid = $migration->handleSourceMigration('BriefingBookFiles', $media_token['fid'])) {
        $media_token['fid'] = $dest_fid;
      }
      else {
        $message = t('File id !fid not substituded by destination fid in media filter tag, because fid it was not found in source file migration. You need to fix source file migration first, otherwise media tag won\'t work properly.',
          array('!fid' => $media_token['fid'],
          ));
        $migration->queueMessage($message, MigrationBase::MESSAGE_ERROR);
        MigrationBase::displayMessage(t('Entity !id: ', array('!id' => current($migration->currentSourceKey()))) . $message);
      }
      return '[[' . drupal_json_encode($media_token) . ']]';
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
