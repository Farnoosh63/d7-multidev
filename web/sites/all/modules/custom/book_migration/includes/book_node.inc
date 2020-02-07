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
      $this->addFieldMapping('field_pdf:description', 'field_pdf:description')
        ->defaultValue('');

      // Field Q&A TODO: field mapping wont import to destination
      $this->addFieldMapping('field_q_a:field_question_value', 'field_q_a:field_question_value');
      $this->addFieldMapping('field_q_a', 'field_q_a');
      $this->addFieldMapping('field_q_a:id', 'field_q_a:id');


      // Book hierarchiy
//      $this->addFieldMapping('link_path', 'link_path');
//      $this->addFieldMapping('weight', 'weight');


    }

      /**
       * Overrides parent::query to add more data to the source, in our case,
       * book hierarchy stuff.
       */
      public function query() {
        $query = parent::query();
        // Add in book parent child relationships.
        $query->leftJoin('book', 'b', 'n.nid = b.nid');
        $query->addField('b', 'bid');
        $query->addField('b', 'mlid');
        $query->leftJoin('menu_links', 'ml', 'b.mlid = ml.mlid');
        $query->condition('module', 'book');
        $query->addField('ml', 'weight');
        $query->addField('ml', 'plid');
        $query->addField('ml', 'link_path');
        $query->addField('ml', 'depth');
        $query->addField('ml', 'p1');
        $query->addField('ml', 'p2');
        $query->addField('ml', 'p3');
        $query->addField('ml', 'p4');
        $query->addField('ml', 'has_children');
        $query->addField('ml', 'module');
        $query->addField('ml', 'menu_name');
        // Sort by depth so there is always a parent
        $query->orderBy('ml.depth');

        return $query;
      }


      /**
       * Acts right after a book node has been saved. Map the book hierarchy.
       *
       * @param object $node
       *   A node object for the newly migrated book.
       * @param stdClass $row
       *   An object representing data from the source row.
       */
      public function complete($entity, stdClass $row) {

//        $node = node_load($entity->nid);
        // We cannot set the nid from $row to nid to $row
        // since the nid in source is different than destination.
        // The book id is the parent id.
        // If this is a top-level book, don't set a parent.
        $bid = $row->nid == $row->bid ? $entity->nid : $this->lookupMigratedBook($row->bid);
        $entity->book['bid'] = $bid;
        $entity->book['weight'] = $row->weight;
        $entity->book['depth'] = $row->depth;
        $entity->book['has_children'] = $row->has_children;

        _book_update_outline($entity);

        node_save($entity);

      }

      /**
       * Returns a mapping for a migrated book.
       *
       * @param int $source_book_nid
       *   Nid of book in source database to lookup.
       */
      protected function lookupMigratedBook($source_book_nid) {
        $dest_book_nid = parent::handleSourceMigration('BriefingBookNodes', $source_book_nid);
        return $dest_book_nid;
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

    }

    public function prepare($entity, stdClass $row) {

      $entity->menu['depth'] = $row->depth;
      $entity->book['depth'] = $row->depth;

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

