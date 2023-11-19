<?php
// update_score.php
require "../config.php";
require '../mail.php';
$mailer = new Mailer();
$tag = $_GET['tag'];

$link = mysqli_connect('localhost', 'root', 'geeks_hack_2023', 'geekshack3');

$requete1 = "select * from team where team_tag = '$tag'";
$result1 = mysqli_query($link, $requete1);
$coord = mysqli_fetch_assoc($result1);

// Update the score in the database
$sql = "UPDATE team SET state = 1 WHERE team_tag = '$tag'";

if (mysqli_query($link, $sql)) {
    echo "State updated successfully.";
    $hour = date('H');
    $greeting = "";
    $full_name = "";
    $username = "";
    $email = "";
    $subject = 'GeeksHack Team Confirmation';
    if ($hour > 18 || $hour < 1) {
        $greeting = 'Good Evening';
    } else if ($hour > 12) {
        $greeting = 'Good Afternoon';
    } else {
        $greeting = 'Good Morning';
    }
    $login = $coord['login'];
    $password = $coord['password'];
    $username1 = $coord['leader_username'];
    $username2 = $coord['member_one_username'];
    $username3 = $coord['member_two_username'];
    # member 1
    $requete2 = "select * from candidat where username = '$username1'";
    $result2 = mysqli_query($link, $requete2);
    $row2 = mysqli_fetch_assoc($result2);
    $username = $username1;
    $email = $row2['email'];
    $full_name = $coord['nom'] . ' ' . $coord['prenom'];
    $message = '
         <html>
    <head>
            
            <meta charset="utf-8" />
    </head>
                <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                    <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                        <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                        <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                    </div>
                    <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                        <b>' . $greeting . ' Dear ' . $full_name . ',</b><br><br>
                        <br>  Your Team Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your username : <strong>' . $username . '</strong><br>
                        <br>Your Team Tag : <strong>' . $tag . '</strong><br>
                        <br>Your Login : <strong>' . $login . '</strong><br>
                        <br>Your Password : <strong>' . $password . '</strong><br>
                        
                        <br>Now, you can participate in Geeks Hack 3.0 <a href="https://geekshack.ensitgeeksclub.com">From this Link</a><br>
                        <br>You will need  <strong>Login</strong>  and <strong>Password</strong> to enter the contest.<br>
                          
                        <br>Please don\'t remove this mail, put it in a safe place until the contest is done.<br>
                        <br>Feel free to contact us for any other information.<br>
                             Cordially.<br>
                        
                    </div>
                    <br>
                    <div style="font-size: 11px;text-align: center;color:gray;">
                      [THIS IS AN AUTOMATED MESSAGE .]
                    </div>


                </div>
              </body>  
    </html>
           ';

    $mailed = $mailer->sendMail($email, $subject, $message);

    # member 2

    $requete2 = "select * from candidat where username = '$username2'";
    $result2 = mysqli_query($link, $requete2);
    if ($row2 = mysqli_fetch_assoc($result2)) {
        $username = $username2;
        $email = $row2['email'];
        $full_name = $coord['nom'] . ' ' . $coord['prenom'];
        $message = '
         <html>
    <head>
            
            <meta charset="utf-8" />
    </head>
                <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                    <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                        <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                        <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                    </div>
                    <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                        <b>' . $greeting . ' Dear ' . $full_name . ',</b><br><br>
                        <br>  Your Team Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your username : <strong>' . $username . '</strong><br>
                        <br>Your Team Tag : <strong>' . $tag . '</strong><br>
                        <br>Your Login : <strong>' . $login . '</strong><br>
                        <br>Your Password : <strong>' . $password . '</strong><br>
                        
                        <br>Now, you can participate in Geeks Hack 3.0 <a href="https://geekshack.ensitgeeksclub.com">From this Link</a><br>
                        <br>You will need  <strong>Login</strong>  and <strong>Password</strong> to enter the contest.<br>
                          
                        <br>Please don\'t remove this mail, put it in a safe place until the contest is done.<br>
                        <br>Feel free to contact us for any other information.<br>
                             Cordially.<br>
                        
                    </div>
                    <br>
                    <div style="font-size: 11px;text-align: center;color:gray;">
                      [THIS IS AN AUTOMATED MESSAGE .]
                    </div>


                </div>
              </body>  
    </html>
           ';

        $mailed = $mailer->sendMail($email, $subject, $message);
    }

    # member 3

    $requete2 = "select * from candidat where username = '$username3'";
    $result2 = mysqli_query($link, $requete2);
    if ($row2 = mysqli_fetch_assoc($result2)) {
        $username = $username3;
        $email = $row2['email'];
        $full_name = $coord['nom'] . ' ' . $coord['prenom'];
        $message = '
         <html>
    <head>
            
            <meta charset="utf-8" />
    </head>
                <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                    <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                        <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                        <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                    </div>
                    <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                        <b>' . $greeting . ' Dear ' . $full_name . ',</b><br><br>
                        <br>  Your Team Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your username : <strong>' . $username . '</strong><br>
                        <br>Your Team Tag : <strong>' . $tag . '</strong><br>
                        <br>Your Login : <strong>' . $login . '</strong><br>
                        <br>Your Password : <strong>' . $password . '</strong><br>
                        
                        <br>Now, you can participate in Geeks Hack 3.0 <a href="https://geekshack.ensitgeeksclub.com">From this Link</a><br>
                        <br>You will need  <strong>Login</strong>  and <strong>Password</strong> to enter the contest.<br>
                          
                        <br>Please don\'t remove this mail, put it in a safe place until the contest is done.<br>
                        <br>Feel free to contact us for any other information.<br>
                             Cordially.<br>
                        
                    </div>
                    <br>
                    <div style="font-size: 11px;text-align: center;color:gray;">
                      [THIS IS AN AUTOMATED MESSAGE .]
                    </div>


                </div>
              </body>  
    </html>
           ';

        $mailed = $mailer->sendMail($email, $subject, $message);
    }

} else {
    echo "Error updating State: " . mysqli_error($link);
}

mysqli_close($link);
header('Location: https://geekshack.ensitgeeksclub.com/dash/control_teams.php');
exit;
?>
