<?php


/**
 * Page callback for mlid/%menu_link/under-construction
 * 
 * @param array $item
 *   The menu link, as returned by menu_link_load()
 * @return string
 *   Rendered HTML
 *   TODO: We could instead return a renderable array.
 */
function menu_editor_placeholder_page($item) {
  drupal_set_title(t('!link_title - Under Construction', array(
    '!link_title' => $item['link_title'],
  )));
  $html = '';
  foreach (node_type_get_types() as $type_name => $type_info) {
    if (me_node_creation_create_node_access($type_info)) {
      $link_html = l($type_info->name, "node/add/$type_name/mlid/$item[mlid]");
      $html .= "<li>$link_html</li>";
    }
  }
  // TODO: Provide themeable output, or find another solution.
  $txt = t('We are working on it.');
  if ($html) {
    $txt_admin = t("Replace this placeholder link with real content:");
    return <<<EOT
<p>$txt</p>
<p>$txt_admin</p>
<ul>$html</ul>
EOT;
  } else {
    return <<<EOT
<p>$txt</p>
EOT;
  }
}
