<article class="<?php print $classes . ' ' . $zebra; ?>"<?php print $attributes; ?>>
  <div class="row">
    <div class="user col-sm-2">
      <?php if(!empty($og_group_ref)): ?>
       <?php
          print l(theme_image_style(array('style_name' => 'thumbnail', 'path' => $comment->og_group_ref[LANGUAGE_NONE][0]['entity']->field_org_picture[LANGUAGE_NONE][0]['uri'], 'width' => null, 'height' => null)), 'node/' . $comment->og_group_ref[LANGUAGE_NONE][0]['entity']->nid, array('html' => TRUE));
        ?> 
      <?php else: ?>
        <?php print $picture; ?>
      <?php endif; ?>
    </div>
    <div class="content col-sm-10">
      <?php if(!empty($og_group_ref)): ?>
      <div class="submitted"><span property="dc:date dc:created" content="" datatype="xsd:dateTime" rel="sioc:has_creator">Inviato da <?php print render($content['og_group_ref']); ?> il <?php print format_date($comment->created, 'medium'); ?></span></div>
      <?php else: ?>
        <div class="submitted"><?php print $submitted; ?></div>
      <?php endif; ?>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['links']);
        hide($content['og_group_ref']);
        print render($content);
      ?>
      <?php print render($content['links']) ?>
    </div>
  </div>
</article> <!-- /.comment -->
