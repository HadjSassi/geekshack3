<?php
$servername = "localhost";
$username = "root";
$password = "Magali_1984";
$dbname = "tsutnnytsu";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Get the number of teams
    $sql = "SELECT COUNT(*) FROM team";
    $pre = $conn->prepare($sql);
    $pre->execute();
    $res = $pre->fetchColumn(); // Use fetchColumn to get a single value
    $numberOfTeam = $res;

//    echo "Number of teams: " . $numberOfTeam;
} catch (PDOException $e) {
    // Print detailed error message
    echo "Error: " . $e->getMessage();
}
?>
