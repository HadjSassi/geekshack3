<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
require "config.php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$base", $user, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  } catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
  }

  $coord= json_decode(file_get_contents('php://input'),true);
  $data= [];
  

    try {
        $sql ="SELECT * from candidat where state = 1;";
        
        $i=0;
          foreach  ($conn->query($sql) as $row) {
              $data[$i]['nom']= $row['nom'] ;
              $data[$i]['prenom']= $row['prenom'] ;
              $data[$i]['email']=  $row['email'] ;
              $data[$i]['phone']=  $row['phone'];
              $data[$i]['username']=  $row['username'];
              $data[$i]['ecole']=  $row['ecole'];
              $data[$i]['preuve_etudiant']=  $row['preuve_etudiant'];
              $i++;
          }
          echo json_encode($data);
    } catch (PDOException $e) {
        echo json_encode($e);
    }
?>