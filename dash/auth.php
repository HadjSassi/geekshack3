<?php

function authenticate($password) {
    $credentials = json_decode(file_get_contents('credentials.json'), true);
    $algorithm = "sha256"; // You can use other algorithms like sha256, sha512, etc.
    $hash = hash($algorithm, $password);
    return isset($credentials['pass']) && $credentials['pass'] === $hash;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $password = $_POST['password'];

    if (authenticate($password)) {
        // Authentication successful, redirect to the dashboard page
        session_start();
        $_SESSION['authenticated'] = true;
        header('Location: index.php');
        exit();
    } else {
        // Authentication failed, redirect to an error page or display an error message
        header('Location: login.php?error=1');
        exit();
    }
}

?>
