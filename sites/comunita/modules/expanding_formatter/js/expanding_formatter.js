/*global Drupal:true */
(function ($) {

  /**
   * Logic for expanding/collapsing fields that configured with a toggle.
   */
  Drupal.behaviors.expandingFormatter = {
    attach: function (context) {
      var $formatters = $(context).find('.expanding-formatter');
      $formatters.once('expanding-formatter', function () {
        var $formatter = $(this).removeClass('expanded collapsed');
        var $content = $formatter.find('.expanding-formatter-content');
        var $trigger = $formatter.find('.expanding-formatter-trigger a');
        var data = $formatter.data();
        if (!data.effect) {
          data.effect = 'normal';
          $content.hide();
        }
        else {
          // Get normal expanded height.
          data.expandedHeight = $formatter.outerHeight(false);
          $content.hide();
          data.collapsedHeight = $formatter.outerHeight(false);
          $formatter.addClass('collapsed').height(data.collapsedHeight);
          $content.removeAttr('style');
          if (!data.css3) {
            $content.hide();
          }
        }
        data = $.extend({}, data, {
          $formatter: $formatter,
          $content: $content,
          $trigger: $trigger
        });
        $trigger.bind('click', function () {
          data.expanded = $formatter.hasClass('expanded');
          // Non-CSS and CSS effects.
          if (typeof Drupal.expandingFormatterEffects[data.effect] !== 'undefined') {
            // Use CSS3 if applicable.
            if (data.css3 && typeof Drupal.expandingFormatterEffects[data.effect + 'Css'] !== 'undefined') {
              Drupal.expandingFormatterEffects[data.effect + 'Css'](data);
            }
            // Otherwise use non-CSS effect.
            else {
              Drupal.expandingFormatterEffects[data.effect](data);
            }
          }
          // CSS3 effects.
          else if (data.css3 && typeof Drupal.expandingFormatterEffects[data.effect + 'Css'] !== 'undefined') {
            Drupal.expandingFormatterEffects[data.effect + 'Css'](data);
          }
          // Error.
          else {
            window.alert('Unknown effect: ' + data.effect);
          }
        });
      });
    }
  };

  /**
   * Object used for animation of expanding formatters.
   *
   * If the effect supports CSS3, it should create an additional method like
   * 'effectNameCss3'.
   */
  Drupal.expandingFormatterEffects = Drupal.expandingFormatter || {
    normal: function (data) {
      if (data.expanded) {
        data.$formatter
          .removeClass('expanded')
          .addClass('collapsed');
        data.$content.hide();
      }
      else {
        data.$formatter
          .removeClass('collapsed')
          .addClass('expanded');
        data.$content.show();
      }
    },
    collapseCss: function (data) {
      data.$formatter
        .removeClass('expanded')
        .addClass('collapsed')
        .height(data.collapsedHeight)
        .trigger('collapsed', [data]);
      data.$trigger.text(data.expandedLabel);
    },
    expandCss: function (data) {
      data.$formatter
        .removeClass('collapsed')
        .addClass('expanded')
        .height(data.expandedHeight)
        .trigger('expanded', [data]);
      if (data.collapsedLabel) {
        data.$trigger.text(data.collapsedLabel);
      }
      else {
        data.$trigger.hide();
      }
    },
    fade: function (data) {
      if (data.$formatter.hasClass('expanded')) {
        data.$trigger.fadeOut(data.jsDuration);
        data.$content
          .css({
            display: 'inline',
            opacity: 1
          })
          .animate({
            opacity: 0
          }, data.jsDuration, function () {
            data.$content.css({
              display: data.inline ? 'inline-block' : 'block',
              height: 0,
              overflow: 'hidden',
              width: 0
            });
            data.$formatter
              .removeClass('expanded')
              .addClass('collapsed')
              .height(data.collapsedHeight)
              .trigger('collapsed', [data])
              .find('.expanding-formatter-ellipsis').fadeIn(data.jsDuration);
            data.$trigger.text(data.expandedLabel).fadeIn(data.jsDuration);
          });
      }
      else {
        data.$formatter
          .removeClass('collapsed')
          .addClass('expanded')
          .height(data.expandedHeight)
          .find('.expanding-formatter-ellipsis').hide();
        data.$trigger.hide();
        if (data.collapsedLabel) {
          data.$trigger
            .text(data.collapsedLabel)
            .fadeIn(data.jsDuration);
        }
        data.$content
          .removeAttr('style')
          .css({
            display: data.inline ? 'inline' : 'block',
            opacity: 0
          })
          .animate({
            opacity: 1
          }, data.jsDuration, function () {
            data.$formatter.trigger('expanded', [data]);
          });
      }
    },
    fadeCss: function (data) {
      data.$formatter.addClass('fading');
      // Collapse.
      if (data.expanded) {
        setTimeout(function () {
          data.$formatter.removeClass('fading');
          Drupal.expandingFormatterEffects.collapseCss(data);
        }, 500);
      }
      // Expand.
      else {
        setTimeout(function () {
          data.$formatter.removeClass('fading');
        }, 500);
        Drupal.expandingFormatterEffects.expandCss(data);
      }
    },
    slide: function (data) {
      if (data.expanded) {
        data.$formatter
          .removeClass('expanded')
          .addClass('collapsed');
        data.$trigger.text(data.expandedLabel);
        data.$formatter.animate({
          height: data.collapsedHeight
        }, data.jsDuration, function () {
          data.$content.hide();
          data.$formatter
            .trigger('collapsed', [data])
            .find('.expanding-formatter-ellipsis').show();
        });
      }
      else {
        data.$formatter
          .removeClass('collapsed')
          .addClass('expanded')
          .find('.expanding-formatter-ellipsis').hide();
        data.$content.show();
        if (data.collapsedLabel) {
          data.$trigger.text(data.collapsedLabel);
        }
        else {
          data.$trigger.hide();
        }
        data.$formatter.animate({
          height: data.expandedHeight
        }, data.jsDuration, function () {
          data.$formatter.trigger('expanded', [data]);
        });
      }
    },
    slideCss: function (data) {
      // Add/remove animation classes to assist with styles.
      data.$formatter.addClass('sliding');
      setTimeout(function () {
        data.$formatter.removeClass('sliding');
      }, 500);
      // Collapse.
      if (data.expanded) {
        Drupal.expandingFormatterEffects.collapseCss(data);
      }
      // Expand.
      else {
        Drupal.expandingFormatterEffects.expandCss(data);
      }
    }
  };

})(jQuery);
