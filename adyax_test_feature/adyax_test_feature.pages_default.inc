<?php
/**
 * @file
 * adyax_test_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function adyax_test_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test_page';
  $page->task = 'page';
  $page->admin_title = 'Test page';
  $page->admin_description = 'This page demonstrate ADYAX Test task result';
  $page->path = 'test2';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'test_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'ADYAX Test result page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'border_width' => '2px',
      ),
    ),
    'middle' => array(
      'style' => 'adyax_test_style',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '11987ffc-d6a9-42f6-a9f9-5aebf8cd3933';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-776a30db-0ae2-4407-b9c2-8179ad42de0e';
    $pane->panel = 'middle';
    $pane->type = 'adyax_test_widget';
    $pane->subtype = 'adyax_test_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'style' => 'adyax_test_style',
      'settings' => array(
        'border_width' => '2px',
      ),
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '776a30db-0ae2-4407-b9c2-8179ad42de0e';
    $display->content['new-776a30db-0ae2-4407-b9c2-8179ad42de0e'] = $pane;
    $display->panels['middle'][0] = 'new-776a30db-0ae2-4407-b9c2-8179ad42de0e';
    $pane = new stdClass();
    $pane->pid = 'new-9e4430c7-8c1b-40cf-b188-759abea70dba';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Pane with text',
      'title' => '',
      'body' => 'This is test pane for showing how was applied region\'s style',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9e4430c7-8c1b-40cf-b188-759abea70dba';
    $display->content['new-9e4430c7-8c1b-40cf-b188-759abea70dba'] = $pane;
    $display->panels['middle'][1] = 'new-9e4430c7-8c1b-40cf-b188-759abea70dba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test_page'] = $page;

  return $pages;

}
