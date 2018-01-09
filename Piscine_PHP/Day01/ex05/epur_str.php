#!/usr/bin/php
<?PHP

if ($argc == 2)
{
  $str = $argv[1];
  $str = trim($str);
  if ($str == NULL)
    return (false);
  $tab = array_filter(explode(' ', $str));
  $tab = implode(' ', $tab);
  echo "$tab\n";
}
else
  return (false);

?>
