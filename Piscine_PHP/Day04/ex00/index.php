<?PHP

session_start();
if ($_GET['submit'] === 'OK')
{
  $_SESSION['login'] = $_GET['login'];
  $_SESSION['psswd'] = $_GET['psswd'];
}

?>
<html>
  <body>
    <form method="GET">
      Identifiant:
      <br />
      <input type="text" name="login" value="<?PHP echo $_SESSION['login'] ?>" />
      <br />
      <br />
      Mot de passe:
      <br />
      <input type="password" name="psswd" value="<?PHP echo $_SESSION['psswd'] ?>" />
      <br />
      <br />
      <input type="submit" name="submit" value="OK" />
    </form>
  </body>
</html>
