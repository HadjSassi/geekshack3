<?php
    require 'serverAdd.php';
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CountDown</title>
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
    <style>
        p {
            text-align: center;
            font-size: 60px;
            margin-top: 0px;
        }
    </style>
</head>

<body>
    <div class="limiter">
        <div class="container-login100">
            <div class="wrap-login100 p-l-85 p-r-85 p-t-55 p-b-55">
                <h1 class="text-primary"><b>Geeks Hack Starts in</b></h1>
                <p id="demo"></p>
            </div>
        </div>
    </div>
    <script>
        // Set the date we're counting down to
        // 1. JavaScript
        // var countDownDate = new Date("Sep 5, 2018 15:37:25").getTime();
        // 2. PHP
        var countDownDate = <?php require 'params.php'; echo strtotime($start); ?> * 1000;
        // console.log(new Date(countDownDate));
        var now = <?php echo time() ?> * 1000;

        // Update the count down every 1 second
        var x = setInterval(function() {

            // Get todays date and time
            // 1. JavaScript
            // var now = new Date().getTime();
            // 2. PHP
            now = now + 1000;

            // Find the distance between now an the count down date
            var distance =countDownDate-now;

            // Time calculations for days, hours, minutes and seconds
            var days = Math.floor(distance / (1000 * 60 * 60 * 24));
            var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
            var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
            var seconds = Math.floor((distance % (1000 * 60)) / 1000);

            // Output the result in an element with id="demo"
            if (days !== 0)
                document.getElementById("demo").innerHTML = days + "day and <br> "+hours + ": " +
                    minutes + ": " + seconds + "";
            else
                document.getElementById("demo").innerHTML = hours + ": " +
                    minutes + ": " + seconds + "";
           // If the count down is over, write some text 
            if (distance <= 0) {
                clearInterval(x);
                document.getElementById("demo").innerHTML ="Redirection ..."
                let add = '<?php echo $add; ?>';
                console.log(add)
                window.location.href = add+'/login.php';
            }
        }, 1000);
    </script>
</body>

</html>
