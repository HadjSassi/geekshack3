<?php
?>
    <html lang="en">
    <head>
        <title>Hack Over</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <!--===============================================================================================-->
        <link rel="icon" href="assets/logo-geeks.png"/>
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/bootstrap/css/bootstrap.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="fonts2/font-awesome-4.7.0/css/font-awesome.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="fonts2/Linearicons-Free-v1.0.0/icon-font.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/animate/animate.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/css-hamburgers/hamburgers.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/animsition/css/animsition.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/select2/select2.min.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="vendor/daterangepicker/daterangepicker.css">
        <!--===============================================================================================-->
        <link rel="stylesheet" type="text/css" href="css2/util.css">
        <link rel="stylesheet" type="text/css" href="css2/main.css">
        <!--===============================================================================================-->

        <style>
            .modal {
                display: none; /* Hidden by default */
                position: fixed; /* Stay in place */
                z-index: 1; /* Sit on top */
                left: 0;
                top: 0;
                width: 100%; /* Full width */
                height: 100%; /* Full height */
                overflow: auto; /* Enable scroll if needed */
                background-color: rgb(0, 0, 0); /* Fallback color */
                background-color: rgba(0, 0, 0, 0.4); /* Black w/ opacity */
            }

            /* Modal Content/Box */
            .modal-content {
                background-color: #fefefe;
                margin: 15% auto; /* 15% from the top and centered */
                padding: 20px;
                border: 1px solid #888;
                width: 80%; /* Could be more or less, depending on screen size */
            }

            /* The Close Button */
            .close {
                color: #aaa;
                float: right;
                font-size: 28px;
                font-weight: bold;
            }

            video {
                object-fit: cover;
                width: 100vw;
                height: 100vh;
                object-fit: cover;
                position: fixed;
                left: 0;
                right: 0;
                top: 0;
                bottom: 0;
                z-index: -1;
            }

            .close:hover,
            .close:focus {
                color: black;
                text-decoration: none;
                cursor: pointer;
            }
        </style>
    </head>
    <body>

    <div class="limiter">
        <div class="container-login100" style="background: transparent;">
            <video autoplay muted loop poster id="myVideo">
                <source src="vd.mp4" type="video/mp4">
            </video>
            <div class=""
                 style="">
                <div class="text-center" >
                    <img src="assets/logo-geekswhite.png" width="200" style="margin-top:-7px; margin-right: -30px;" >
                    <h1 class="text-white">
                        <b>Geeks Hack 3</b>
                    </h1>
                    <h2 class="text-white">
                        <u>Is Over</u>
                    </h2>
                    <h2 class="text-white">
                        <b>
                            Thanks for your participation
                        </b>
                    </h2>
                    <br>
                    <a class="btn btn-light" href="https://www.ensitgeeksclub.com/">You can visit our website page.</a>


                </div>
            </div>
        </div>
    </div>
    <div id="myModal" class="modal">

        <div class="modal-content">
            <div style="display: flex; flex-direction: row-reverse;"><span class="close">&times;</span></div>
            <p>Login or password is/are wrong. Please check your login parameters</p>
        </div>

    </div>


    <div id="dropDownSelect1"></div>

    <?php
    if (isset($_POST['ID']) && isset($_POST['PASS'])) {
        require './config.php';
        try {

            $sql = "SELECT id_team, login, team_tag FROM team where state =1 and password = '" . $_POST['PASS'] . "';";

            function exists($conn, $sql)
            {
                $founded = false;
                foreach ($conn->query($sql) as $row) {
                    if ($row['team_tag'] == $_POST['ID'] || $row['login'] == $_POST['ID']) {
                        $founded = true;
                        $_SESSION['ID'] = $row['team_tag'];
                        $_SESSION['id_team'] = $row['id_team'];
                        require 'serverAdd.php';
                        echo " <script>window.location.href = '" . $add . "/index.php';</script> ";

                    }
                }
                return $founded;
            }

            if (exists($conn, $sql) == false) {
                ?>

                <script>
                    function getModal() {
                        // Get the modal
                        var modal = document.getElementById("myModal");


                        // Get the <span> element that closes the modal
                        var span = document.getElementsByClassName("close")[0];

                        // When the user clicks on the button, open the modal

                        modal.style.display = "block";


                        // When the user clicks on <span> (x), close the modal
                        span.onclick = function () {
                            modal.style.display = "none";
                        }

                        // When the user clicks anywhere outside of the modal, close it
                        window.onclick = function (event) {
                            if (event.target == modal) {
                                modal.style.display = "none";
                            }
                        }
                    }

                    getModal()
                </script>

                <?php

            }
        } catch (PDOException $e) {
            echo "<script>console.log('Error: " . $e->getMessage() . "')</script>";
        }
    }
    ?>

    <!--===============================================================================================-->
    <script src="vendor/jquery/jquery-3.2.1.min.js"></script>
    <!--===============================================================================================-->
    <script src="vendor/animsition/js/animsition.min.js"></script>
    <!--===============================================================================================-->
    <script src="vendor/bootstrap/js/popper.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.min.js"></script>
    <!--===============================================================================================-->
    <script src="vendor/select2/select2.min.js"></script>
    <!--===============================================================================================-->
    <script src="vendor/daterangepicker/moment.min.js"></script>
    <script src="vendor/daterangepicker/daterangepicker.js"></script>
    <!--===============================================================================================-->
    <script src="vendor/countdowntime/countdowntime.js"></script>
    <!--===============================================================================================-->
    <script src="js2/main.js"></script>

    </body>
    </html>
<?php ?>
