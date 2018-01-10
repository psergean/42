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

if ($argc < 2)
  return (false);
$x = 2;
$str = $argv[1];
while ($argv[$x])
{
  $str = $str." ".$argv[$x];
  $x++;
}
$tab = ft_split($str);
foreach ($tab as $str)
{
  echo "$str\n";
}

?>
