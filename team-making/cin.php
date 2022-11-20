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
    $sql = "SELECT member_two_username,email
    from team, candidat 
    where team.member_two_username = candidat.username;";

    $i = 0;
    foreach ($conn->query($sql) as $row) {
    	for($j=0;$j<15;$j++){
    	
    	}
        $data[$i]['leader_username'] = $row['leader_username'];
        $data[$i]['nom'] = $row['nom'];
        $data[$i]['prenom'] = $row['prenom'];
        $data[$i]['email'] = $row['email'];


        $i++;
    }
    

    ////////////////////////////
    $subject='Crococoder Training';

date_default_timezone_set('Africa/Tunis');
$hour = date('H');
$error_mail=null;
$groupLimit=25;
$limit=50;
$greeting="";


if($hour > 18 || $hour < 1) {$greeting='Good Evening';}
else if($hour>12){$greeting='Good Afternoon';}
        else  {$greeting='Good Morning';}
           $header="MIME-Version: 1.0\r\n";
           $header.='From:"ENSIT Geeks Club"<contact@ensitgeeksclub.com>'."\n";
           $header.='Content-Type:text/html; charset="utf-8"'."\n";
           $header.='Content-Transfer-Encoding: 8bit';
       
           $message = '
         <html>
    <head>
            
            <meta charset="utf-8" />
    </head>
                <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                    <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                        <img src="https://ensitgeeksclub.com/joinUs/images/logo-geeks.png" width="30px" />
                        <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                    </div>
                    <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                        <b>'.$greeting.' Dear Participant,</b><br><br>
                        
                        <br>Thank you for your participation in GeeksHack competition .<br>
                        <br>As we mentioned at the end of the competition, <strong>CrocoCoder</strong> training center offers for all participants a free training via 
                        <a href="https://crococoder.tn/formations-en-ligne/?fbclid=IwAR0KttuhPgk0miCM-PWeo7cgVli3_xUvvBmzjqSKSAVokZzTeCmOEZtzPq8">this LINK</a>   <br> 
                        
         
                        <br>We want to thank <strong>CorocoCoder</strong> for supporting our Event.<br>
                        
                        <br>Stay tuned for next edition...<br>
                             <strong>Cordially.</strong><br>
                        
                    </div>
                    <br>
                    <div style="font-size: 11px;text-align: center;color:gray;">
                      [THIS IS AN AUTOMATED MESSAGE .]
                    </div>


                </div>
              </body>  
    </html>
           ';
           echo $message;
           
           for($i=0;$i<sizeof($data);$i++){
           
           	/*if(mail($data[$i]['email'], $subject, $message, $header)){
            
      		}*/
           }
    
    ////////////////////////////
   
} catch (PDOException $e) {
    echo json_encode($e);
}
