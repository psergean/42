#!/usr/bin/php
<?PHP

if ($argc >= 2)
{
  $str = trim($argv[1]);
  $pattern = '/[ \t]+/';
  $replacement = ' ';
  $regex = preg_replace($pattern, $replacement, $str);
  echo "$regex\n";
}
else
  return (false);

?>
