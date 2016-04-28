<?php

/**
 * @file 
 * bubblesort.pages.inc
 */

/**
 * Bubblesort page
 */
function bubblesort_page() {

  if (isset($_POST['op'])) {

    switch ($_POST['op']) {

      // If Shuffle button, then shuffle deck
      case 'shuffle':
        _bubblesort_shuffle();
        break;

      // If Step button, then perform single sort operation
      case 'step':
        _bubblesort_step();
        break;

    } 

  }

  $variables = array(
    'set' => variable_get('bubblesort_set', array()),
    'set_size' => variable_get('bubblesort_set_size', BUBBLESORT_SET_SIZE),
    'pos' => variable_get('bubblesort_position', 0),
    'complete' => _bubblesort_check_complete(),
  );

  return theme('bubblesort_view', $variables);

}
