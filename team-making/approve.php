<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
require "config.php";
require '../mail.php';
$mailer  = new Mailer();
try {
    $conn = new PDO("mysql:host=$host;dbname=$base", $user, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  } catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
  }

  $coord= json_decode(file_get_contents('php://input'),true);

//   echo json_encode(["response"=>$coord['username']]);
//   http_response_code(200);
  

    try {
        $sql ="UPDATE team set state = 1 WHERE team_tag = '".$coord['team_tag']."';";
        
        $stmt = $conn->prepare($sql);

        // execute the query
        $stmt->execute();

        ///////////////////////////

        $subject='GeeksHack Confirmation';

date_default_timezone_set('Africa/Tunis');
$hour = date('H');
$error_mail=null;
$groupLimit=25;
$limit=50;
$greeting="";


$team_tag=$coord['team_tag'];

$leader_email = $coord['leader_email'];
$full_name=$coord['leader_full_name'];


$member_one_name= $coord['member_one_name'];
$member_two_name= $coord['member_two_name'];


$member_one_email=$coord['member_one_email'];
$member_two_email = $coord['member_two_email'];

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
                        <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                        <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                    </div>
                    <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                        <b>'.$greeting.' Dear '.$full_name.',</b><br><br>
                        <br>  Your Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your team tag : <strong>'.$team_tag.'</strong><br>
                        '.
                        ( ( isset($member_one_email) && $member_one_email != null && strlen($member_one_email)!=0 ?
                            "<br>Member one :<strong> ".$member_one_name."</strong><br>"
                        : "") )
                        .'
                        '.
                        ( ( isset($member_two_email) && $member_two_email != null && strlen($member_two_email)!=0  ?
                            "<br>Member two : <strong>".$member_two_name."</strong><br>"
                        : "") )
                        .'
                        <br><strong>Reminder :</strong>GeeksHack competition will start on 27 Nov 2021 at ENSIT <br>
                          
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

           if ( isset($member_one_email) && $member_one_email != null && strlen($member_one_email)!=0 ) {
            $message2 = '
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
                           <b>'.$greeting.' Dear '.$member_one_name.',</b><br><br>
                           <br>  Your Registration for GeeksHack event has been successfully confirmed <br>
                           
                           
                           <br>Your team tag : <strong>'.$team_tag.'</strong><br>
                           <br>Team Leader:<strong> '.$full_name.'</strong><br>
                           '.
                           ( ( isset($member_two_email) && $member_two_email != null && strlen($member_two_email)!=0  ?
                               "<br>Member two : <strong>".$member_two_name."</strong><br>"
                           : "") )
                           .'
                           <br><strong>Reminder :</strong>GeeksHack competition will start on 27 Nov 2021 at ENSIT <br>
                             
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
               $mailed = $mailer->sendMail($member_one_email, $subject, $message2);

//              if(mail($member_one_email, $subject, $message2, $header)){
//
//            }
           }



           ///////////////////////////


           if ( isset($member_two_email) && $member_two_email != null && strlen($member_two_email)!=0 ) {
            $message3 = '
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
                           <b>'.$greeting.' Dear '.$member_two_name.',</b><br><br>
                           <br>  Your Registration for GeeksHack event has been successfully confirmed <br>
                           
                           
                           <br>Your team tag : <strong>'.$team_tag.'</strong><br>
                           <br>Team Leader:<strong> '.$full_name.'</strong><br>
                           '.
                           ( ( isset($member_one_email) && $member_one_email != null && strlen($member_one_email)!=0  ?
                               "<br>Member two : <strong>".$member_one_name."</strong><br>"
                           : "") )
                           .'
                           <br><strong>Reminder :</strong>GeeksHack competition will start on 27 Nov 2021 at ENSIT <br>
                             
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
               $mailed = $mailer->sendMail($member_two_email, $subject, $message3);

//              if(mail($member_two_email, $subject, $message3, $header)){
//
//            }
           }


           /////////////////////////////

        $mailed = $mailer->sendMail($leader_email, $subject, $message);

//        if(mail($leader_email, $subject, $message, $header)){
//
//      }

        ////////////////////////
        $res = array ("res" => "Success");
        echo json_encode($res);
        
    } catch (PDOException $e) {
        echo json_encode($e);
        http_response_code(500);
    }
