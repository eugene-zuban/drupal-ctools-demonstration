<?php

/**
 * @file
 * "Adyax test widget" simply show 3 random published nodes in 'teaser' view mode.
 *
 */

/**
 * Describe plugin
 */
$plugin = array(
  'title' => t('Adyax test. Show 3 random nodes'),
  'description' => t("This plugin shows 3 random nodes in 'teaser' view mode."),
  'single' => TRUE,
  'render callback' => 'adyax_test_content_type_render',
  'defaults' => array(),
  'category' => array(t('Adyax Test'), -9),
);

/**
 * Rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 *  in this case we don't use any
 *
 * @return
 *   An object with title and content members.
 */
function adyax_test_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '';

  $nids = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('status', 1)
    ->orderRandom()
    ->range(0, 3)
    ->execute();

  foreach ($nids as $item) {
    $node = node_load($item->nid);
    $block->content .= drupal_render(node_view($node, 'teaser'));
  }

  if (empty($block->content)) {
    $block->content = t("There are no nodes for this pane");
  }

  $block->title = check_plain("3 random nodes in a teaser view mode");

  return $block;
}

