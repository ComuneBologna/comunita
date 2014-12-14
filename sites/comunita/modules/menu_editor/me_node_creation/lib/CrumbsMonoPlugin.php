<?php


class me_node_creation_CrumbsMonoPlugin implements crumbs_MonoPlugin {

  function describe($api) {
    $api->setTitle('Set breadcrumbs for placeholder pages.');
  }

  function findParent($path, $item) {
    switch ($item['route']) {
      case 'node/add/%/mlid/%':
        $mlid = $item['fragments'][4];
        return "mlid/$mlid/under-construction";
      case 'mlid/%/under-construction':
        // Let the menu.hierarchy.* plugin do its thing
        break;
    }
  }
}
