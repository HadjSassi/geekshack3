<?php
session_start();
/*if (isset($_POST['ID']) && isset($_POST['PASS'])) {
	$_SESSION['ID'] = $_POST['ID'];
	$_SESSION['PASS'] = $_POST['PASS'];
}*/
require 'serverAdd.php';
require 'config.php';

if (!(isset($_SESSION['ID'])))
// badalet add bel valeur mta3o bech ntesti 
	echo " <script>window.location.href = http://https://geekshack.ensitgeeksclub.com//login.php';</script> ";


else {
	$id = $_SESSION['ID'];

	/*$s=exec("if [ -d ".$id." ]; then
        	cd $id;
			pwd;
        else
            mkdir $id;
            cd $id;
			pwd;
        fi
        ");*/


?>


	<!DOCTYPE html>
	<html style="height: 100%;">

	<head>

		<meta charset="utf-8">
		<title>Code</title>
		<meta name="description" content="">
		<link rel="icon" href="assets/logo-geeks.png" />
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
		<style>
			*{
                /* font-family: 'Titillium Web', sans-serif; */

            }
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

		#logout:hover{
                cursor: pointer;
            }
			#bar {
				list-style-type: none;
				margin: 0;
				padding: 0;
				overflow: hidden;
				border: 1px solid #e7e7e7;
				background-color: #f3f3f3;
			}

			#run_item {
				float: left;
			}

			#run_item input {
				display: block;
				color: white;
				text-align: center;

				text-decoration: none;
			}

			#run_item input:hover:not(.active) {
				background-color: #cdcdcd;
			}

			.active {
				background-color: #4CAF50;
			}

			.table {
				width: 100%;
				height: 90%;
			}


			.scrollbar {
				float: left;
				height: 100px;
				overflow-y: scroll;
				width: 100%;
				margin-top: -20px;
			}

			#scroll::-webkit-scrollbar-track {
				-webkit-box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				border-radius: 10px;
				background-color: #F5F5F5;
			}

			#scroll::-webkit-scrollbar {
				background-color: #F5F5F5;
				width: 7px
			}

			#scroll::-webkit-scrollbar-thumb {
				border-radius: 10px;
				-webkit-box-shadow: inset 0 0 6px rgba(0, 0, 0, .3);
				box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				background-color: #555;

			}

			tr {
				background-color: #EEEEEE;
				height: 30px;
				font-size: 16px;
			}

			.droit-scrollbar {
				float: left;
				height: 100%;
				overflow-y: scroll;
				width: 100%;
			}

			#droit-scroll::-webkit-scrollbar-track {
				-webkit-box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				border-radius: 10px;
				background-color: #F5F5F5;
			}

			#droit-scroll::-webkit-scrollbar {
				background-color: #F5F5F5;
				width: 7px
			}

			#droit-scroll::-webkit-scrollbar-thumb {
				border-radius: 10px;
				-webkit-box-shadow: inset 0 0 6px rgba(0, 0, 0, .3);
				box-shadow: inset 0 0 6px rgba(0, 0, 0, 0.3);
				background-color: #555;

			}
			
		</style>
		
		<link rel="stylesheet" href="css/font-awesome.min.css">

		<link rel="stylesheet" href="css/normalize.css">
		<!-- 
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css"> -->
		<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/js/bootstrap.bundle.min.js"></script>
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/boxicons@latest/css/boxicons.min.css">

		<script src="js/vendor/modernizr-2.8.3.min.js"></script>

		<script src="js/vendor/modernizr-2.8.3.min.js"></script>
		<script src="js/vendor/jquery-1.12.0.min.js"></script>
		<script src="js2/myScript.js"></script>
		<!-- <script src="bootstrap-3.3.7/js/bootstrap.min.js"></script>
		<script src="bootstrap-3.3.7/js/bootstrap.js"></script>
		<link rel="stylesheet" href="css/bootstrap.min.css"> -->
		<meta charset='utf-8'>
		<meta http-equiv='X-UA-Compatible' content='IE=edge'>
		<script src="https://kit.fontawesome.com/ed9dc6a116.js"> </script>
		<meta name='viewport' content='width=device-width, initial-scale=1'>
		<link href="https://fonts.googleapis.com/css2?family=Dongle:wght@300&family=Marvel&family=Rubik+Mono+One&family=Tenali+Ramakrishna&family=Thasadith:ital@1&display=swap" rel="stylesheet">
		<!-- <link rel='stylesheet' type='text/css' media='screen' href='problems/prob4/style.css'> -->

		<link rel="stylesheet" href="css/style.css">
		<style>
			.gutter {
				background-color: #eee;
				background-repeat: no-repeat;
				background-position: 50%;

			}

			.gutter.gutter-horizontal {
				background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAeCAYAAADkftS9AAAAIklEQVQoU2M4c+bMfxAGAgYYmwGrIIiDjrELjpo5aiZeMwF+yNnOs5KSvgAAAABJRU5ErkJggg==');
				cursor: col-resize;
			}

			.gutter.gutter-vertical {
				background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAB4AAAAFAQMAAABo7865AAAABlBMVEVHcEzMzMzyAv2sAAAAAXRSTlMAQObYZgAAABBJREFUeF5jOAMEEAIEEFwAn3kMwcB6I2AAAAAASUVORK5CYII=');
				cursor: row-resize;
			}

			#content {
				display: flex;
				flex-direction: row;
				height: 90%;
			}

			#gauche {
				flex-grow: 1;
				flex-shrink: 0;
				flex-basis: 50%;
			}


			#droit {
				height: 95%;
				padding-right: 1%;
				padding-left: 2%;
			}

			.loader {
				border: 16px solid #f3f3f3;
				/* Light grey */
				border-top: 16px solid #3498db;
				/* Blue */
				border-radius: 50%;
				width: 120px;
				height: 120px;
				animation: spin 2s linear infinite;
				margin: 0 auto;
			}

			@keyframes spin {
				0% {
					transform: rotate(0deg);
				}

				100% {
					transform: rotate(360deg);
				}
			}

			pre {
				border: 0;
				background-color: #ddd
			}

			.bt {
				background-color: red;
				/* Blue background */
				border: none;
				/* Remove borders */
				color: white;
				/* White text */
				padding: 12px 16px;
				/* Some padding */
				font-size: 16px;
				/* Set a font size */
				cursor: pointer;
				/* Mouse pointer on hover */
			}

			/* Darker background on mouse-over */
			.bt:hover {
				background-color: RoyalBlue;
			}
		</style>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
		<!-- <script  src="scripts/require.js"></script> -->
		<style>
			pre {
				border: 0;
				background-color: transparent;
			}
		</style>
	</head>

	<body style="height: 100% ;background:#010c24">
		
	
	
	<!-- <nav class="navbar navbar-expand-lg navbar-dark bg-dark" style="width: 100%;height: 10%;">

			<img src="./assets/logo-geeks.png" width="70" height="40" alt="">

			<a class="navbar-brand" style="margin-top: 0.2%;" href="#">ENSIT Geeks Club</a>

			<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarText" aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>
			<div class="collapse navbar-collapse" style="width: 100%;" id="navbarText">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item">
						<a class="nav-link" style="margin-top: 6%;" href="index.php">Problem List </a>
					</li>
				</ul>
				<span class="navbar-text" style="float:right">
				<span id="demo"></span>
				<button class="bt"><i class="fa fa-sign-out"></i></button>
				</span>
			</div>
		</nav> -->



		<nav class="navbar navbar-inverse" style="border-radius:0;background-image:linear-gradient(115deg,#25304e 1%,#010c24);border:none;">
			<div class="container-fluid">
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
		<div class="main" style="width: 100%;margin:-2em auto;height:100%; padding:2em 0; background:#010c24;">

		<div id='content'>
			<div id="gauche" style="margin-left: 1%;float:left;width: 45%; height:100%">

				<div class="col-sm-8" style="width: 100%; height: 100%;">
					<div class="form-group" style="width: 100%;">

						<!--form action="compile.php" id="form" name="f2" method="POST" target="_blank" onsubmit="return getText()"-->
						<label for="lang" style="color: white;">Choose Language</label>

						<select class="form-control" id="codetype" onchange=val() name="language">
							<option value="Select" disabled selected>Select Your langage</option>
							<option value="c">C</option>
							<option value="cpp11">C++</option>
							<option value="java">Java</option>
							<option value="python3.2">Python3</option>

						</select>
						<ul id="bar" style="width : 100% ; background-image:linear-gradient(115deg,#25304e 1%,#010c24);border:none;color:white; margin:10px auto; padding:0.5px auto;">
							<li id="run_item" style="height:2.5em ;">
							<?php
								// $sql="select ".$_SESSION["namep"]." from score where id_team=".$_SESSION["id_team"]."";	
								//echo $sql."<br>";
								// $pre=$conn->prepare($sql);
							  	// $pre->execute();
							  	// $res=$pre->fetchAll();
								// echo ;
							  	// $scoreProblemes=floatval($res[0][0]);
								// if($scoreProblemes>60)
								echo '<input type="submit" id="run" class="btn" style="float:height:1em; left;transform: rotate(90deg); background:#010c24; color:white;" value="▲">';
								// else
								// echo '<input disabled type="submit" id="run" class="btn" style="float:height:1em; left;transform: rotate(90deg); background:#010c24; color:white;" value="▲">';

								?>
								</li>
							<li id="run_item" style="float:right; transform: translateY(50%);">Your score in this problem : <b id="score"></b></li>
						</ul>
						<label for="ta" style="margin-top : 20px;color:white;">Write Your Code</label>
						<div style="height:40vh" id="editor"></div>

						<script src="js2/ace.js" type="text/javascript">
						</script>
						<script>
							
							var editor = ace.edit("editor");
							function getText() {
								var forms = document.getElementById('form');
								var x = document.createElement("input");
								//var t = document.createTextNode(editor.getSession().getValue());
								//x.appendChild(t);
								x.name = "code";
								x.type = "hidden";
								x.value = editor.getSession().getValue();
								console.log(editor.getSession().getValue());
								forms.appendChild(x);
								//document.getElementById('code').value = editor.getSession().getValue();
								//alert(x.value);
								return true;
							}
						</script>
					</div>
					<div class="loader"></div>
					<div id="result" style="height: 30%;">
					</div>
				</div>


			</div>
			<div id="droit">
				<div class='droit-scrollbar' id='droit-scroll'>
					<?php
					exec("cd $id");
					$name = "";
					if (isset($_POST['problem'])) {
						$name = $_POST['file_name'];
						$piece = explode(".", $name);
						$base_name = explode(" ", $piece[0]);
						$pn = $base_name[0];
						$niveau = $base_name[1];
						$_SESSION['niveau'] = $niveau;
						$_SESSION['namep'] = $pn;
						require "problems/" . $pn . "/" . $name;

						/*****************         Autre Methode         ***************/
						/*
							$contenu = file_get_contents("problems/".$pn."/".$name);
							echo $contenu;
						*/
						/*****************-------------------------------***************/
						$ch = shell_exec("cd scode/$id;
						if [ -d " . $pn . " ]; then cd $pn; else mkdir $pn; chmod 777 $pn; cd $pn; fi;");
						//$sh= shell_exec("pwd");
					}

					?>

				</div>
			</div>

			<!-- </div> -->
	</body>

	</html>
<?php

}
?>
<script src="https://unpkg.com/split.js/dist/split.min.js"></script>
<script>
	Split(['#gauche', '#droit'], {
		gutterSize: 10,
		sizes: [20, 80],

	});
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
					window.location.href = "https://https://geekshack.ensitgeeksclub.com//login.php";
					

				}
			})

		});
		var editor = ace.edit("editor");

		editor.setOptions({
			fontSize: "10pt"
		});

		// hide loader spinner
		$('.loader').hide();

		var id_team = '<?php echo $_SESSION['id_team']; ?>'
		var namep = '<?php echo   $_SESSION["namep"]; ?>';
		$.ajax({
			url: 'score.php',
			method: 'POST',
			data: {
				id_team: id_team,
				namep: namep
			},
			success: function(data) {
				console.log(data);
				$("#score").html(parseInt(data))
			}
		})
		$('#run').click(function() {
			if ($(".table").length) {
				$(".col-sm-12").remove();
				$("#result").html("<div class=\"loader\"></div>")
			}
			var editor = ace.edit("editor");
			var code = editor.getSession().getValue();
			var user = '<?php echo $_SESSION["ID"]; ?>';
			var namep = '<?php echo $_SESSION["namep"]; ?>';
			var language = $("#codetype").val();
			var id_team = '<?php echo $_SESSION['id_team']; ?>';

			$.ajax({
				url: 'compile.php',
				method: "POST",
				data: {
					code: code,
					user: user,
					namep: namep,
					language: language
				},
				beforeSend: function() {
					$("#result").hide();
					$(".loader").show();
				},

				complete: function() {
					$('.loader').hide();
					$("#result").show();

				},
				success: function(data) {
					//console.log(data);
					$("#result").html(data)
					$.ajax({
						url: 'score.php',
						method: 'POST',
						data: {
							id_team: id_team,
							namep: namep
						},
						success: function(data) {
							$("#score").html(parseInt(data))
						}
					})

				},
	
				error: function (xhr, status, err){
					
					$("#result").html(xhr.responseText);
					$.ajax({
						url: 'score.php',
						method: 'POST',
						data: {
							id_team: id_team,
							namep: namep
						},
						success: function(data) {
							$("#score").html(data)
						},
						error: function (xhr, status, err){
							$("#score").html(xhr.responseText);
						
						}
						
					})
					
				},
			})

		})
		$('#codetype').change(function() {
			var editor = ace.edit("editor"); ///---->   HEYY SYRINE : here the declaration of ace variable
			var user = '<?php echo $_SESSION["ID"]; ?>';
			var namep = '<?php echo $_SESSION["namep"]; ?>';
			var code_type = $(this).val();
			$.ajax({
				url: "load_code_editor.php",
				method: "POST",
				data: {
					user: user,
					namep: namep,
					code_type: code_type,
				},
				success: function(data) {

					editor.getSession().setValue(data); ///---->   HEYY SYRINE : this how we set the default value of ace editor

				}
			});
		});
	});

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
		hours = Math.floor(distance / (1000 * 60 * 60));
		// hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
		minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
		seconds = Math.floor((distance % (1000 * 60)) / 1000);

		// Output the result in an element with id="demo"
		document.getElementById("demo").innerHTML = hours + ": " +
			minutes + ": " + seconds + "s ";

		// If the count down is over, write some text 
		if (distance <= 0) {
			clearInterval(x);
			document.getElementById("demo").innerHTML = "Redirection ...";
			// let add = <?php echo $add; ?>;
			let add="https://geekshack.ensitgeeksclub.com"
			console.log(add)
			window.location.href = add + '/hack_over.php';
			console.log(add);
		}
	}, 1000);
	/***************************** */
</script>
