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
  return ($tab);
}

if ($argc >= 2)
{
  $strtest = trim($argv[1]);
  $i = 0;
  $count = 0;
  $alpha = 0;
  while ($strtest[$i])
  {
    if ($strtest[$i] == ' ')
      $space++;
    $i++;
  }
  if ($space == 0 && $i > 0)
  {
    echo $strtest."\n";
    return (0);
  }
  $str = $argv[1];
  $str = trim($str);
  if ($str == NULL)
    return (false);
  $tab = array_filter(explode(' ', $str), filter);
  $tab = implode(' ', $tab);
  $firstworld = ft_split($tab);
  $x = 1;
  foreach ($firstworld as $var)
  {
    $strnew = $tmp." ".$firstworld[$x];
    trim($strnew);
    $tmp = $strnew;
    $x++;
  }
  $str = $strnew;
  $str = trim($str);
  if ($str == NULL)
  {
    echo "0\n";
    return (0);
  }
  $tab = array_filter(explode(' ', $str), filter);
  $tab = implode(' ', $tab);
  echo $tab." ".$firstworld[0]."\n";
}
else
  return (false);

?>
