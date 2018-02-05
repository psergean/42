<div class="corpse">

                <?php
                    if ($_SERVER['PHP_SELF'] === '/v2/srcs/index.php')
                    {
                        ?>
                        <html>
                            <div style="width:100%; height:100%; background-image:url(../img/logo.jpg); background-size:cover; background-repeat:no-repeat; background-position:center; opacity:0.9;">
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/about.php')
                    {
                        ?>
                        <html>
                            <div>
                                    <p><h1><u>Le projet Associatif :</u></h1></p>
                                    <p>A prevoir une description de l'asso</p>
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/team.php')
                    {
                        ?>
                        <html>
                            <div>
                                <img src="../img/dreamteam.jpg" style="width:100%; height:auto;"/>
                            </div>
                            <div style="width:100%; height:100%; background-image:url(../img/logo.jpg); background-size:contain;">

                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/calendar.php')
                    {
                        ?>
                        <html>
                            <div>
                                a prevoir un belle agenda ! peut etre en JS ???
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/news.php')
                    {
                        ?>
                        <html>
                            <div>
                                tableau des news
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/home.php')
                    {
                        ?>
                        <html>
                            <div>
                                une image d'acceuil
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/gallery.php')
                    {
                        ?>
                        <html>
                            <div>
                                pix gallery
                            </div>
                        </html>
                        <?php
                    }
                    else if ($_SERVER['PHP_SELF'] === '/v2/srcs/contact.php')
                    {
                        ?>
                        <html>
                                <div style="color:white">
                                    <p><h1><u>Contacts :</u></h1></p>
                                    <p>Email : Gararge83-C@jesaispassiyaunemail.com</p>
                                    <p>Telephone : +36123612</p>
                                    <p>Adresse : La boite au lettre de l'association</p>
                                    <p>rue Mirabeau peut etre<p>
                                    <p>Lille Fives le Ghetto, 59800</p>
                                </div>
                        </html>
                        <?php
                    }
                ?>

</div>
