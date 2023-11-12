<?php
// update_score.php

$tag = $_POST['tag'];

$link = mysqli_connect('localhost', 'root', 'geeks_hack_2023', 'geekshack3');

// Update the score in the database
$sql = "UPDATE team SET state = 1 WHERE team_tag = '$tag'";

if (mysqli_query($link, $sql)) {
    echo "Score updated successfully.";
} else {
    echo "Error updating score: " . mysqli_error($link);
}

mysqli_close($link);
header('Location: https://geekshack.ensitgeeksclub.com/dash');
exit;
?>
