<?php

    session_start();
    session_destroy();
    require 'serverAdd.php';
    echo $add;
?>