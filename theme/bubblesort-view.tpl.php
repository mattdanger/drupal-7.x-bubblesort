<?php
/**
 * @file
 * bubblesort.tpl.php
 */
?>

<?php //print render($message); ?>

<form method="POST">
  <?php if (!$complete): ?><button name="op" value="step">Step</button><?php endif; ?>
  <button name="op" value="shuffle">Shuffle</button>
</form>
<hr>

<?php if ($set && $complete): ?>
  <h3>Sort complete!</h3>
  <p>Click Shuffle to reload with new data</p>
<?php endif; ?>

<?php if (!empty($set)): ?>

  <?php if (!$complete): ?><p>Click "Step" above to walk through the sorting item-by-item.</p><?php endif; ?>

  <table class="bubblesort">
  <?php for ($i = 0; $i < count($set); $i++): ?>
    <tr>
      <td>
        <span 
          style="width: <?php print $set[$i]; ?>%" 
          <?php if (!$complete && (($pos == $i) || ($pos+1 == $i))): ?>class="active"<?php endif; ?>
        ></span>
        &nbsp;   <?php print $set[$i]; ?>
        
      </td>
    </tr>
  <?php endfor; ?>
  </table>
  
<?php else: ?>

  <p>To begin, click "Shuffle" to generate a sortable list of data.</p>

<?php endif; ?>