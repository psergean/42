#!/usr/bin/php
<?PHP
date_default_timezone_set('Europe/Paris');

function check_argv($argv)
{
  if (preg_match("/^([L|l]undi|[M|m]ardi|[M|m]ercredi|[J|j]eudi|[V|v]endredi|[S|s]amedi|[D|d]imanche) {1}[0-9]{2} {1}([J|j]anvier|[F|f]évrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]oût|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d]écembre) {1}[0-9]{4} {1}[0-9]{2}:{1}[0-9]{2}:{1}[0-9]{2}$/", $argv) != 0)
  {
    return (true);
  }
  else
  {
    return (false);
  }
}

function get_month($month)
{
  if ($month == "Janvier" || $month == "janvier")
    return (1);
  if ($month == "Février" || $month == "février")
    return (2);
  if ($month == "Mars" || $month == "mars")
    return (3);
  if ($month == "Avril" || $month == "avril")
    return (4);
  if ($month == "Mai" || $month == "mai")
    return (5);
  if ($month == "Juin" || $month == "juin")
    return (6);
  if ($month == "Juillet" || $month == "juillet")
    return (7);
  if ($month == "Août" || $month == "août")
    return (8);
  if ($month == "Septembre" || $month == "septembre")
    return (9);
  if ($month == "Octobre" || $month == "octobre")
    return (10);
  if ($month == "Novembre" || $month == "novembre")
    return (11);
  if ($month == "Décembre" || $month == "décembre")
    return (12);

}

if ($argc >= 2)
{
  if (check_argv($argv[1]) == false)
  {
    echo "Wrong Format\n";
    return (-1);
  }
  else
  {
    preg_match("/^([L|l]undi|[M|m]ardi|[M|m]ercredi|[J|j]eudi|[V|v]endredi|[S|s]amedi|[D|d]imanche)/" , $argv[1], $day);
    preg_match("/[0-9]{1,2}/", $argv[1], $date);
    preg_match("/([J|j]anvier|[F|f]évrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]oût|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d]écembre)/", $argv[1], $month);
    $m = get_month($month[0]);
    preg_match("/[0-9]{4}/", $argv[1], $year);
    preg_match("/[0-9]{2}:/", $argv[1], $hour);
    preg_match("/:[0-9]{2}:/", $argv[1], $minute);
    preg_match("/:[0-9]{2}$/", $argv[1], $seconde);
    $hour[0] = substr($hour[0], 0, 2);
    $minute[0] = substr($minute[0], 1);
    $minute[0] = substr($minute[0], 0, 2);
    $seconde[0] = substr($seconde[0], 1);
    echo mktime($hour[0], $minute[0], $seconde[0], $m, $date[0], $year[0])."\n";
  }
}
?>
