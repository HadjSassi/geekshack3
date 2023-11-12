<?php

function authenticate($password) {
    $credentials = json_decode(file_get_contents('credentials.json'), true);
    $algorithm = "sha256"; // You can use other algorithms like sha256, sha512, etc.

    if (isset($credentials['pass']) && hash($algorithm, $password) === $credentials['pass']) {
        // User is an admin with full access
        return array('role' => 'admin', 'authenticated' => true);
    } elseif (isset($credentials['visitorPass']) && $password === $credentials['visitorPass']) {
        // User is a visitor with read-only access
        return array('role' => 'visitor', 'authenticated' => true);
    } else {
        // Authentication failed
        return array('authenticated' => false);
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $password = $_POST['password'];

    $authResult = authenticate($password);

    if ($authResult['authenticated']) {
        // Authentication successful
        session_start();
        $_SESSION['authenticated'] = true;
        $_SESSION['role'] = $authResult['role'];

        header('Location: index.php');
        exit();
    } else {
        // Authentication failed, redirect to an error page or display an error message
        header('Location: login.php?error=1');
        exit();
    }
}

?>
