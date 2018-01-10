#!/usr/bin/php
<?PHP

function ft_is_sort($tab)
{
  $tmptab = $tab;
  sort($tmptab);
  foreach ($tab as $elem)
  {
    if (ord($tmptab[$i]) != ord($tab[$i]))
      return (false);
    $i++;
  }
  return (true);
}

?>
