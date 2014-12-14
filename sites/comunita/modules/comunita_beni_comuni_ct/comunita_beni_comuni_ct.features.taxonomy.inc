<?php
/**
 * @file
 * comunita_beni_comuni_ct.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function comunita_beni_comuni_ct_taxonomy_default_vocabularies() {
  return array(
    'tipologia_bene_oggetto_di_intervento' => array(
      'name' => 'Tipologia bene oggetto di intervento',
      'machine_name' => 'tipologia_bene_oggetto_di_intervento',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
