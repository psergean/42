<nav>
    <div class="logo">
        <a href="index.php">
            <img class="logo" title="association d'gens normal" alt="association d'gens normal" src="../img/logo.jpg"/>
        </a>
        <text></text>
    </div>
    <ul>
        <?php
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/home.php')
            {
                ?>
                    <li>
                        <a href="home.php" class="activate">
                            <i class="fas fa-home" style="color:white"></i> - Home
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="home.php">
                            <i class="fas fa-home" style="color:white"></i> - Home
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/news.php')
            {
                ?>
                    <li>
                        <a href="news.php" class="activate">
                            <i class="far fa-newspaper" style="color:white"></i> - News
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="news.php">
                            <i class="far fa-newspaper" style="color:white"></i> - News
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/calendar.php')
            {
                ?>
                    <li>
                        <a href="calendar.php" class="activate">
                            <i class="far fa-calendar-alt" style="color:white"></i> - Agenda
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="calendar.php">
                            <i class="far fa-calendar-alt" style="color:white"></i> - Agenda
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/about.php')
            {
                ?>
                    <li>
                        <a href="about.php" class="activate">
                            <i class="fas fa-book" style="color:white"></i> - About
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="about.php">
                            <i class="fas fa-book" style="color:white"></i> - About
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/gallery.php')
            {
                ?>
                    <li>
                        <a href="gallery.php" class="activate">
                            <i class="fas fa-camera-retro" style="color:white"></i> - Gallery
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="gallery.php">
                            <i class="fas fa-camera-retro" style="color:white"></i> - Gallery
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/team.php')
            {
                ?>
                    <li>
                        <a href="team.php" class="activate">
                            <i class="fas fa-users" style="color:white"></i> - Team
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="team.php">
                            <i class="fas fa-users" style="color:white"></i> - Team
                        </a>
                    </li>
                <?php
            }
            if ($_SERVER['PHP_SELF'] === '/v2/srcs/contact.php')
            {
                ?>
                    <li>
                        <a href="contact.php" class="activate">
                            <i class="fas fa-address-book" style="color:white"></i> - Contact
                        </a>
                    </li>
                <?php
            }
            else
            {
                ?>
                    <li>
                        <a href="contact.php">
                            <i class="fas fa-address-book" style="color:white"></i> - Contact
                        </a>
                    </li>
                <?php
            }
        ?>
    </ul>
</nav>
