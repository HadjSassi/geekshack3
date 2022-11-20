<?php 

	require 'serverAdd.php';
	$timestamp = time();
	$today = date("M j, Y H:i:s",$timestamp);
	require 'params.php';
	$date = $start;
	echo " <script>console.log('start = $date');</script> ";
	echo " <script>console.log('today = $today');</script> ";
	// session_start();

	if($today<$date){
		echo " <script>window.location.href = '".$add."/countDown.php';</script> ";
		echo " <script>console.log('start = $date');</script> ";
		echo " <script>console.log('today = $today');</script> ";
	}
	else {
	if ( empty(session_id()) ){
		session_start();
	} 
?>
<html lang="en">
<head>
	<title>Login</title>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
<!--===============================================================================================-->	
<link rel="icon" href="assets/logo-geeks.png" />
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
  background-color: rgb(0,0,0); /* Fallback color */
  background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
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
  float: right ;
  font-size: 28px;
  font-weight: bold;
}
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
			<video  autoplay muted loop poster id="myVideo">
    			<source src="vd1.mp4" type="video/mp4">
        	</video>
			<div class="wrap-login100 p-l-85 p-r-85 p-t-55 p-b-55" style="opacity:95%;background-image:linear-gradient(115deg,#25304e 1%,#010c24);">
				<form class="login100-form validate-form flex-sb flex-w" method="POST">
					<span class="login100-form-title p-b-32" style="color:white;">
						Account Login
					</span>

					<span class="txt1 p-b-11" style="color:white;">
						Team login
					</span>
					<div class="wrap-input100 validate-input m-b-36" data-validate = "Login is required">
						<input class="input100" type="text" name="ID" >
						<span class="focus-input100"></span>
					</div>
					
					<span class="txt1 p-b-11" style="color:white;">
						Password
					</span>
					<div class="wrap-input100 validate-input m-b-12" data-validate = "Password is required">
						<span class="btn-show-pass">
							<i class="fa fa-eye"></i>
						</span>
						<input class="input100" type="password" name="PASS" >
						<span class="focus-input100"></span>
					</div>
					
					<!--div class="flex-sb-m w-full p-b-48">
						<div class="contact100-form-checkbox">
							<input class="input-checkbox100" id="ckb1" type="checkbox" name="remember-me">
							<label class="label-checkbox100" for="ckb1">
								Remember me
							</label>
						</div>

						<div>
							<a href="#" class="txt3">
								Forgot Password?
							</a>
						</div>
					</div-->

					<div class="container-login100-form-btn">
						<button id="btn" class="login100-form-btn" style="background-image:linear-gradient(115deg,#25304e 1%,#010c24); box-shadow:2px 2px 5px #000000;">
							Login
						</button>
					</div>

				</form>
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
		if (isset($_POST['ID']) && isset($_POST['PASS']))
		{
			require './config.php';
			try {
				
				$sql = "SELECT id_team, login, team_tag FROM team where state =1 and password = '".$_POST['PASS']."';";

				function exists($conn,$sql){
					$founded=false;
					foreach  ($conn->query($sql) as $row) {
						if ($row['team_tag'] == $_POST['ID'] || $row['login'] == $_POST['ID'] ){
							$founded=true;
							$_SESSION['ID'] = $row['team_tag'];
							$_SESSION['id_team'] = $row['id_team'];
							require 'serverAdd.php';
							echo " <script>window.location.href = '".$add."/index.php';</script> ";
							
						}
					}
					return $founded;
				}
					
					if (exists($conn,$sql) == false){
?>
						
						<script>
							function getModal (){
							// Get the modal
							var modal = document.getElementById("myModal");


							// Get the <span> element that closes the modal
							var span = document.getElementsByClassName("close")[0];

							// When the user clicks on the button, open the modal
							
							modal.style.display = "block";
							

							// When the user clicks on <span> (x), close the modal
							span.onclick = function() {
							modal.style.display = "none";
							}

							// When the user clicks anywhere outside of the modal, close it
							window.onclick = function(event) {
							if (event.target == modal) {
								modal.style.display = "none";
							}
							}
						}
						getModal()
						</script>
						
				<?php 
					 
					}
			  } catch(PDOException $e) {
				echo "<script>console.log('Error: " . $e->getMessage()."')</script>";
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
<?php } ?>
