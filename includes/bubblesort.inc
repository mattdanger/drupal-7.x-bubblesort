<?php

/**
 * @file
 * bubblesort.inc
 */

/**
 * Generate a new set of unsorted data
 */
function _bubblesort_shuffle() {

  $set_size = variable_get('bubblesort_set_size', BUBBLESORT_SET_SIZE);
  $min = BUBBLESORT_MIN;
  $max = BUBBLESORT_MAX;
  $set = array();

  while (count($set) < $set_size) {
    
    // Random value between $min and $max
    $rand = rand($min, $max);

    // Make sure this random value doesn't already exist in our dataset
    if (!in_array($rand, $set)) {
      $set[] = $rand;
    }

  }

  variable_set('bubblesort_set', $set);  
  variable_set('bubblesort_position', 0);

}

/**
 * Return bubble sort set
 */
function _bubblesort_step() {

  $pos = variable_get('bubblesort_position', 0);
  $set = variable_get('bubblesort_set', array());
  $size = count($set);

  // Compare values & swap if necessary
  if (isset($set[$pos+1]) && $set[$pos+1] > $set[$pos]) {

    // Swap numbers
    $tmp = $set[$pos];
    $set[$pos] = $set[$pos+1];
    $set[$pos+1] = $tmp;

    variable_set('bubblesort_set', $set);

  }

  // Update position
  if ($pos == ($size-2)) {

    variable_set('bubblesort_position', 0);

  } else {

    $pos++;
    variable_set('bubblesort_position', $pos);

  }


}

/**
 * Check if data is completely sorted
 *
 * @returns bool
 */
function _bubblesort_check_complete() {

  // Copy the data
  $set = variable_get('bubblesort_set', array());
  
  // Sort it
  $size = count($set);
  $sorted = $set;
  for ($i = 0; $i < $size; $i++) {

    for ($j = 0; $j < $size - 1 - $i; $j++) {

      if ($sorted[$j+1] > $sorted[$j]) {

        // Swap numbers
        $tmp = $sorted[$j];
        $sorted[$j] = $sorted[$j+1];
        $sorted[$j+1] = $tmp;

      }

    }

  }
  
  // Does the sorted data match the stored data?
  return ($set == $sorted);

}