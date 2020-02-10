<?php
/**
 * @file
 * Contains \MigrateDestinationBookOutline.
 */

/**
 * Destination class implementing migration into books.
 */
class MigrateDestinationBookOutline extends MigrateDestinationMenuLinks {
  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return t("Book outlines");
  }

  /**
   * {@inheritdoc}
   */
  public function fields($migration = NULL) {
    $fields = parent::fields($migration) + array(
      'nid' => t("The node ID of the book page."),
      'book_id' => t("The node ID of the root book page."),
    );

    $fields['plid'] = t("The parent link ID (plid) is the mlid of the parent page in the book hierarchy, or zero if the link is for a root book page.");

    // These field values are set by the Book module.
    unset($fields['menu_name']);
    unset($fields['module']);

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function prepare($menu_link, stdClass $row) {
    parent::prepare($menu_link, $row);

    // Set the fixed fields to the appropriate values.
    $menu_link->menu_name = book_menu_name($menu_link->book_id);
    $menu_link->module = 'book';

    // Store any fields that aren't part of a normal menu_link, because the link
    // passed to ::complete() is freshly loaded.
    $this->currentBookId = $menu_link->book_id;
    $this->currentNid = $menu_link->nid;
  }

  /**
   * {@inheritdoc}
   */
  public function complete($menu_link, stdClass $row) {
    global $user;

    parent::complete($menu_link, $row);

    // Update the book table.
    db_merge('book')
      ->key(array('mlid' => $menu_link->mlid))
      ->fields(array(
        'nid' => $this->currentNid,
        'bid' => $this->currentBookId,
      ))
      ->execute();

    // Load and save the book node with $node->book correctly populated in case
    // custom node/entity hooks depend on the book hierarchy in some way.
    $node = node_load($this->currentNid, NULL, TRUE);

    // The book module ensures a revision is saved unless the current user has
    // the 'administer nodes' permission. Impersonate user 1 to prevent it.
    $original_session_state = drupal_save_session();
    drupal_save_session(FALSE);
    $original_user = $user;
    $user = user_load(1);

    node_save($node);

    // Restore the user.
    $user = $original_user;
    drupal_save_session($original_session_state);
  }

  /**
   * {@inheritdoc}
   */
  public function rollback($id) {
    parent::rollback($id);
    db_delete('book')
      ->condition('mlid', reset($id))
      ->execute();
  }

  /**
   * The book ID of the menu link currently being imported.
   */
  private $currentBookId;

  /**
   * The NID of the menu link currently being imported.
   */
  private $currentNid;

}
