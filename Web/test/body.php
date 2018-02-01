<div class="element-corspe-mid">
    <?php
        if ($_SERVER['PHP_SELF'] === '/test/index.php')
        {
            echo ("index");
            ?>
            <html>blabla</html>
            <?php
        }
        else if ($_SERVER['PHP_SELF'] === '/test/asso.php')
        {
            ?>
            <html>
                <div class="container">
                    <div class="contact">
                        <p><h1><u>Le projet Associatif :</u></h1></p>
                        <p>A prevoir une description de l'asso</p>
                    </div>
                </div>
            </html>
            <?php
        }
        else if ($_SERVER['PHP_SELF'] === '/test/team.php')
        {
            ?>
            <html>
                <div class="container">
                    <img src="img/dreamteam.jpg" class="team"/>
                </div>
            </html>
            <?php
        }
        else if ($_SERVER['PHP_SELF'] === '/test/calendar.php')
        {
            ?>
            <html>
                <div class="container">
                    a prevoir un belle agenda ! peut etre en JS ??
                </div>
            </html>
            <?php
        }
        else if ($_SERVER['PHP_SELF'] === '/test/contacts.php')
        {
            ?>
            <html>
                <div class="container">
                    <div class="contact">
                        <p><h1><u>Contacts :</u></h1></p>
                        <p>Email : Gararge83-C@jesaispassiyaunemail.com</p>
                        <p>Telephone : +36123612</p>
                        <p>Adresse : La boite au lettre de l'association</p>
                        <p>rue Mirabeau peut etre<p>
                        <p>Lille Fives le Ghetto, 59800</p>
                    </div>
                </div>
            </html>
            <?php
        }
    ?>
</div>
<div class="element-corspe-right"></div>
