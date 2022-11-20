<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
require "config.php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$base", $user, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$coord = json_decode(file_get_contents('php://input'), true);
$data = [];


try {
    $sql = "SELECT * from team where state = 0;";

    $i = 0;
    foreach ($conn->query($sql) as $row) {
        $data[$i]['id_team'] = $row['id_team'];
        $data[$i]['team_tag'] = $row['team_tag'];
        $data[$i]['leader_username'] =  $row['leader_username'];
        $data[$i]['member_one_username'] =  $row['member_one_username'];
        $data[$i]['member_two_username'] =  $row['member_two_username'];
        $data[$i]['preuve'] =  $row['preuve'];

        $s = "SELECT email from candidat where username = '" . $data[$i]['leader_username'] . "';";
        foreach ($conn->query($s) as $r) {

            $data[$i]['email']['leader'] = $r['email'];
        }
        $a = "SELECT nom, prenom from candidat where username = '" . $data[$i]['leader_username'] . "';";
        foreach ($conn->query($a) as $r) {

            $data[$i]['leader_full_name'] = $r['nom'] . " " . $r['prenom'];
        }
        if ($data[$i]['member_one_username'] != null) {
            $q = "SELECT email from candidat where username = '" . $data[$i]['member_one_username'] . "';";
            foreach ($conn->query($q) as $r) {

                $data[$i]['email']['member_one'] = $r['email'];
            }

            $c = "SELECT nom, prenom from candidat where username = '" . $data[$i]['member_one_username'] . "';";
            foreach ($conn->query($c) as $r) {

                $data[$i]['member_one_name'] = $r['nom'] . " " . $r['prenom'];
            }
        }

        if ($data[$i]['member_two_username'] != null) {
            $a = "SELECT email from candidat where username = '" . $data[$i]['member_two_username'] . "';";
            foreach ($conn->query($a) as $r) {

                $data[$i]['email']['member_two'] = $r['email'];
            }

            $c = "SELECT nom, prenom from candidat where username = '" . $data[$i]['member_two_username'] . "';";
            foreach ($conn->query($c) as $r) {

                $data[$i]['member_two_name'] = $r['nom'] . " " . $r['prenom'];
            }
        }

        $i++;
    }
    echo json_encode($data);
} catch (PDOException $e) {
    echo json_encode($e);
}
