<?php $this_user = user_load($user_profile['field_nome']['#object']->uid); ?>
<div class="profile elenco-item"<?php print $attributes; ?>>
  <?php print render($user_profile['user_picture']) ?>
  <?php print theme('username', array('account' => $this_user)); ?>
</div>
