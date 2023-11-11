<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
require "config.php";

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
        $sql ="UPDATE candidat set state = 1 WHERE username = '".$coord['username']."';";
        
        $stmt = $conn->prepare($sql);

        // execute the query
        $stmt->execute();

        ///////////////////////////


date_default_timezone_set('Africa/Tunis');
$hour = date('H');
$error_mail=null;
$groupLimit=25;
$limit=50;
$greeting="";


$username=$coord['username'];
$email = $coord['email'];
$full_name=$coord['full_name'];

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
                        <b>'.$greeting.' Dear '.$full_name.',</b><br><br>
                        <br>  Your Pre-Registration for GeeksHack event has been successfully confirmed <br>
                        
                        
                        <br>Your username : <strong>'.$username.'</strong><br>
                        
                        <br>Now, you can participate in team or without team <a href="http://https://geekshack.ensitgeeksclub.com//team-registration">From this Link</a><br>
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
      if(mail($email, $subject, $message, $header)){
           if(mail("ahmedraies594@gmail.com", $subject, $message, $header)){
            
          } 
          }


        ////////////////////////
        $res = array ("res" => "Success");
        echo json_encode($res);
        
    } catch (PDOException $e) {
        echo json_encode($e);
        http_response_code(500);
    }
?>
