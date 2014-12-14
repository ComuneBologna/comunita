<?php
/**
 * @file
 * comunita_forms.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_forms_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_allegati|entityform|vandalismo_grafico|form';
  $field_group->group_name = 'group_allegati';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'vandalismo_grafico';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Allegati',
    'weight' => '18',
    'children' => array(
      0 => 'field_foto_del_luogo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Allegati',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-allegati field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_allegati|entityform|vandalismo_grafico|form'] = $field_group;

  return $export;
}
