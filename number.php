<?php

header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
header("Content-type: application/json;charset=utf8");

$host = "localhost";
$db = "geekshack3";
$user = "root";
$password = "geeks_hack_2023";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db;charset=UTF8", $user, $password, array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$s3 = 0;

$sql = "SELECT count(*)-1 as number from team;";
foreach ($conn->query($sql) as $row) {
    $s3 = $row["number"];

}

if ($s3 < 25) {
    echo 0;
} else {
    echo 1;
}


?>
