<?php
// update_score.php

$score = $_POST['score'];
$tag = $_POST['tag'];
$prob = $_POST['prob'];
$idteam = $_POST['idteam'];

$link = mysqli_connect('51.38.112.160', 'root', 'geeks_hack_2023', 'geekshack3');

// Update the score in the database
$sql = "UPDATE score SET prob$prob = $score WHERE id_team = $idteam";

if (mysqli_query($link, $sql)) {
    echo "Score updated successfully.";
} else {
    echo "Error updating score: " . mysqli_error($link);
}

mysqli_close($link);
?>
