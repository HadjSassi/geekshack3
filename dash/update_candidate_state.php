<?php
// update_score.php
require "../config.php";
require '../mail.php';
$mailer  = new Mailer();

$id = $_GET['id'];

$link = mysqli_connect('localhost', 'root', 'geeks_hack_2023', 'geekshack3');

$requete1 = "select * from candidat where username = '$id'";
$result1 = mysqli_query($link, $requete1);
$coord = mysqli_fetch_assoc($result1);

// Update the score in the database
$sql = "UPDATE candidat SET state = 1 WHERE username = '$id'";

if (mysqli_query($link, $sql)) {
    echo "State updated successfully.";
    $hour = date('H');
    $greeting="";
    if($hour > 18 || $hour < 1) {$greeting='Good Evening';}
    else if($hour>12){$greeting='Good Afternoon';}
    else  {$greeting='Good Morning';}
    $email = $coord['email'];
    $full_name= $coord['nom'] . ' ' . $coord['prenom'];
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
                        <b>'.$greeting.' Dear '.$full_name.',</b><br><br>
                        <br>  Your Pre-Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your username : <strong>'.$id.'</strong><br>
                        
                        <br>Now, you can participate in team or without team <a href="https://geekshack.ensitgeeksclub.com/team-registration">From this Link</a><br>
                        <br>You will need your <strong>username</strong> to finalize your particiation request<br>
                          
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

    $subject='GeeksHack Confirmation';
    $mailed = $mailer->sendMail($email, $subject, $message);
} else {
    echo "Error updating State: " . mysqli_error($link);
}

mysqli_close($link);
header('Location: https://geekshack.ensitgeeksclub.com/dash/control_candidates.php');
exit;
?>
