(function($) {
  Drupal.behaviors.menuEditor = {
    attach: function (context, settings) {
      $('#menu-editor-overview-form #menu-overview', context).each(function(){
        
        // table elements
        var table = $(this);
        var tbody = $('tbody', this);
        
        // delete all checkbox
        (function(){
          var th_delete = $('thead th.delete-checkbox', table);
          var master_delete_checkbox = $('<input type="checkbox" class="master-delete-checkbox" />');
          th_delete.html('<span>&nbsp;'+th_delete.html()+'</span>');
          th_delete.prepend(master_delete_checkbox);
          
          var onchange = function(){
            var checked_now = master_delete_checkbox.attr('checked');
            $('tbody td.delete-checkbox :checkbox', table).attr('checked', checked_now);
          };
          
          master_delete_checkbox.change(onchange);
          
          // IE does not trigger the change event..
          if ($.browser.msie) {
            master_delete_checkbox.click(onchange);
          }
        })();
        
        // freeze width of first column (currently disabled)
        if (false) {
          var w = $('td.drag', this).width();
          $('td.drag', this).each(function(){
            $(this).css('width', w+'px');
          });
        }
        
        // get reference css for textareas
        var ref_input = $('td.path-edit input', this);
        var h = ref_input.height();
        var ref_css = {
          'height': h + 'px',
          'padding-top': ref_input.css('padding-top'),
          'padding-bottom': ref_input.css('padding-bottom')
        };
        var div_ref_height = ref_input.parent().height();
        
        // adjust height of existing description textareas
        $('td.description textarea', this).css(ref_css);
        // this is necessary because of the vertical-align:middle
        $('td.description div.form-item', this).css('height', div_ref_height+'px');
        
        // description column resizing
        $('td.description textarea', this).focus(function(){
          table.addClass('focus-description-column');
          $('tr.focus', table).removeClass('focus');
          $(this).parents('tr').slice(0, 1).addClass('focus');
        });
        $('td:not(.description) input', this).focus(function(){
          table.removeClass('focus-description-column');
          $('tr.focus', table).removeClass('focus');
          $(this).parents('tr').slice(0, 1).addClass('focus');
        });
      });
    }
  };
})(jQuery);
