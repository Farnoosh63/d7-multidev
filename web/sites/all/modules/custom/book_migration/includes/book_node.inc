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

      // These fields have been unmigrated in migrate_d2d module for destination.
      // We set this up unmigrated for source as well.
      $this->addUnmigratedSources(array('revision',
        'revision_uid', 'log'));

      // Updating existing content based on destination nid
      // rather than importing new content if nid already exists on destination
      // https://www.drupal.org/node/1117454
//      $this->addFieldMapping('nid', 'nid');
//      $this->systemOfRecord = Migration::DESTINATION;
//      $this->addFieldMapping('is_new')->defaultValue(TRUE);

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
      $this->addFieldMapping('field_pdf:display', 'field_pdf:display');

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
    public function replaceSourceFidCallback(array $match, $row) {
      $media_token = str_replace("[[", "", $match);
      $media_token = str_replace("]]", "", $media_token);
      $media_token = $media_token[0];

      $media_token = drupal_json_decode($media_token);

      if (!$media_token) {
        return $match[0];
      }

      // node database in destination
      $fid_exists_on_destination = db_select('file_managed', 'fm')
        ->fields('fm', array('fid'))
        ->condition('fm.fid', $media_token['fid'])
        ->execute()
        ->fetchAllAssoc('fid', PDO::FETCH_ASSOC);
      $fid_exists_on_destination = reset($fid_exists_on_destination);
      if ($fid_exists_on_destination['fid']) {
        // Replace the source fid with destination fid.
        $migration = Migration::currentMigration();
        if ($media_token['fid'] && $dest_fid = $migration->handleSourceMigration('BriefingBookFiles', $media_token['fid'])) {
          $media_token['fid'] = $dest_fid;
        }

      }
      else {
        // This file id not exists on destination table.
        $file_id_from_media_token = $media_token['fid'];
        $source_query = Database::getConnection('default', $this->sourceConnection)
          ->select('file_managed', 'fm')
          ->fields('fm', array('uri'))
          ->condition('fm.fid', $file_id_from_media_token)
          ->execute()
          ->fetchAllAssoc('uri', PDO::FETCH_ASSOC);
        $file = reset($source_query);

        $uri = $file['uri'];

//          Migration::registerMigration('BookFileMigration', 'BriefingBookFiles', array('source_dir'));
//          $this->source_dir = Migration::getInstance('BriefingBookFiles');

//        drush_print_r($this->source_dir);
        $source_file_url = str_ireplace('public://', 'https://live-d7-ci-multidev.pantheonsite.io/sites/default/files/', $uri);

        $file = self::importFileFromSource($source_file_url);
        $media_token['fid'] = $file->fid;
      }

      return '[[' . drupal_json_encode($media_token) . ']]';
    }

    static protected function importFileFromSource($uri) {

      $file_contents = file_get_contents($uri);
      $folder_base = 'book_images';
      $destination = 'public://' . $folder_base;
      file_prepare_directory($destination, FILE_CREATE_DIRECTORY);

      $path = parse_url($uri, PHP_URL_PATH);
      $filename = basename($path);

      // Transliterate filename.
      $filename = transliteration_clean_filename($filename,language_default());

      // Create file object
      $file = new stdClass();
      $file->fid = NULL;
      $file->uri = $uri;
      $file->filename = basename($uri);
      $file->filemime = file_get_mimetype($uri);
      $file->uid = $GLOBALS['user']->uid;
      $file->destination = file_destination($destination . '/' . $file->filename, FILE_EXISTS_REPLACE);
      $file->type = 'image';

      // Saves a file to the specified destination and creates a database entry.
      $file = file_save_data($file_contents, $destination . '/'. $filename, FILE_EXISTS_REPLACE);
      return $file;
    }

    /**
     * List all the node IDs that were deleted in the source.
     */
    public function postImport() {

      $sourceNodes = Database::getConnection('default', $this->sourceConnection)
        ->select('node', 'ns')
        ->fields('ns', array('nid'))
        ->condition('ns.type', 'book')
        ->execute()
        ->fetchAllAssoc('nid', PDO::FETCH_ASSOC);

      // node database in destination
      $destNode = db_select('node', 'nd')
        ->fields('nd', array('nid'))
        ->condition('nd.type', 'book')
        ->execute()
        ->fetchAllAssoc('nid', PDO::FETCH_ASSOC);

      // compare source node with destination after import.
      // https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_array_diff_assoc_recursive/7.x
      $diff = drupal_array_diff_assoc_recursive($destNode, $sourceNodes);
      foreach ($diff as $deletedNode=>$value) {
//        drupal_set_message(t('Node ID @nodeId has been deleted from the source database. ', ['@nodeId' => $deletedNode]), 'status');
      }
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

    protected function query() {
      $query = parent::query();

      // book pdf file
      $pdf_query = Database::getConnection('default', $this->sourceConnection)
        ->select('file_managed', 'f')
        ->fields('f');
      $pdf_query->innerJoin('field_data_field_pdf', 'fdp', 'f.fid = fdp.field_pdf_fid');
      $pdf_query->innerJoin('book', 'b', 'fdp.entity_id = b.nid');

      return $pdf_query;
    }

    public function prepareRow($row) {
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }

    }
  }
