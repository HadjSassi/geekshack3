<?php

header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
header("Content-type: application/json;charset=utf8");

$s="";
$s1="";
$s2="";
$s3="";

 $host="localhost";
 $db="geekshack";
    $user="root";
    $password="geeksgeeks";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db;charset=UTF8", $user, $password,array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$cord= json_decode(file_get_contents('php://input'), true);

//$_POST['team_tag']=str_replace(["'","\"","`","/","\\"],' ', $_POST["team_tag"]);

    $check= "select leader_username, member_one_username, member_two_username from team where leader_username ='".$_POST['username']."' 
    or member_one_username ='".$_POST['username']."' 
    or member_two_username ='".$_POST['username']."' 
    ;";
    
   foreach ($conn->query  ($check) as $row){
     $s=$row["leader_username"]; 
     $s1=$row["member_one_username"];
     $s2=$row["member_two_username"];   
    
    }

    $sql= "select username from candidat where username ='".$_POST['username']."' and state = 1;'";
 foreach ($conn->query  ($sql) as $row){
     $s3=$row["username"]; 
       
    }
     
    $s4="";
    $sql2= "select username from candidat where username ='".$_POST['username']."';'";
 foreach ($conn->query  ($sql2) as $row){
     $s4=$row["username"]; 
       
    }

    if(strlen($s)==0 && strlen($s1)==0 && strlen($s2)==0 && strlen($s4)==0) {
        echo "This username does not exist !";
            http_response_code(203);
       
    }else{
        if(strlen($s)==0 && strlen($s1)==0 && strlen($s2)==0 && strlen($s3)!=0) {
            echo "Valid username";
            http_response_code(200);
            
        }
        
        if(strlen($s)==0 && strlen($s1)==0 && strlen($s2)==0 && strlen($s3)==0) {
            echo "This username is not approved yet !";
                http_response_code(203);
        
        }
    

        if(strlen($s)!=0 || strlen($s1)!=0 || strlen($s2)!=0  ) {
                echo "This username exists in another team !";
            http_response_code(203);
            } 
    }
?>
