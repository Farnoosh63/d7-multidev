<?php

/**
 * @file
 * site_config..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function site_config_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_q_a';
  $multifield->label = 'field_q_a';
  $multifield->description = '';
  $export['field_q_a'] = $multifield;

  return $export;
}
