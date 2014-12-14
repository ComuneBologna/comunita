<article<?php print $attributes; ?> class="news-item">
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php if($content['og_group_ref']): ?>
    <div class="group"><span class="from"><?php print t("Da"); ?></span><?php print render($content['og_group_ref']); ?></div>
    <?php endif; ?>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <?php if($page): ?>
  <div class="row">
    <div class="col-sm-8">
      <div class="panel panel-blog">
        <div class="panel-heading">
          <h1><?php print $title ; ?></h1>
          <?php if(isset($content['og_group_ref'])): ?>
          <span>dal blog di <?php print render($content['og_group_ref']); ?></span>
          <?php endif; ?>
        </div>
        <div class="panel-body">
          <?php
            hide($content['og_group_ref']);
            hide($content['comments']);
            hide($content['links']);
            print render($content['field_image']);
            print '<div class="date">' . format_date($content['body']['#object']->created, 'blog') . '</div>';
            print render($content);
          ?>
        </div>
        <div class="panel-footer">
          <div class="clearfix">
            <?php if (!empty($content['links'])): ?>
              <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
            <?php endif; ?>

            <?php print render($content['comments']); ?>
          </div>
        </div>
      </div>
    </div>
    <div class="col-sm-4">
      <div class="panel panel-blog panel-side">
        <div class="panel-heading">
          <?php if(!empty($og_group_ref)): ?>
          <?php
            print l(theme_image_style(array('style_name' => 'thumbnail', 'path' => $node->og_group_ref[LANGUAGE_NONE][0]['entity']->field_org_picture[LANGUAGE_NONE][0]['uri'], 'width' => null, 'height' => null)), 'node/' . $node->og_group_ref[LANGUAGE_NONE][0]['entity']->nid, array('html' => TRUE));
            print render($content['og_group_ref']);
          ?>
          <?php else: ?>
          <?php
            $author = user_load($node->uid);
            print l(theme_image_style(array('style_name' => 'thumbnail', 'path' => $author->picture->uri, 'width' => null, 'height' => null)), 'users/' . $author->name, array('html' => TRUE));
            print l($author->field_nome[LANGUAGE_NONE][0]['value'] . ' ' . $author->field_cognome[LANGUAGE_NONE][0]['value'], 'users/' . $author->name);
          ?>
          <?php endif; ?>
        </div>
        <div class="panel-body">
          <h2>Post recenti dal blog</h2>
          <?php if(!empty($og_group_ref)): ?>
          <?php print views_embed_view('post_recenti_su_organizzazione', 'block_3', $node->og_group_ref[LANGUAGE_NONE][0]['entity']->nid); ?>
          <?php else: ?>
          <?php print views_embed_view('post_recenti_su_organizzazione', 'block_4', $node->uid); ?>
          <?php endif; ?>
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
  </div>
  <?php endif; ?>
</article>