<?php
$servername = "localhost";
$username = "root";
$password = "Abderrazek/0";
$dbname = "geekshack";
try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
				$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
  }
  //avoir le nombre d'equipe
  $sql="select count(*) from team ;";	
	$pre=$conn->prepare($sql);
  $pre->execute();
  $res=$pre->fetchAll();
  $numberOfTeam=$res[0][0];

?>
