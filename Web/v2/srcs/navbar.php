
<html>
    <div id="mySidenav" class="nav">
        <a href="javascript:void(0)" class="closebtn" onclick="closeNav()"><i class="material-icons" style="font-size:2vmin">close</i></a>
<div id="logo" style="width:100%;height:33%;">
        <div class="logo">
            <a href="index.php">
                <img class="logo" title="association d'gens normal" alt="association d'gens normal" src="../img/logo.jpg"/>
            </a>
        </div>
</div>
    <div class="navcenter">
        <ul>
      <?php
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/home.php')
          {
              ?>
                  <li>
                      <a href="home.php" class="activate">
                          <i class="fas fa-home"></i> - Home
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="home.php">
                          <i class="fas fa-home"></i> - Home
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/news.php')
          {
              ?>
                  <li>
                      <a href="news.php" class="activate">
                          <i class="far fa-newspaper"></i> - News
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="news.php">
                          <i class="far fa-newspaper"></i> - News
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/calendar.php')
          {
              ?>
                  <li>
                      <a href="calendar.php" class="activate">
                          <i class="far fa-calendar-alt"></i> - Agenda
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="calendar.php">
                          <i class="far fa-calendar-alt"></i> - Agenda
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/about.php')
          {
              ?>
                  <li>
                      <a href="about.php" class="activate">
                          <i class="fa fa-globe"></i> - About
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="about.php">
                          <i class="fa fa-globe"></i> - About
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/gallery.php')
          {
              ?>
                  <li>
                      <a href="gallery.php" class="activate">
                          <i class="fas fa-camera-retro"></i> - Gallery
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="gallery.php">
                          <i class="fas fa-camera-retro"></i> - Gallery
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/team.php')
          {
              ?>
                  <li>
                      <a href="team.php" class="activate">
                          <i class="fas fa-users"></i> - Team
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="team.php">
                          <i class="fas fa-users"></i> - Team
                      </a>
                  </li>
              <?php
          }
          if ($_SERVER['PHP_SELF'] === '/v2/srcs/contact.php')
          {
              ?>
                  <li>
                      <a href="contact.php" class="activate">
                          <i class="fas fa-address-book"></i> - Contact
                      </a>
                  </li>
              <?php
          }
          else
          {
              ?>
                  <li>
                      <a href="contact.php">
                          <i class="fas fa-address-book"></i> - Contact
                      </a>
                  </li>
              <?php
          }
      ?>
  </ul>
</div>
</div>
<script>
function openNav() {
    document.getElementById("mySidenav").style.width = "18%";
    // document.getElementById("header").style.width = "80%";
    // document.getElementById("corpse").style.width = "80%";
    // document.getElementById("footer").style.width = "80%";
    document.getElementById("header").style.opacity = "0.9";
    document.getElementById("corpse").style.opacity = "0.8";
    document.getElementById("footer").style.opacity = "0.9";
    document.getElementById("logo").style.height = "33%";
    document.getElementById("logo").style.width = "100%";
    document.getElementById("main").style.marginLeft= "18%";
}
function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
    // document.getElementById("header").style.width = "100%";
    // document.getElementById("corpse").style.width = "100%";
    // document.getElementById("footer").style.width = "100%";
    document.getElementById("header").style.opacity = "1";
    document.getElementById("corpse").style.opacity = "1";
    document.getElementById("footer").style.opacity = "1";
    document.getElementById("logo").style.height = "0.001%";
    document.getElementById("logo").style.width = "0%";
    // document.getElementsByClassName("logo").style.height = "0%";
    // document.getElementsByClassName("logo").style.width = "0%";
    document.getElementById("main").style.marginLeft= "0";
}
</script>
</html>
