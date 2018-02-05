<div class="element-corspe-left">

            <!-- **************** NAV BAR ***************** -->
        <ul>
            <?php
                if ($_SERVER['PHP_SELF'] === '/test/index.php')
                {
                    ?>
                        <li>
                            <a href="/test/index.php" class="activate">
                                <i class="fas fa-home" style="color:white"></i> - Home
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/index.php">
                                <i class="fas fa-home" style="color:white"></i> - Home
                            </a>
                        </li>
                    <?php
                }
                if ($_SERVER['PHP_SELF'] === '/test/news.php')
                {
                    ?>
                        <li>
                            <a href="/test/news.php" class="activate">
                                <i class="far fa-newspaper" style="color:white"></i> - News
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/news.php">
                                <i class="far fa-newspaper" style="color:white"></i> - News
                            </a>
                        </li>
                    <?php
                }
                if ($_SERVER['PHP_SELF'] === '/test/calendar.php')
                {
                    ?>
                        <li>
                            <a href="/test/calendar.php" class="activate">
                                <i class="far fa-calendar-alt" style="color:white"></i> - Agenda
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/calendar.php">
                                <i class="far fa-calendar-alt" style="color:white"></i> - Agenda
                            </a>
                        </li>
                    <?php
                }
                if ($_SERVER['PHP_SELF'] === '/test/asso.php')
                {
                    ?>
                        <li>
                            <a href="/test/asso.php" class="activate">
                                <i class="fas fa-book" style="color:white"></i> - About
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/asso.php">
                                <i class="fas fa-book" style="color:white"></i> - About
                            </a>
                        </li>
                    <?php
                }
                if ($_SERVER['PHP_SELF'] === '/test/team.php')
                {
                    ?>
                        <li>
                            <a href="/test/team.php" class="activate">
                                <i class="fas fa-users" style="color:white"></i> - Team
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/team.php">
                                <i class="fas fa-users" style="color:white"></i> - Team
                            </a>
                        </li>
                    <?php
                }
                if ($_SERVER['PHP_SELF'] === '/test/contacts.php')
                {
                    ?>
                        <li>
                            <a href="/test/contacts.php" class="activate">
                                <i class="fas fa-address-book" style="color:white"></i> - Contact
                            </a>
                        </li>
                    <?php
                }
                else
                {
                    ?>
                        <li>
                            <a href="/test/contacts.php">
                                <i class="fas fa-address-book" style="color:white"></i> - Contact
                            </a>
                        </li>
                    <?php
                }
            ?>
        </ul>

            <!-- **************** NAV BAR ***************** -->

</div>
