
<html>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <div id="corpse" onclick="closeNav()">
        </html>
                <?php
                    if ($_SERVER['PHP_SELF'] === '/v2/srcs/index.php')
                    {
                        ?>
                            <html>
                            <div class="center">
                                <div style="width:auto; height:100%; background-image:url(../img/logo.jpg); background-size:cover; background-repeat:no-repeat; background-position:center; opacity:0.9;"></div>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/about.php')
                    {
                        ?>
                        <html>
                            <div class="center">
                                <div>
                                    <p><h1><u>Le projet Associatif :</u></h1></p>
                                    <p>A prevoir une description de l'asso</p>
                                </div>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/team.php')
                    {
                        include("./teamcard.php");
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/calendar.php')
                    {
                        ?>
                        <html>
                            <div class="center">
                                <div>
                                    a prevoir un belle agenda ! peut etre en JS ???
                                </div>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/news.php')
                    {
                        ?>
                        <html>
                            <div class="center">
                                <div>
                                    tableau des news
                                </div>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/home.php')
                    {
                        ?>
                        <html>
                            <div class="center">
                                <div>
                                    une image d'acceuil
                                </div>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/contact.php')
                    {
                        include("contactsection.php");
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/gallery.php')
                    {
                        include("slideshow_gallery.php");
                    }
                        ?>
        <html>
    </div>
</html>
