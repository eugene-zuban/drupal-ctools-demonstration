<?php

/**
 * @file
 * "Adyax test style" is regions and panes style CTools plugin
 *
 */

/**
 * Describe plugin
 */
$plugin = array(
  'title' => t('Content in a border'),
  'description' => t('Set border width'),
  'render region' => 'adyax_test_style_render_region',
  'render pane' => 'adyax_test_style_render_pane',
  'settings form' => 'adyax_test_style_settings_form',
  'pane settings form' => 'adyax_test_style_settings_form',
);

/**
 * Theme a pane
 */
function theme_adyax_test_style_render_pane($vars) {
  $settings = $vars['settings'];
  $style = isset($settings['border_width']) ? $settings['border_width'] : 'none';

  $output = '<div class="adyax-test-style" style="border: ' . $style . ' solid;">';
  $output .= render($vars['content']->content);
  $output .= '</div>';

  return $output;
}

/**
 * Theme a region
 */
function theme_adyax_test_style_render_region($vars) {
  $content = '';

  foreach ($vars['panes'] as $pane_id => $pane_output) {
    $content .= $pane_output;
  }

  if (empty($content)) {
    return;
  }

  $settings = $vars['settings'];
  $style = isset($settings['border_width']) ? $settings['border_width'] : 'none';

  $output = '<div class="adyax-test-style" style="border: ' . $style . ' solid;">';
  $output .= $content;
  $output .= '</div>';

  return $output;
}

/**
 * Style settings form
 */
function adyax_test_style_settings_form($style_settings) {
  $form['border_width'] = array(
    '#type' => 'select',
    '#title' => t("Border's width"),
    '#options' => array(
      'none' => 'none',
      '1px' => '1px',
      '2px' => '2px',
      '3px' => '3px',
      '4px' => '4px',
    ),
    '#default_value' => (isset($style_settings['border_width'])) ? $style_settings['border_width'] : 'none',
  );

  return $form;
}
