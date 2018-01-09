#!/usr/bin/php
<?PHP

function filter($var)
{
  if ($var == NULL)
    return (false);
  return (true);
}

if ($argc == 2)
{
  $str = $argv[1];
  $str = trim($str);
  if ($str == NULL)
    return (false);
  $tab = array_filter(explode(' ', $str), filter);
  $tab = implode(' ', $tab);
  echo "$tab\n";
}
else
  return (false);

?>
