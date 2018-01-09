#!/usr/bin/php
<?PHP

function check_is_digit($str)
{
  $str = trim($str);
  if ($str[0] == '0' || $str[0] == '2' || $str[0] == '4' || $str[0] == '6' || $str[0] == '8')
    return (1);
  if ($str[0] == '1' || $str[0] == '3' || $str[0] == '5' || $str[0] == '7' || $str[0] == '9')
    return (0);
  if ($str[0] == NULL)
    return (-1);
}

function check_str($str, $nb)
{
  $x = 0;
  $str = trim($str);
  while ($str[$x])
  {
    if ($str[$x] < '0' || $str[$x] > '9')
      return (-1);
    $x++;
  }
}

echo "Entrez un nombre: ";

while ($nb = fgets(STDIN))
{
  $str = $nb;
  $nb = trim($nb);
  if (check_str($str, $nb) == -1)
    echo "'$nb' n'est pas un chiffre.\n";
  else
  {
    if (check_is_digit(strrev($str)) == 1)
      echo "Le chiffre $nb est pair.\n";
    if (check_is_digit(strrev($str)) == 0)
      echo "Le chiffre $nb est impair.\n";
    if (check_is_digit(strrev($str)) == -1)
      echo "'$nb' n'est pas un chiffre.\n";
  }
  echo "Entrez un nombre: ";
}
echo "^D\n";
?>
