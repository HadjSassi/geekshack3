<?php

    $id_team = $_POST['id_team'];
    $namep = $_POST['namep'];
    require './config.php';
    
    $sql = "SELECT ".$namep." FROM score where id_team = ".$id_team.";";

    $data = [];
    foreach  ($conn->query($sql) as $row) {
        array_push($data,$row[$namep]);
    }

    echo $data[0];


?>