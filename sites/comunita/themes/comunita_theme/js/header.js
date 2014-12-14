(function($) {
  $(function() {
    // logo change refresh
    var logo_ebologna = $('.logo-ebologna img');
    var random = Math.floor((Math.random() * 8) + 1);
    logo_ebologna.attr('src', logo_ebologna.attr('src').replace('1.png', '' + random + '.png'));
    
    var user_tooltips = $('.user-buttons .login a').qtip({
      content: $('#user-tooltip') ,
      hide: {
        fixed: true,
        delay: 300
      },
      style: {
        classes: 'qtip-light'
      },
      position: {
        viewport: $(window),
        adjust: {
            method: 'flipinvert'
        },
        my: 'top center',
        at: 'bottom center',
        target: $('.user-buttons .login a')
      }
    });
    
    var feedback_tooltips = $('.feedback a').qtip({
      content: $('#feedback-tooltip') ,
      hide: {
        fixed: true,
        delay: 300
      },
      style: {
        classes: 'qtip-dark'
      },
      position: {
        viewport: $(window),
        adjust: {
            method: 'flipinvert'
        },
        my: 'top center',
        at: 'bottom center',
        target: $('.feedback a')
      }
    });
    
    var api_user_tooltip = user_tooltips.qtip('api');
    var api_feedback_tooltip = user_tooltips.qtip('api');
    
    $('.user-buttons .picture').mouseover(function() {
      if(($(window)).width() < 767) {
        api_user_tooltip.set('position.target', $('.user-buttons .picture'));
      }
      else {
        api_user_tooltip.set('position.target', $('.user-buttons .login a'));
      }
      api_feedback_tooltip.hide();
      api_user_tooltip.show();
    });
    
    $('.feedback').mouseover(function() {
      api_user_tooltip.hide();
    });
  });
})(jQuery);