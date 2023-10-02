<?php

header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
header("Content-type: application/json;charset=utf8");

$s="";

 $host="localhost";
 $db="tsutnnytsu";
    $user="root";
    $password="Magali_1984";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db;charset=UTF8", $user, $password,array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$cord= json_decode(file_get_contents('php://input'), true);

//$_POST['team_tag']=str_replace(["'","\"","`","/","\\"],' ', $_POST["team_tag"]);

    $check= "select team_tag from team where team_tag ='".$_POST['team_tag']."';";
    
   foreach ($conn->query  ($check) as $row){
     $s=$row["team_tag"];   }
     
     if($s=="") {
          echo "Valid Tag";
          http_response_code(200);
       
    }
    if(strlen($s)!=0) {
    		echo "Not Valid Tag";
          http_response_code(203);
          } 
 ?>
