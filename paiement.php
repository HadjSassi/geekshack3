<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");
header("Content-type: application/json;charset=utf8");

require 'mail.php';
$mailer  = new Mailer();

 $host="localhost";
 $db="geekshack3";
    $user="root";
    $password="geeks_hack_2023";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db;charset=UTF8", $user, $password,array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$sql =  'SELECT MAX(id_team) as m from team ;';
$m="";
        foreach  ($conn->query($sql) as $row) {
            $m=strval($row['m']);
        }
$cord= json_decode(file_get_contents('php://input'), true);

function randomPass() { 
    $alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890'; 
    $pass = array(); //remember to declare $pass as an array 
    $alphaLength = strlen($alphabet) - 1; //put the length -1 in cache 
    for ($i = 0; $i < 10; $i++) { 
        $n = rand(0, $alphaLength); $pass[] = $alphabet[$n]; 
    } 
    return implode($pass); 
}



$target_dir = "paiements/";
$target_file = $target_dir .$m. basename(str_replace(["'","\"","`","/","\\"],' ', $_FILES["preuve"]["name"]));
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));

// Check if image file is a actual image or fake image

    $check = getimagesize($_FILES["preuve"]["tmp_name"]);
if ($check !== false) {
    // echo "File is an image - " . $check["mime"] . ".";
    $uploadOk = 1;
} else {
    echo "File is not an image.";
    http_response_code(206);
    $uploadOk = 0;
}


// Check if file already exists
// if (file_exists($target_file)) {
//    echo "Sorry, file already uploaded. Try to rename it!";
//    http_response_code(205);
//    $uploadOk = 0;
//}


// Allow certain file formats
// if (
//     $imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
//     && $imageFileType != "gif"
// ) {
//     echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
//     http_response_code(204);
//     $uploadOk = 0;
// }

// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.";
    http_response_code(203);
    // if everything is ok, try to upload file
} 
else{
    if (move_uploaded_file($_FILES["preuve"]["tmp_name"], $target_file)) {
        // echo "The file " . htmlspecialchars(basename($_FILES["preuve"]["name"])) . " has been uploaded.";
        
            $member1=null;
            $member2=null;
            if(strlen($_POST['member_one_username'])!=0){
                $member1=$_POST['member_one_username'];
            }

            if(strlen($_POST['member_two_username'])!=0){
                $member2=$_POST['member_two_username'];
            }
            $log=$_POST['team_tag']."@geekshack.tn";
            $r = "INSERT into team (login,password,team_tag,leader_username,".($member1 == null ? "":"member_one_username ,").($member2 == null ? "":"member_two_username ,")."state,preuve) values('".$log."','".randomPass()."','".$_POST['team_tag']."','".$_POST['leader_username']."',".($member1 ==null ? "":"'".$member1."',").($member2==null ? "":"'".$member2."',")."0,'".$target_file."');";
            // Prepare statement
        
        try {
            $stmt = $conn->prepare($r);

            // execute the query
            $stmt->execute();
            $lastInsertedId = $conn->lastInsertId();
            $r ="Insert into score(id_team) values ($lastInsertedId)";
            $stmt = $conn->prepare($r);

            // execute the query
            $stmt->execute();
            //////////////////////////////////////////////////


            date_default_timezone_set('Africa/Tunis');
            $hour = date('H');
            $error_mail=null;
            $groupLimit=25;
            $limit=50;
            $greeting="";

            $nom="";
            $prenom="";
            $email="";
            $mailsql= "select nom,prenom,email from candidat where username ='".$_POST['leader_username']."';'";
            foreach ($conn->query  ($mailsql) as $row){
                $nom=$row["nom"]; 
                $prenom=$row['prenom'];
                $email=$row['email'];
            }
            /////////////////////////////////////
            
            $nom2="";
            $prenom2="";
            $email2="";
            if ( $member2!=null ) {
            
            	$m2= "select nom,prenom,email from candidat where username ='".$member2."';'";
            foreach ($conn->query  ($m2) as $row){
                $nom2=$row["nom"]; 
                $prenom2=$row['prenom'];
                $email2=$row['email'];
            }
            	$messagTwo = '
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
                                    <b>'.$greeting.' Dear '.$nom2.' '.$prenom2.',</b><br><br>
                                    <br> <strong>'.$nom.' '.$prenom.'</strong> has added you in new team for GeeksHack competition  <br>  
                                    <br>Your team tag is :<strong>'.$_POST['team_tag'].'</strong><br>
                                     
                                   
                                    <br>  Stay tuned <br>
                                    Feel free to contact us for any other information.<br>
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
            
            }
            
            /////////////////////////
            
            $nom1="";
            $prenom1="";
            $email1="";
            if ( $member1!=null ) {
            
            	$m1= "select nom,prenom,email from candidat where username ='".$member1."';'";
            foreach ($conn->query  ($m1) as $row){
                $nom1=$row["nom"]; 
                $prenom1=$row['prenom'];
                $email1=$row['email'];
            }
            	$messagOne = '
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
                                    <b>'.$greeting.' Dear '.$nom1.' '.$prenom1.',</b><br><br>
                                    <br> <strong>'.$nom.' '.$prenom.'</strong> has added you in new team for GeeksHack competition  <br>  
                                    <br>Your team tag is :<strong>'.$_POST['team_tag'].'</strong><br>
                                     
                                   
                                    <br>  Stay tuned <br>
                                    Feel free to contact us for any other information.<br>
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
            
            }
            
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
                                    <b>'.$greeting.' Dear '.$nom.' '.$prenom.',</b><br><br>
                                    <br>  Your participation request in GeeksHack competition has been successfully received <br>  
                                    <br>Your team tag is :<strong>'.$_POST['team_tag'].'</strong><br>
                                    <br> Leader : <strong>'.$_POST['leader_username'].'</strong></br> 
                                    '.( $member1 != null  ?
                                    "<br>  Member one : <strong>".$member1."</strong><br>" : ""
                                    ).'
                                    '.(  $member2!= null ?
                                    "<br>  Member two : <strong>".$member2."</strong><br>" : ""
                                    ).'
                                    '.( $member1 != null || $member2!= null ?
                                    "<br>  Please make sure to transfer this mail to your teammates<br>" : ""
                                    ).'
                                    <br>Once we verify that you paid the registration fees, a confirmation mail will be sent<br>
                                    <br>  Stay tuned <br>
                                    Feel free to contact us for any other information.<br>
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
                      
                      
            
            
            
                      $header2="MIME-Version: 1.0\r\n";
                       $header2.='From:"ENSIT Geeks Club"<contact@ensitgeeksclub.com>'."\n";
                       $header2.='Content-Type:text/html; charset="utf-8"'."\n";
                       $header2.='Content-Transfer-Encoding: 8bit';
                       $message2 = '
                                <html>
                            <head>
                                    <title>Registration</title>
                                    <meta charset="utf-8" />
                            </head>
                                        <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                                        <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                                            <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                                                <img src="https://ensitgeeksclub.com/joinUs/images/logo-geeks.png" width="30px" />
                                                <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                                            </div>
                                            <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                                                <b>Geeks Hack registration</b><br><br>
                                                <b> Name: </b>'.$nom.' '.$prenom.'<br><br>
                                                <b> Email: </b>'.$email.'<br><br>
                                            </div>
                                            <br>
                                            <div style="font-size: 11px;text-align: center;color:gray;">
                                            [THIS IS AN AUTOMATED MESSAGE .]
                                            </div>
            
            
                                        </div>
                                        
                                        </body>
                            </html>
                       ';
                       $subject='GeeksHack Team Registration';
            $mailed = $mailer->sendMail($email, $subject, $message);
            $mailed = $mailer->sendMail("hadjsassiscompany@gmail.com", $subject, $message2);
            $mailed = $mailer->sendMail($email, $subject, $messageOne);
            $mailed = $mailer->sendMail($email, $subject, $messageTwo);

//            if(mail($email, $subject, $message, $header)){
//                        if(mail("hadjsassiscompany@gmail.com", $subject, $message2, $header2)){
//            			if(mail($email1, $subject, $messagOne, $header)){
//            			if(mail($email2, $subject, $messagTwo, $header)){
//
//                        }
//                        }
//                        }
//                      }

            //////////////////////////////////////////////////

            echo "Your request has been successfully uploaded. Please check your mail";
            
            http_response_code(200);
        } catch (PDOException $e) {
            echo "internal server error ";
            
            http_response_code(200);
        }
        


    }
    else {
        echo "Sorry, there was an error uploading your file.";
        http_response_code(202);
    }
}
?>
