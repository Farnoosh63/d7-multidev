; Specify the version of Drupal being used.
core = 7.x
; Specify the api version of Drush Make.
api = 2

; Contrib patches.

;multifield
;Migrate field handler
projects[multifield][patch][] = "https://www.drupal.org/files/issues/multifield-migrate_field_handler-2217353-50.patch"