<?php

    require 'serverAdd.php';
    session_start();
    session_destroy();
    
    $host="localhost";
    $user="root";
    $password="";
    $base = "geekshack";
try {
    $conn = new PDO("mysql:host=$host;dbname=$base", $user, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
$up = "UPDATE team SET state = 0;";
            $stm = $conn->prepare($up);

            // execute the query
            $stm->execute();
//badalet add bel valeur bech najem  ntassti w mayhznich ll geekshacktn
    echo " <script>window.location.href ='http://localhost:8800/geekshack-main/login.php';</script> ";
?>
