#!/usr/bin/env bash

# Please see https://pantheon.io/blog/running-drupal-8-data-migrations-pantheon-through-drush

# set variables
export SITE_ENV="d7-ci-multidev.live"
export PANTHEON_D7_SITE="d7-ci-multidev"
export D7_MYSQL_URL=$(terminus connection:info $PANTHEON_D7_SITE.live --field=mysql_url)

# wake up database
terminus env:wake $SITE_ENV

# set secrets.json file on pantheon environment files/private directory mentioned on settings.migrate-on-pantheon.php file
terminus secrets:set $SITE_ENV migrate_source_db__url $D7_MYSQL_URL --clear

# show secrets.json file
terminus secrets:show $SITE_ENV migrate_source_db__url

# copy secrets.json file into desktop private directory
# copy the file into sites/default/files/private directory in your destination
terminus rsync d7-ci-multidev.live:files/private .

# delete secrets.json file from pantheon environment
terminus secrets:delete $SITE_ENV migrate_source_db__url


lando drush --filter=migrate

# register our migration
lando drush mreg BriefingBookNodes # comes from book_migration.migration.inc
lando drush mreg BriefingBookFiles
lando drush mreg BookMigrateOutline

lando drush ms

# First migrate Files module
# This may take some time
lando drush mi BriefingBookFiles

lando drush mi BriefingBookNodes

# run after all the book nodes have been imported.
lando drush mi BookMigrateOutline


# roll back migration
lando drush mr BriefingBookNodes
lando drush mr BriefingBookFiles
lando drush mr BookMigrateOutline

# deregister the migration
lando drush mdreg BriefingBookNodes
lando drush migrate-deregister --group="book_migration"


# Common errors:
#Migration for <em class="placeholder">TitleBookMigration</em> failed with source plugin exception: <em class="placeholder">SQLSTATE[42S02]: Base table or view not found: 1146 Table &#039;pantheon.migrate_map_briefingbooknodes&#039; doesn&#039;t [error]
#exist</em>, in <em class="placeholder">/app/web/includes/database/database.inc</em>:<em class="placeholder">2227</em>
https://www.drupal.org/node/1152150#map_joinable
https://drupal.stackexchange.com/a/165017


# Registering a new migration
#After adding new migrations, or making changes to the arguments of previously-registered migrations, if you want them to be recognized by Migrate, you need to:
#Clear the Drupal cache, so any new classes are added to the Drupal cache registry.
#Perform the registration, either with drush migrate-register or by visiting admin/content/migrate/configure and clicking the "Register statically-defined classes" button.
https://www.drupal.org/node/1824884



#I applied this patch to d2d_migration
https://www.drupal.org/project/migrate_d2d/issues/2637350


#if Invalid argument supplied for foreach() menu_links.inc:37
#Add
if (is_array($this->node_migrations)) {

}
#around foreach on menu_links.inc file



Modules requirements:
1- Drupal-to-Drupal data migration dev version
2- Mulrifield dev version


These errors:
#Class DrupalBookLinksMigration could not be found
#Migration BriefingBookFiles could not be constructed.
#SQLSTATE[HY000] [2002] Connection refused
#Migration BriefingBookNodes could not be constructed.
#SQLSTATE[HY000] [2002] Connection refused
#No migration with machine name BriefingBookNodes found

#run below to wake up the database connection
terminus env:wake $SITE_ENV
