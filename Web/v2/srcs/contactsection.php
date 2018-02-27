<html>
    <div class="center">
        <div class="center" style="text-align: center">
            <p><h1><u>Contacts :</u></h1></p>
            <p>Email : Gararge83-C@jesaispassiyaunemail.com</p>
            <p><i class="material-icons">call</i>Telephone : +36123612</p>
            <p>Adresse : La boite au lettre de l'association</p>
            <p>rue Mirabeau peut etre<p>
            <p>Lille Fives le Ghetto, 59800</p>
        </div>
        <div id="map" style="width:40vw;height:40vw;margin-left:auto;margin-right:auto;"></div>

        <script>
            function myMap()
            {
                var myCenter = new google.maps.LatLng(50.63477967243569, 3.0870525448146964);
                var mapCanvas = document.getElementById("map");
                var mapOptions = {center: myCenter, zoom: 12}
                var map = new google.maps.Map(mapCanvas, mapOptions);
                var marker = new google.maps.Marker({position:myCenter});
                        marker.setMap(map);
            }
        </script>
        <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBU9TRuhtup84xMXy2hjmWBb9HW6_JE0Rw&callback=myMap"></script>
        <br/>
    </div>
</html>
