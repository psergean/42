#!/usr/bin/php
<?PHP

function filter($var)
{
  if ($var == NULL)
    return (false);
  return (true);
}

function ft_split($str)
{
  if ($str == NULL)
    return (false);
  $tab = array_filter(explode(' ', $str), filter);
  sort($tab);
  return ($tab);
}

?>
