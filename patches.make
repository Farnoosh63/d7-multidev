; Specify the version of Drupal being used.
core = 7.x
; Specify the api version of Drush Make.
api = 2

; Contrib patches.

;multifield
;Migrate field handler
; @see https://www.drupal.org/project/multifield/issues/2217353#comment-10796648
projects[multifield][patch][] = "https://www.drupal.org/files/issues/multifield-migrate_field_handler-2217353-50.patch"

;migrate_d2d
;Preserve Book hierarchies
; @see https://www.drupal.org/project/migrate_d2d/issues/2146961#comment-11034435
projects[migrate_d2d][patch][] = "https://www.drupal.org/files/issues/migrate_d2d-book_migration-2146961-4-d7.patch"

;migrate
;destination handler
; @see https://www.drupal.org/project/migrate/issues/763880#comment-11034401
projects[migrate][patch][] = "https://www.drupal.org/files/issues/migrate-book_destination-763880-7-d7.patch"
