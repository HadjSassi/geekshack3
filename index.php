<?php
require 'serverAdd.php';
 
session_start();
if (isset($_SESSION['ID']) == false)
    echo " <script>window.location.href = '".$add."/login.php';</script> ";
else {
    echo " <script>console.log('".$_SESSION['ID']."');</script> ";
    $id = $_SESSION['ID'];
    //echo "<h1>$id</h1>";
    shell_exec("cd scode; if [ -d " . $id . " ]; then cd $id; else mkdir $id; cd $id; fi");
?>


    <!DOCTYPE html>
    <html>

    <head>
        <style>
            
            video{
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
            body {
                overflow-x: hidden;
                

            }
        </style>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="color-scheme" content="dark light">

        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/5.0.0/normalize.min.css">
        <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.css'>
        <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick-theme.min.css'>
        <link rel="stylesheet" href="./slider.css">

        <meta charset="utf-8">
        <meta http-equiv="x-ua-compatible" content="ie=edge">
        <title>Problems</title>
        <link rel="icon" href="assets/logo-geeks.png" />
        <meta name="description" content="">
        <meta name="viewport" content="width=device-width, initial-scale=1">


        <link rel="stylesheet" href="css/font-awesome.min.css">
        <link rel="stylesheet" href="css/normalize.css">

        <!-- <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/js/bootstrap.bundle.min.js"> -->
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/boxicons@latest/css/boxicons.min.css">

        <script src="js/vendor/modernizr-2.8.3.min.js"></script>
        <script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script>
        <script src='https://cdnjs.cloudflare.com/ajax/libs/jquery-mousewheel/3.1.12/jquery.mousewheel.js'></script>
        <script src='https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.js'></script>
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Titillium+Web&family=Ubuntu:wght@300&display=swap" rel="stylesheet">
        <!-- <link rel="stylesheet" href="css/bootstrap.min.css"> -->

        <link rel="stylesheet" href="css/style.css">


        <style>
            *{
                font-family: 'Titillium Web', sans-serif;
                font-weight:bolder;

            }
            #logout:hover {
                cursor: pointer;
            }
            
        </style>





    </head>
    <style>

        ::-webkit-scrollbar {
            width: 12px;
        }

        /* Track */
        ::-webkit-scrollbar-track {
            background:#333;
        }

        /* Handle */
        ::-webkit-scrollbar-thumb {
            border-radius: 10px;
            background-image:linear-gradient(115deg,#25304e 1%,#010c24);
        }

        .icon {
            width: 50px;
            height: 50px;
            background-color: #eee;
            border-radius: 15px;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 39px;
            color:blue;
        }

        


        h6 {
            font-size: 20px;
        }

        .progress {
            height: 10px;
            border-radius: 10px
        }

        .progress div {
            background-color: red
        }

        .text1 {
            font-size: 14px;
            font-weight: 600
        }

        .text2 {
            color: #a5aec0
        }

        input[type=submit] {
            position: relative;
            float: right;
        }

        .main {
            margin: -5% auto;
            width: 100vw;
        }

        #cont {
            width: 100%;
        }

        #right {
            width: 40%;
            float: right;
            margin: 0 -18%;
        }

        #left {
            width: 50%;
            float: left;
        }

        #submitButton {
            padding: 10px 20px 11px !important;
            font-size: 21px !important;
            background-color: white;
            text-shadow: 1px 1px #F36C8C;
            color: green;
            border-radius: 100px;
            -moz-border-radius: 100px;
            -webkit-border-radius: 100px;
            border: 1px solid #F36C8C;
            border-radius: 100%;
            cursor: pointer;
            box-shadow: 0 1px 0 rgba(255, 255, 255, 0.5) inset;
            -moz-box-shadow: 0 1px 0 rgba(255, 255, 255, 0.5) inset;
            -webkit-box-shadow: 0 1px 0 rgba(255, 255, 255, 0.5) inset;
            float: right;
            margin-top: -5%;
        }

        .circle-wrapper {
            width: 100px;
            height: 100px;
            float: left;
            margin: -10% 20%;
        }

        .circle {
            display: block;
            width: 50px;
            height: 50px;
            border-radius: 50%;
            padding: 2.5px;
            background-clip: content-box;
            background-color: transparent;
            z-index: 1;
            animation: spin 10s linear infinite;
        }
        .circle:hover{
            animation: spin 3s linear infinite;
        }

        .circle-wrapper:active .circle {
            /* animation: spin 2s linear infinite; */
        }

        #runner{
            color:#c6ffea;
        }
        .success {
            border: 2.5px dashed #c6ffea;
        }


        @keyframes spin {
            100% {
                transform: rotateZ(360deg);
            }
        }

        #bb #val {
            position: absolute;
            bottom: 0%;
            right: 0%; 
            padding: 20px;

        }

        #runner {
            transform: translate(190%, 230%);

        }

        fieldset {
            border-radius: 10px;
            height: 130px;
            margin: 2vh auto;
            background-image:linear-gradient(115deg,#25304e 1%,#010c24);
            color: white;
            box-shadow: 3px 4px 10px #101010;
        }
        

        @media only screen and (max-width: 700px) {
            #right {
                width: 40%;
                float: right;
                margin: 0 -12%;
            }
        }

        #sc {
            font-size: large;
            font-weight: normal;
        }


        .score{
            font-size:50px;
            text-align: center;
            color:#c6ffea ;
            font-family: 'Titillium Web', sans-serif;
            
        }
    </style>

<body>
        <video  autoplay muted loop poster id="myVideo">
            <source src="vd1.mp4" type="video/mp4">
        </video>
        <nav class="navbar navbar-inverse" style="overflow: hidden;

        position: fixed;
        top: 0;
        background-image:linear-gradient(115deg,#25304e 1%,#010c24);
        width: 100%;
        z-index:10;
        border:none;border-radius:0%;">
            <div class="container-fluid" style="height:100% ;">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="#"> 
                        <img src="assets/logo-geekswhite.png" height="35px" style="margin-top:-7px;" width="55px">
                    </a>
                </div>
                <div class="collapse navbar-collapse" id="myNavbar">
                    <ul class="nav navbar-nav">
                        <li class="active" ><a style="background-color: #25304e;"  href="index.php" >Problem list</a></li>
                    </ul>
                    <ul class="nav navbar-nav navbar-right">
                        <li><a><span id="demo"></span></a></li>
                        <li id="logout"><a><span class="glyphicon glyphicon-log-out"></span>Logout</a></li>
                    </ul>
                </div>
            </div>
        </nav>
        <br><br><br><br><br>
        <?php 
            echo "<h1 style='color:#c6ffea;text-align:center; margin: -1em auto 1.5em auto;font-size:4em; font-family: Titillium Web, sans-serif;' >Our Supporters</h1>";
        ?>
        <div  class="main">
            <?php echo require "./slideForSponsoros.php"?>
            
            <div class="row log" style="margin: 55vh auto 2vh; ">
                <div class="col-sm-3" >
                
                </div>

                <?php
                    require './config.php';
                    $somme= 0;
                    $identifient = $_SESSION['id_team'];
                                $sql = "SELECT * FROM score where id_team = '" . $identifient . "';";
                                foreach ($conn->query($sql) as $row) {
                                    for ($i=1; $i <50 ; $i++) { 
                                        error_log($row['prob' . $i]);
                                        $somme+=$row['prob' . $i];
                                    }
                                    
                                }
                ?>
                <div class="col-sm-6">
                <h2 class="score" >Global Score :</h2>
                <h2 class="score"><?php echo $somme; ?></h2>
            </div>

                <div class="col-sm-4">

                </div>

            </div>
            <br>

            <!-- <div style="margin: 12% auto;">
                        <h1 style="text-align:center; margin-bottom: -12%; margin-top: -10%;">Problems</h1>
            </div>
            <hr> -->
            <div class="container mt-5 mb-3">
                <div class="row">
                    <?php
                    $level = ["easy" => "mailchimp", "medium" => "dribbble", "hard" => "reddit"];
                    foreach ($level as $key => $value) {
                        echo "<div class='col-md-4'>
                        <div class='card p-3 mb-2'>
                            <div class='d-flex justify-content-between'>
                                <div class='d-flex flex-row align-items-center'>
                                    <div class='ms-2 c-details'>";
                                    if($key == "easy")
                                    echo "<h2 style='text-align: center;color:#00e37b; font-size:26px; letter-spacing:3px; font-weight:bold;' class='mb-0'>Easy</h2>";
                                    if($key == "medium")
                                    echo "<h2 style='text-align: center;color:#ff9c54;font-size:26px; letter-spacing:3px; font-weight:bold;' class='mb-0'>Medium</h2>";
                                    if($key == "hard")
                                    echo "<h2 style='text-align: center;color:#ff5959;font-size:26px; font-weight:bold; letter-spacing:3px;' class='mb-0'>Hard</h2>";
                                echo "</div>
                            </div>
                            </div>";

                        for ($i = 1; $i <= 50; $i++) {
                            if (file_exists("problems/prob" . $i . "/prob" . $i ." ".$key.".html")) {

                                echo "<form action=\"code.php\" method=\"post\"><fieldset style='border: none';>";
                                echo "<input type=hidden name=\"file_name\" value= 'prob$i $key.html'>";
                                echo "<div class='mt-5'>
                            <h3 style=''>";

                                echo file_get_contents("problems/prob" . $i . "/titre.txt");
                            
                            echo "</h3>
                            <div id='cont'>
                            <div id='left' >
                                <p id='sc'>Score : <span id=\"score\">";
                            $identifient = $_SESSION['id_team'];
                            $sql = "SELECT prob" . $i . " FROM score where id_team = '" . $identifient . "';";
                            foreach ($conn->query($sql) as $row) {
                                echo $row['prob' . $i];
                            }
                            echo " point</span></p>
                            </div>
                            <div id='right'>
                            <div class=\"circle-wrapper\">
                        <label id=\"val\">
                        <i  id=\"runner\"class=\"fa fa-play\"></i>
                        <button type=\"submit\" id='bb' name=\"problem\" class=\"success circle\"></button>
                        </label>
                    </div>
                                </div>
                            </div>
                            
                        </div>";

                                echo "</fieldset></form>";
                            }
                        }
                        echo "</div>
                    </div>";
                    }
                    ?>



                </div>
            </div>

            <div class="col-sm-3">

            </div>
        </div>
        </div>
        </div>
        <br>
        <div class="area">
            <div class="well foot" style="background-color: #010716;;border:none;opacity:95%;width:100vw;">
                <div class="row area">
                    <div class="col-sm-3" style="margin-left:3em ;">
                        <h2 style="text-align: start;">ENSIT Geeks Club</h2>
                        <p style="text-align: start;">Contact : 43 308 524</p>
                        <p style="text-align: start;">Email : contact@ensitgeeksclub.com</p>
                    </div>
                    <div class="col-sm-5"> 
                        <div class="fm">
                        </div>
                    </div>
                    <div class="col-sm-3">
                        <div class="col-sm-3">
                            <img src="./assets/logo-geekswhite.png" style="margin-right: -28em;height: 15vh;margin-top: 0.5em;">
                        </div>
                    </div>
                </div>
            </div>
        </div>
        

        <script>
            /**************************** */

	// Set the date we're counting down to
	// 1. JavaScript
	// var countDownDate = new Date("Sep 5, 2018 15:37:25").getTime();
	// 2. PHP
	var countDownDate = <?php require 'params.php'; echo strtotime($finish) ?> * 1000;
	// console.log(new Date(countDownDate));
	var now = <?php echo time() ?> * 1000;
	let distance = 1,
		days = 1,
		hours = 1,
		minutes = 1,
		seconds = 50;
	// Update the count down every 1 second
	var x = setInterval(function() {

		// Get todays date and time
		// 1. JavaScript
		// var now = new Date().getTime();
		// 2. PHP
		now = now + 1000;

		// Find the distance between now an the count down date
		distance = countDownDate - now;

		// Time calculations for days, hours, minutes and seconds
		days = Math.floor(distance / (1000 * 60 * 60 * 24));
		hours = Math.floor(distance / (1000 * 60 * 60 ) );
		// hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
		minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
		seconds = Math.floor((distance % (1000 * 60)) / 1000);

		// Output the result in an element with id="demo"
		document.getElementById("demo").innerHTML = hours + ":" +
			minutes + ":" + seconds + " ";

		// If the count down is over, write some text 
		if (distance <= 0) {
			clearInterval(x);
			document.getElementById("demo").innerHTML = "Redirection ...";
			//let add = '<?php echo $add; ?>';
            add="http://localhost/geekshack-main";
			window.location.href = add + '/hack_over.php';
		}
	}, 1000);
        </script>
        
        <script>
        $(document).ready(function() {
            $('#logout').click(function() {
			

			$.ajax({
				url: 'out.php',
				method: "POST",
				data: {
				},
				beforeSend: function() {

					
				},

				complete: function() {
					
				},
				success: function(data) {
					console.log("data:",data)
					//data par le contenu de $add
					window.location.href = "http://localhost:8800/geekshack-main/login.php";
					

				}
			})

		});

	});
        </script>
<div >

    </body>

    </html>
<?php
}
// }
?>