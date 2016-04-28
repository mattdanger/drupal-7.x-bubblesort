<?php

/**
 * @file bubblesort.admin.inc
 */

/**
 * Form builder.
 */
function bubblesort_settings_form($form, &$form_state) {

  $form['bubblesort_set_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Set Size'),
    '#default_value' => variable_get('bubblesort_set_size', BUBBLESORT_SET_SIZE),
    '#description' => 'A value between 5 and 15 is recommended.',
    '#size' => 5,
  );

  return system_settings_form($form);

}

/**
 * Form validate
 */
function bubblesort_settings_form_validate($form, &$form_state) {

  if (!is_numeric($form_state['values']['bubblesort_set_size'])) {

    form_set_error('bubblesort_set_size', t('You must enter a numeric value.'));

  } else if ($form_state['values']['bubblesort_set_size'] < 5 || $form_state['values']['bubblesort_set_size'] > 15) {
  
    form_set_error('bubblesort_set_size', t('A value between 5 and 15 is recommended.'));

  }

}
