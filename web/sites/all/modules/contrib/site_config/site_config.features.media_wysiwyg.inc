<?php

/**
 * @file
 * site_config.features.media_wysiwyg.inc
 */

/**
 * Implements hook_media_wysiwyg_defaults().
 */
function site_config_media_wysiwyg_defaults() {
  $media_wysiwyg = array();

  // WYSIWYG view mode for image files.
  $media_wysiwyg['image_wysiwyg_view_mode'] = 'none';

  // Restricted view modes for image files.
  $media_wysiwyg['image_teaser_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_preview_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_wysiwyg_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_default_restrict_wysiwyg'] = FALSE;

  // WYSIWYG view mode for video files.
  $media_wysiwyg['video_wysiwyg_view_mode'] = 'none';

  // Restricted view modes for video files.
  $media_wysiwyg['video_teaser_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['video_preview_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['video_wysiwyg_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['video_default_restrict_wysiwyg'] = FALSE;

  // WYSIWYG view mode for audio files.
  $media_wysiwyg['audio_wysiwyg_view_mode'] = 'none';

  // Restricted view modes for audio files.
  $media_wysiwyg['audio_teaser_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['audio_preview_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['audio_wysiwyg_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['audio_default_restrict_wysiwyg'] = FALSE;

  // WYSIWYG view mode for document files.
  $media_wysiwyg['document_wysiwyg_view_mode'] = 'none';

  // Restricted view modes for document files.
  $media_wysiwyg['document_teaser_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['document_preview_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['document_wysiwyg_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['document_default_restrict_wysiwyg'] = FALSE;

  return $media_wysiwyg;
}
