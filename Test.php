<?php

require 'serverAdd.php';
require 'mail.php';
error_reporting(E_ALL);
ini_set('display_errors', 1);
$mailer = new Mailer();


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
                        <b> Buenos Dear Mahdi Hadj Sassi,</b><br><br>
                        <br>  Your request has been successfully received <br>  
                        <br>  Stay tuned for the confirmation <br>
                        Feel free to contact us for any other information.<br>
                             Cordially.<br>
                        
                    </div>
                    <br>
                    <div style="font-size: 11px;text-align: center;color:rgb(128,128,128);">
                      [THIS IS AN AUTOMATED MESSAGE .]
                    </div>


                </div>
              </body>  
    </html>
           ';

$subject = 'GeeksHack Pre-Registration';
$mailed = $mailer->sendMail("mahdihadjsassi1@gmail.com", $subject, $message);




