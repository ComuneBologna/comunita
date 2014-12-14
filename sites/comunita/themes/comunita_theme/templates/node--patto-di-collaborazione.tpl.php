<article<?php print $attributes; ?> class="news-item">
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <?php if($page): ?>
  <div class="row">
    <div class="col-sm-12">
      <div class="panel">
        <div class="panel-heading">
          <h1><?php print $title ; ?></h1>
        </div>
        <div class="panel-body">
          <?php
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_consultazione']);
            print render($content);
          ?>
        </div>
      </div>
    </div>
  </div>
  <?php else: ?>
  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
    <a class="scopri scopri-destra" href="<?php print $node_url ?>" title="Scopri di più"><?php print t('Scopri di più »') ?></a>
  </div>
  <?php endif; ?>
</article>