<?php

/**
 * @file
 * site_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function site_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_book';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'seven';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_cache';
  $strongarm->value = 1;
  $export['block_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_allowed_types';
  $strongarm->value = array(
    0 => 'book',
  );
  $export['book_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_child_type';
  $strongarm->value = 'book';
  $export['book_child_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache';
  $strongarm->value = 1;
  $export['cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_lifetime';
  $strongarm->value = '0';
  $export['cache_lifetime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = '1';
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_book';
  $strongarm->value = 0;
  $export['comment_anonymous_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_book';
  $strongarm->value = '1';
  $export['comment_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_book';
  $strongarm->value = 0;
  $export['comment_default_mode_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_book';
  $strongarm->value = '50';
  $export['comment_default_per_page_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_book';
  $strongarm->value = 0;
  $export['comment_form_location_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_page';
  $strongarm->value = 0;
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_book';
  $strongarm->value = '0';
  $export['comment_preview_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_book';
  $strongarm->value = 0;
  $export['comment_subject_field_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_key';
  $strongarm->value = '-AiyELEJNa7-o7AeSE-okBjiJVfMpy4xKOjypBvfuHA';
  $export['cron_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_last';
  $strongarm->value = 1580762245;
  $export['cron_last'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'css_js_query_string';
  $strongarm->value = 'q552gh';
  $export['css_js_query_string'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctools_last_cron';
  $strongarm->value = 1580736819;
  $export['ctools_last_cron'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'America/New_York';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_css_cache_files';
  $strongarm->value = array(
    '823ba1006db72809515d2221cd02ec1075d7b49b0c07f49307b3a7930bfdd9e4' => 'public://css/css_xE-rWrJf-fncB6ztZfd2huxqgxu4WO-qwma6Xer30m4.css',
    '592db66916e1dd3416cbe95bcb34a5a68775eb0b7cf95e4c858671de35290cc9' => 'public://css/css_LS9OUalDR9-d_lCAvF3yUWjNU6yF8ZBm84jEPRvoyuQ.css',
    'd557018b7529ac8387ca29e38399372818412c7ebd645b16a17026ee6a2c64d8' => 'public://css/css_sSHomZZj2ymWDeIagshQaJnvTPkbnSfeFZh4n-CEtJA.css',
    '08e73ee5bdc709cedbe8f3d38be9de6e3b4909f6159bd6bd206af8afa7c5deb2' => 'public://css/css_Iour8uW8KH00bYszt1ZD1fhcGNAmZhSxncZW5dg-dno.css',
    'ebb3f433ad4107b1ac31e9d7de0f9a5d399040e9f82b6364211dcfaadea158c0' => 'public://css/css_Nv0ct-zkzztuah_LbaPFF8ZkdSEk-LxBtTWMm9mN_F8.css',
    'cb9f93e666a396bb3eb14c5fd16f7ebd1cdd0067733eb0a2ab1b294b6f14f76f' => 'public://css/css_1kF33EODTO5gDyEbdpAfYzMKbjG3ottD1s5np0BNI8U.css',
    '568f3bca87830de88c7b44e71808ac7f33f4cdf273ed3bf3d2532bd48f084b06' => 'public://css/css_NRg0AX3iY_x0OX3_WzcWp90JnwurHRvZn6i75GL0rRI.css',
    '586e4d641f74d0fbdea2ecffe62294e983c5961df8d0128aab1c561505f6b35a' => 'public://css/css_2THG1eGiBIizsWFeexsNe1iDifJ00QRS9uSd03rY9co.css',
    '12f3610d3716d361ab968674679f876fa993dfd07d2f1f6d0cc76efc47382671' => 'public://css/css_JoYP3SyEFWEMl4HgoN3y8m7tsdG7OJhA4tzrebCC8bs.css',
    '20f8eaf5847d9a8a6df28ecc9bcf2cd47f2354023590585b97ca5c054ae0e0a5' => 'public://css/css_jENQOQqZCRFGZK__DTefxYiXR2RUf03k1ugj3_Vg7vk.css',
    '032d72e2b3124645b11e59c23005327dc2b450af6aaa6bf3cad34a6a65a9d774' => 'public://css/css_ZDWl28hdmeinIcKg-HMrN6uKD0nTMld5NlXLmm5MH2U.css',
    '97d3c9c56ae9b87cecd7d80ef932ecbb083af5eee00974fd49d932f7be95952f' => 'public://css/css_LjqfbWqfWvT33GNiW8FdUKtJTKnuqY6tVbaOICQaMAE.css',
    'c3cafd99e7ab018c258f76c386df24ac60b6855b8d91e3b62ae0aea30f3c1557' => 'public://css/css__o6fFpRFoHAw1J7qEiSq6eqcSTuf6f12i5aZDZMjVO8.css',
    '3a6d20215cb5d942a488dc7ba51fe1f7f102538fe34094687b14f55816964776' => 'public://css/css_q5vNrGP5bjEG4gRWIyc04BS_OBfIJBQvxtmgvur23XU.css',
    '32b88b424908b5a7a44f8f1d2d86dba0e40dbc48abac821a71b4ae93557cb9aa' => 'public://css/css_-7C9TvFsQnHdAPV4PX2kn_f9UWUIx7VrGbvHZAZkmjY.css',
    '1c36101f305446b1b88af3ae50209ee3c713f1f7ffbbb30629a37d65198330fa' => 'public://css/css_1FuaQyNpeoGilFLg6GsDTprte9QHfko-0ntzSWCraiQ.css',
    'f05494fc83c9c8e2c74180252d01c9ea50f347143d606c3ea4a216ea0f24ce6e' => 'public://css/css_BR3eb_ceEn8jEAv9rAj8_gjpfC6A1BpCm8JGn5sUfnY.css',
  );
  $export['drupal_css_cache_files'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_http_request_fails';
  $strongarm->value = FALSE;
  $export['drupal_http_request_fails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_js_cache_files';
  $strongarm->value = array(
    '8a083345a4311ad41ef0859b0ba91c2ad46b6388c07807b9de1d44cf543eb0f5' => 'public://js/js_qikmINIYTWe4jcTUn8cKiMr8bmSDiZB9LQqvceZ6wlM.js',
    '9c7ad3b64966f68be435d73dfefb1ad341e46e22696cb373731d43092add0994' => 'public://js/js_I23gxiikXxx_6GGz6rJ54UoPf8kO1zLBQwc8jUznXYM.js',
    '894d50601a5da8e76dd47df54662af06bc3635d48ac2d1710d3105abc9dd4700' => 'public://js/js_GP0zr57CpbbK1FdGVy7Q7EzG3yP2XjqVSPgIMtKWWYo.js',
    '179ba294430e111268012b975fde1e5f7d550c16989fb1b88ad1e9bbf7548546' => 'public://js/js_y0ljG2A7zV1Tbk8rBM1ZjX499DZ-Q73zKvXtbsVHKJ0.js',
    '2534e83b47c8bc64737d4d69a2b7f149ee08935f617385b29e78f1964836bcdf' => 'public://js/js_COyqYVT1zUmjsesp9MbmQtgtm_qe6OE1e5-Wwbmfyr4.js',
    '4ae9a95afa43ece34b1efb2f7cad7f62e2eb64479f41ef7d66bc6e7147a8966a' => 'public://js/js_vNfk0E4QpZNmnRYJCe6E7LXYcNSNtAJmZCBP8gL0YD0.js',
    '2dde6c57c7d091a4eea7ad6743b68bb336186b2d9c63ec8593f26f7c58e64c93' => 'public://js/js_RNlLRuWMrcShIEKcvvhXRiK_XWPEbGPRbwhDRMAMZ7c.js',
    '8e82ae002cb0ffa3b8820d2e1e5256bc0dafc794d1115af549532cbf27b242fd' => 'public://js/js_RC8VLBvCRozlfVvMPHB-iaDGheH3ZCumCJ681wGSUk8.js',
    'fea611fca94430d97bbcc5ad2e8a00ac9d7d45439c0f199280f2bc3e8ec96202' => 'public://js/js_RNUmkGN1a0Y2T8PmNSQw0d-knmWrraAO6OW2rQVN35E.js',
    '1d182bd5de948ce2c103c01b6723883e30b0feaa3b920323aefb01a453a549f0' => 'public://js/js_AOhusWNcX1fBMcXWZtJpi9kLqnB60aInhTjzPWLy4j4.js',
    '1a30c351624a627553d78983ad986922fa2576d2391858497e3ca6bb022b6015' => 'public://js/js_CC-zfeuQHcDhFtVRuKW53h30TL7j_105J32Nz8b8R38.js',
    'a4c3435bd6ae26ddc2fb8e7afa0711e2f80db2bc207f356e499ee22503aa5348' => 'public://js/js_12QpE_gf_9NFgD2NVcnlIYAmLvXFzNHU7OqzKOF5bRc.js',
    'd07fd92dfd6e9aacbf8d021130555c7be1bb62b4040a7310f0160787ba82a49b' => 'public://js/js_bhN16gx7RrRq4l_DxKgNqgsH7yxPlWfKeFXAUH55oiw.js',
    'e871606b30e517a450e19e3a5daa808342365362505d59aed701bf50f12bcdd5' => 'public://js/js_HC7Meqy7dKrfSOHxQqF4GQCqfiJhlF4Mc8sm18KuNA4.js',
    '2c65a1aff885b6ad26ea446e43cf39fd203cf7732ca2c78b8ab8acbd8d3bdeee' => 'public://js/js_JaKjPL2DDhZ43Y3WoeHIwRMM4-2KmEx2K77Ns9nJnmo.js',
    'cc574f4d8de9f4756fe08f6a18fb7be1ba942c6a1280b81487486c56a640155a' => 'public://js/js_9mGe_UUQfgprH1sWTLe6-VQksZw9RAz7sSiCzRQvEGk.js',
    '0a2e4eba9d3d9723f5a525e3affb027e043b54845b604811efa7448854434ac6' => 'public://js/js_fWk1KwA3EbQ6PPZno90DbjBTlwu5Q1pyIb4rcOg1aVg.js',
    'ddd373230c49a05cbd43e1c05a0e62dcb4bc3782a5b6b4cbee18285b0ddd9bff' => 'public://js/js_lU_9A17xlyritPhTj0IwZ1WgL1ZAjl5sXQ8Rewzopw8.js',
    '816ac0e8664fd2e96a9f6ab256b6bac016a1f7f772417b78aee8a3c7358399b0' => 'public://js/js_7QN3_DJPYDtCYeVPGw0l8F_-R1dKdEhRJS3fG1h0mO8.js',
    '4e12e46a743b9c9d4cf7315f5036495cb1ab766e2b9869a07aa0a3791b2aeb44' => 'public://js/js_smjc7rCmlgNF72dggVoqRY8sR4e0XqNC6eslEeezoi4.js',
  );
  $export['drupal_js_cache_files'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupal_private_key';
  $strongarm->value = 'nx94wLld6l_NW2IQdQOEqwuGxGSkHUSC8KDoQ74jd4Y';
  $export['drupal_private_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entityreference:base-tables';
  $strongarm->value = array(
    'comment' => array(
      0 => 'comment',
      1 => 'cid',
    ),
    'multifield' => array(
      0 => 'multifield',
      1 => 'id',
    ),
    'node' => array(
      0 => 'node',
      1 => 'nid',
    ),
    'file' => array(
      0 => 'file_managed',
      1 => 'fid',
    ),
    'taxonomy_term' => array(
      0 => 'taxonomy_term_data',
      1 => 'tid',
    ),
    'taxonomy_vocabulary' => array(
      0 => 'taxonomy_vocabulary',
      1 => 'vid',
    ),
    'user' => array(
      0 => 'users',
      1 => 'uid',
    ),
  );
  $export['entityreference:base-tables'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_codecache';
  $strongarm->value = array(
    'site_config' => array(
      'dependencies' => '01d81c813233332f192e5548ee60a017',
      'field_base' => 'bfce6f4426059e46dd863ee83e3ab969',
      'field_instance' => 'f53880af306cbc4f2f7377a289a74ecd',
      'taxonomy' => '4b7be89caddbae459e1887f68aa0bd10',
      'user_role' => '57d23ee3deb6e9262fa3b2617586b072',
      'variable' => '77bbf32b83808f9e28914fe193121fc2',
      'node' => '72fbc1d40e03ea5819150212c7645a42',
      'filter' => '4804cf8fe90be8778a568775abc85d57',
      'hierarchical_select' => 'c2f243c54938beed594b37b60e543b85',
    ),
  );
  $export['features_codecache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_ignored_orphans';
  $strongarm->value = array();
  $export['features_ignored_orphans'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_modules_changed';
  $strongarm->value = FALSE;
  $export['features_modules_changed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_semaphore';
  $strongarm->value = array();
  $export['features_semaphore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__book';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-field_topics';
  $strongarm->value = array(
    'config_id' => 'taxonomy-field_topics',
    'save_lineage' => '1',
    'enforce_deepest' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 1,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
      'sort' => 1,
    ),
    'editability' => array(
      'status' => 0,
      'item_types' => array(
        0 => '',
        1 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
        1 => 1,
      ),
      'allow_new_levels' => 0,
      'max_levels' => '1',
    ),
    'entity_count' => array(
      'enabled' => 0,
      'require_entity' => 0,
      'settings' => array(
        'count_children' => 0,
        'entity_types' => array(
          'node' => array(
            'count_node' => array(
              'article' => 0,
              'page' => 0,
              'book' => 0,
            ),
          ),
        ),
      ),
    ),
  );
  $export['hs_config_taxonomy-field_topics'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'install_profile';
  $strongarm->value = 'pantheon';
  $export['install_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_book';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_book';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'multifield_max_id';
  $strongarm->value = '2';
  $export['multifield_max_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = 1;
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_book';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_book';
  $strongarm->value = '1';
  $export['node_preview_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_book';
  $strongarm->value = 1;
  $export['node_submitted_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = FALSE;
  $export['node_submitted_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_cache_maximum_age';
  $strongarm->value = '900';
  $export['page_cache_maximum_age'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 0;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_blog_pattern';
  $strongarm->value = 'blogs/[user:name]';
  $export['pathauto_blog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'content/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hyphen';
  $strongarm->value = 1;
  $export['pathauto_punctuation_hyphen'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = 'users/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'path_alias_whitelist';
  $strongarm->value = array(
    'node' => TRUE,
  );
  $export['path_alias_whitelist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_css';
  $strongarm->value = 1;
  $export['preprocess_css'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'preprocess_js';
  $strongarm->value = 1;
  $export['preprocess_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'node';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'fjohnson@urban.org';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'D7-ci-multidev';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = 'multidev 5';
  $export['site_slogan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_override_selector';
  $strongarm->value = TRUE;
  $export['taxonomy_override_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'bartik';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_last_check';
  $strongarm->value = 1580762257;
  $export['update_last_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '3';
  $export['user_admin_role'] = $strongarm;

  return $export;
}
