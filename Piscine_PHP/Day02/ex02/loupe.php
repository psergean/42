#!/usr/bin/php
<?PHP

if ($argc >= 2)
{
  $str = file_get_contents($argv[1]);
  preg_match_all("/href=[^>]+[^<]+</", $str, $link);
  preg_match_all("/title=\"[^\"]+\"/", $str, $title);
  $x = 0;
  foreach ($link[0] as $elem)
  {
    preg_match("/>[^<]+/", $elem, $tmp);
    $linkmatch[$x] = $tmp;
    $x++;
  }
  $x = 0;
  foreach ($title[0] as $elem)
  {
    preg_match("/\"[^\"]+/", $elem, $tmp);
    $titlematch[$x] = $tmp;
    $x++;
  }
  $y = 0;
  while ($linkmatch[$y])
  {
    $x = 0;
    while ($linkmatch[$y][$x])
    {
      $pattern = $linkmatch[$y][$x];
      $pattern = "/$pattern/";
      $replacement = strtoupper($linkmatch[$y][$x]);
      $str = preg_replace($pattern, $replacement, $str);
      $x++;
    }
    $y++;
  }
  $y = 0;
  while ($titlematch[$y])
  {
    $x = 0;
    while ($titlematch[$y][$x])
    {
      $pattern = $titlematch[$y][$x];
      $pattern = "/$pattern/";
      $replacement = strtoupper($titlematch[$y][$x]);
      $str = preg_replace($pattern, $replacement, $str);
      $x++;
    }
    $y++;
  }
  echo "$str";
}
else
  return (false);

?>
