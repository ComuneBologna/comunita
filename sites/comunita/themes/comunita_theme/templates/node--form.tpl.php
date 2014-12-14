<?php global $user; ?>
<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <div<?php print $content_attributes; ?>>
    <?php
      //print render($content);
    ?>
    form eng
    <span id="template" type="hidden" value="<?php print $field_id_form[0]['safe_value']; ?>"></span>
    
    <div id="modulisticaOnlineMainContent" class="form-eng"></div>
  </div>
  
</article>