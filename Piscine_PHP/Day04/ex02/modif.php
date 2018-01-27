<?PHP

if (!$_POST['login'] === "" || $_POST['oldpw'] === "" || $_POST['newpw'] === "" || $_POST['submit'] !== 'OK')
{
		echo "ERROR\n";
		return ;
}
$tab = unserialize(file_get_contents('../private/passwd'));
if ($tab)
{
	foreach ($tab as $key => $elem)
  {
		if ($elem['login'] === $_POST['login'] && $elem['passwd'] === hash('whirlpool', $_POST['oldpw']))
    {
				$tab[$key]['passwd'] = hash('whirlpool', $_POST['newpw']);
				file_put_contents('../private/passwd', serialize($tab));
				echo "OK\n";
				return;
		}
	}
}
echo "ERROR\n";

?>
