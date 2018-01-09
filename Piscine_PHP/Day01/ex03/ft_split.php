#!/usr/bin/php
<?PHP

function ft_split($str)
{
  if ($str == NULL)
    return (false);
  $tab = array_filter(explode(' ', $str));
  sort($tab);
  return ($tab);
}

?>
