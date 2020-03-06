# TPC Book Migration Module

Install this module into TPC project and run migration to update new sets of briefing books.
This module migrates the Book nodes from pantheon database as source to your destination database.

### Local Prerequisites
Install [terminus](https://pantheon.io/docs/terminus/install) along with two plugins:

1- [Terminus Rsync Plugin](https://github.com/pantheon-systems/terminus-rsync-plugin)

2- [Terminus Secrets Plugin](https://github.com/pantheon-systems/terminus-secrets-plugin)

### Contrib Modules Requirements
There are two modules listed as dependencies:

1- [Migrate](https://www.drupal.org/project/migrate)

2- [Drupal-to-Drupal data migration](https://www.drupal.org/project/migrate_d2d)

These modules require dev version installation:

1- [Drupal-to-Drupal data migration](https://www.drupal.org/project/migrate_d2d/releases/7.x-2.x-dev)

2- [Multifield](https://www.drupal.org/project/multifield/releases/7.x-1.x-dev)

### Connecting to pantheon database
1- To setup connection with source database, we use settings.migrate-on-pantheon.php file. This file parse the database credentials from the secrets.json file.
For further reading, please see Defining Your Database Connection on
https://pantheon.io/blog/running-drupal-8-data-migrations-pantheon-through-drush
If you are using your local as destination, you can add a condition like below:
```
if ($_ENV['PANTHEON_ENVIRONMENT'] == 'lando') {
  $secretsFile = '/app/web/sites/default/files/private/secrets.json';
}
```
In the above scenario I am running TPC project on [lando dev tool](https://docs.lando.dev/basics/).

2- We need to set source variables for currect shell by

`export SITE_ENV="MY_PANTHEON_D7_SITE.dev"`

`export PANTHEON_D7_SITE="MY_PANTHEON_D7_SITE"`

`export D7_MYSQL_URL=$(terminus connection:info $PANTHEON_D7_SITE.dev --field=mysql_url)`

3- You must change the __MY_PANTHEON_D7_SITE__ and __pantheon environment__ for your needs.
After setting up shell variables, we need to access mysql database on pantheon by spin up database server.

`terminus env:wake $SITE_ENV`

4- Set secters.json file using Terminus secrets plugin

`terminus secrets:set $SITE_ENV migrate_source_db__url $D7_MYSQL_URL --clear`

`cd app/we/sites/default/files/`

copy the file into sites/default/files/private directory in your destination

`terminus rsync MY_PANTHEON_D7_SITE.dev:files/private .`

##### optional Usage:
To remove the exising secret key from source environment:

`terminus secrets:delete $SITE_ENV migrate_source_db__url`

To show the current value of secret key from MY_PANTHEON_D7_SITE.dev environment:

`terminus secrets:show $SITE_ENV migrate_source_db__url`


### Running the migration

To list all the migrate tools commands, run

`lando drush --filter=migrate`

1- In this module we have three migrations. Register or re-register each migration :

`lando drush mreg BriefingBookNodes`

`lando drush mreg BriefingBookFiles`

`lando drush mreg BookMigrateOutline`

2- We need to migrate __BriefingBookFiles__ first and __BookMigrateOutline__ last.
Migrating files, this may takes some time:

`lando drush mi BriefingBookFiles --update --feedback="100 items"`

Migrating Book nodes:

`lando drush mi BriefingBookNodes --update --feedback="50 items"`

Migration Book Hierarchy (run after all the book nodes have been imported):

`lando drush mi BookMigrateOutline --update --feedback="50 items"`

* In case of only migrating unimported items from the source or update previpusly-imported items with new data add `--update` flag to the abive commands.

### Troubleshooting
If the migration or a class is not detected, roll back all migrations and de-register and redister back the migrations.
to roll back each migration run:
```
lando drush mr BriefingBookNodes
lando drush mr BriefingBookFiles
lando drush mr BookMigrateOutline
```
To Remove all tracking of the migration
```
lando drush migrate-deregister --group="book_migration"
```
After adding new migrations, or making changes to the arguments of previously-registered migrations, if you want them to be recognized by Migrate, you need to:
Clear the Drupal cache, so any new classes are added to the Drupal cache registry.
Perform the registration, either with drush migrate-register or by visiting admin/content/migrate/configure and clicking the "Register statically-defined classes" button.

Error related to database connection refused can be handled by spinning up the source datanase server:
`terminus env:wake $SITE_ENV`

### Resources

1- [Commonly implemented Migration methods](https://www.drupal.org/node/1132582)

2- [Advanced field mappings](https://www.drupal.org/node/1224042)

3- [How to manage your Drupal patches with drush patch file](https://chromatichq.com/blog/how-manage-your-drupal-patches-drush-patch-file)

4- [Defining Your Database Connection](https://pantheon.io/blog/running-drupal-8-data-migrations-pantheon-through-drush)

5- [Accessing MySQL Databases](https://pantheon.io/docs/mysql-access#troubleshooting-mysql-connections)

6- [Drush Migrate Tools commands](https://www.drupal.org/node/1561820)

7- [Migration and group registration](https://www.drupal.org/node/1824884)
