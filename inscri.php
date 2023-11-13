<?php

//error_reporting(E_ALL);
//ini_set('display_errors', 1);

require 'serverAdd.php';
require 'mail.php';

header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');
header("Access-Control-Max-Age: 3600");
header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");


header("Access-Control-Allow-Headers: *");
header("Content-type: application/json;charset=utf8");


$host = "localhost";
$user = "root";
$password = "geeks_hack_2023";
$dbname = "geekshack3";
$mailer  = new Mailer();
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname;charset=UTF8", $user, $password, array(PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"));
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}

$sql = 'SELECT MAX(id_condidat) as m from candidat ;';
$m = "";
foreach ($conn->query($sql) as $row) {
    $m = strval($row['m']);
}
$cord = json_decode(file_get_contents('php://input'), true);

/*str_replace(["'","\"","`","/","\\"],' ', $_FILES["preuve_etudiant"]["name"]);*/
///////////////////////////////
$_POST['nom'] = str_replace(["'", "\"", "`", "/", "\\"], ' ', $_POST["nom"]);
$_POST['prenom'] = str_replace(["'", "\"", "`", "/", "\\"], ' ', $_POST["prenom"]);
$_POST['ecole'] = str_replace(["'", "\"", "`", "/", "\\"], ' ', $_POST["ecole"]);


//////////

$target_dir = "uploads/";
$target_file = $target_dir . $m . basename(str_replace(["'", "\"", "`", "/", "\\"], ' ', $_FILES["preuve_etudiant"]["name"]));
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));

// Check if image file is a actual image or fake image

$check = getimagesize($_FILES["preuve_etudiant"]["tmp_name"]);
if ($check !== false) {
    // echo "File is an image - " . $check["mime"] . ".";
    $uploadOk = 1;
} else {
    $uploadOk = 0;
    $error_message = "File is not an image.";
    echo json_encode(array('error' => $error_message));
    http_response_code(206);
    exit();
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
    $error_message = "Sorry, your file was not uploaded.";
    echo json_encode(array('error' => $error_message));
    http_response_code(203);
    exit();
    // if everything is ok, try to upload file
} else {
    if (strlen(strval($_POST['phone'])) != 8) {
        $error_message = "Phone number must be 8 digits";
        echo json_encode(array('error' => $error_message));
        http_response_code(203);
        exit();
    } else {
        if (move_uploaded_file($_FILES["preuve_etudiant"]["tmp_name"], $target_file)) {
            // echo "The file " . htmlspecialchars(basename($_FILES["preuve_etudiant"]["name"])) . " has been uploaded.";
            $sql = 'SELECT MAX(id_condidat) as m from candidat ;';

            foreach ($conn->query($sql) as $row) {
                $array1 = explode(" ", $_POST['nom']);
                $array2 = explode(" ", $_POST['prenom']);

                $usrname = $array1[0] . $array2[0] . $row['m'];

                $r = "INSERT into candidat (nom,prenom,email,phone,username,state,ecole,preuve_etudiant) values('" . htmlspecialchars($_POST['nom']) . "','" . $_POST['prenom'] . "','" . $_POST['email'] . "'," . $_POST['phone'] . ",'" . $usrname . "',0,'" . $_POST['ecole'] . "','" . $target_file . "');";
                // Prepare statement

                try {
                    $stmt = $conn->prepare($r);

                    // execute the query
                    $stmt->execute();
/////////////////////////////////////////////////////


                    date_default_timezone_set('Africa/Tunis');
                    $hour = date('H');
                    $error_mail = null;
                    $groupLimit = 25;
                    $limit = 50;
                    $greeting = "";

                    if ($hour > 18 || $hour < 1) {
                        $greeting = 'Good Evening';
                    } else if ($hour > 12) {
                        $greeting = 'Good Afternoon';
                    } else {
                        $greeting = 'Good Morning';
                    }
                    $header = "MIME-Version: 1.0\r\n";
                    $header .= 'From:"ENSIT Geeks Club"<contact@ensitGeeksclub.com>' . "\n";
                    $header .= 'Content-Type:text/html; charset="utf-8"' . "\n";
                    $header .= 'Content-Transfer-Encoding: 8bit';

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
                        <b>' . $greeting . ' Dear ' . $_POST['nom'] . ' ' . $_POST['prenom'] . ',</b><br><br>
                        <br>  Your request has been successfully received <br>  
                        <br>  Stay tuned for the confirmation <br>
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


                    $header2 = "MIME-Version: 1.0\r\n";
                    $header2 .= 'From:"ENSIT Geeks Club"<contact@ensitGeeksclub.com>' . "\n";
                    $header2 .= 'Content-Type:text/html; charset="utf-8"' . "\n";
                    $header2 .= 'Content-Transfer-Encoding: 8bit';
                    $message2 = '
                    <html>
                <head>
                        <title>Registration</title>
                        <meta charset="utf-8" />
                </head>
                            <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                            <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                                <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                                    <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                                    <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                                </div>
                                <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                                    <b>Geeks Hack registration</b><br><br>
                                    <b> Name: </b>' . $_POST['nom'] . ' ' . $_POST['prenom'] . '<br><br>
                                    <b> Email: </b>' . $_POST['email'] . '<br><br>
                                </div>
                                <br>
                                <div style="font-size: 11px;text-align: center;color:gray;">
                                [THIS IS AN AUTOMATED MESSAGE .]
                                </div>


                            </div>
                            
                            </body>
                </html>
           ';
                    $subject = 'GeeksHack Pre-Registration';
                    $mailed = $mailer->sendMail($_POST['email'], $subject, $message);
                    /*if (mail($_POST['email'], $subject, $message, $header)) {
                        if (mail("hadjsassiscompany@gmail.com", $subject, $message2, $header2)) {

                        }
                    }*/

/////////////////////////////////////////////////////

                    echo "Your request has been successfully uploaded. Please check your mail";
                    header('Location: index.php');
                    exit();

                    http_response_code(200);
                } catch (PDOException $e) {
                    try {
                        $up = "UPDATE candidat SET nom = '" . htmlspecialchars($_POST['nom']) . "', prenom = '" . $_POST['prenom'] . "', phone= '" . $_POST['phone'] . "', ecole = '" . $_POST['ecole'] . "' ,preuve_etudiant = '" . $target_file . "' WHERE email = '" . $_POST['email'] . "';";
                        $stm = $conn->prepare($up);

                        // execute the query
                        $stm->execute();
/////////////////////////////////////////////////////


                        date_default_timezone_set('Africa/Tunis');
                        $hour = date('H');
                        $error_mail = null;
                        $groupLimit = 25;
                        $limit = 50;
                        $greeting = "";

                        if ($hour > 18 || $hour < 1) {
                            $greeting = 'Good Evening';
                        } else if ($hour > 12) {
                            $greeting = 'Good Afternoon';
                        } else {
                            $greeting = 'Good Morning';
                        }
                        $header = "MIME-Version: 1.0\r\n";
                        $header .= 'From:"ENSIT Geeks Club"<contact@ensitGeeksclub.com>' . "\n";
                        $header .= 'Content-Type:text/html; charset="utf-8"' . "\n";
                        $header .= 'Content-Transfer-Encoding: 8bit';

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
                        <b>' . $greeting . ' Dear ' . $_POST['nom'] . ' ' . $_POST['prenom'] . ',</b><br><br>
                        <br>  Your request has been successfully updated <br>  
                        <br>  Stay tuned for the confirmation <br>
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


                        $header2 = "MIME-Version: 1.0\r\n";
                        $header2 .= 'From:"ENSIT Geeks Club"<contact@ensitGeeksclub.com>' . "\n";
                        $header2 .= 'Content-Type:text/html; charset="utf-8"' . "\n";
                        $header2 .= 'Content-Transfer-Encoding: 8bit';
                        $message2 = '
                    <html>
                <head>
                        <title>Registration</title>
                        <meta charset="utf-8" />
                </head>
                            <body style="font: small/ 1.5 Arial,Helvetica,sans-serif;">
                            <div style="max-width:602px;margin:0 auto;background:#f6f7f9;padding:20px;box-sizing: border-box;"  bgcolor="#f6f7f9">
                                <div style="width:100%;height:30px;display:flex;margin-bottom: 30px;">
                                    <img src="https://ensitgeeksclub.com/assets/img/logo-geeks.png" width="30px" />
                                    <div style="display:flex;align-items: center;height:100%;margin-left:10px;font-size:20px;font-weight: bold;">ENSIT Geeks Club</div>
                                </div>
                                <div style="width:100%;background:white;box-sizing: border-box;padding:30px;">
                                    <b>Geeks Hack registration</b><br><br>
                                    <b> Name: </b>' . $_POST['nom'] . ' ' . $_POST['prenom'] . '<br><br>
                                    <b> Email: </b>' . $_POST['email'] . '<br><br>
                                </div>
                                <br>
                                <div style="font-size: 11px;text-align: center;color:gray;">
                                [THIS IS AN AUTOMATED MESSAGE .]
                                </div>


                            </div>
                            
                            </body>
                </html>
           ';
                        $subject = 'GeeksHack Pre-Registration';
//                        mail($_POST['email'], $subject, $message, $header);
                        $mailed = $mailer->sendMail($_POST['email'], $subject, $message);

/////////////////////////////////////////////////////


                        echo "Your request is updated";
                        header('Location: index.php');
                        exit();
                        http_response_code(200);
                    } catch (PDOException $e) {
                        $error_message =  "Error when updating your data !";
                        echo json_encode(array('error' => $error_message));
                        http_response_code(201);
                        exit();
                    }

                }
            }


        }
        else {
            $error_message = "Sorry, there was an error uploading your file.";
            echo json_encode(array('error' => $error_message));
            http_response_code(202);
            exit();
        }
    }
}
?>		
