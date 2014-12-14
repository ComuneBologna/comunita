<div class="progetto elenco-item"<?php print $attributes; ?>>
  <?php print render($content['field_immagine_progetto']) ?>
  <a class="title" href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a>
  <?php if(isset($content['og_group_ref'])): ?>
  <div class="group"><span class="from"><?php print t("Da"); ?></span><?php print render($content['og_group_ref']); ?></div>
  <?php endif; ?>
  <?php if($node->field_stato_documento[LANGUAGE_NONE][0]['value'] == 0): ?>
  <div class="bozza-alert">BOZZA</div>
  <?php endif; ?>
</div>