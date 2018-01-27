<?PHP

$priv_path = "../private";
$psswd_path = "../private/passwd";
if ($_POST['login'] != "" && $_POST['passwd'] != "")
{
  if ($_POST['submit'] === 'OK')
  {
    $password = hash('whirlpool', $_POST['passwd']);
    if (file_exists($priv_path) == FALSE)
    {
      mkdir($priv_path, 0777, TRUE);
    }
    if (file_exists($psswd_path) == FALSE)
    {
      $users_array = array(array('login'=>$_POST['login'], 'passwd'=>$password));
      $serialize = serialize($users_array);
      file_put_contents($psswd_path, $serialize);
      echo "OK\n";
    }
    else
    {
      $exist = FALSE;
      $users_array = file_get_contents($psswd_path);
      $unserialize = unserialize($users_array);
      foreach ($unserialize as $elem)
      {
        if ($elem['login'] == $_POST['login'])
          $exist = TRUE;
      }
      if ($exist == FALSE)
      {
        $unserialize[] = array('login' => $_POST['login'], 'passwd' => $password);
        $serialize = serialize($unserialize);
        file_put_contents($psswd_path, $serialize);
        echo "OK\n";
      }
      else
      {
        echo "ERROR\n";
      }
    }
  }
  else
  {
    echo "ERROR\n";
  }
}
else
{
  echo "ERROR\n";
}

?>
