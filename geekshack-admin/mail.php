<?php
header('Access-Control-Allow-Origin: *');

header('Access-Control-Allow-Methods: *');

header("Access-Control-Allow-Headers: *");


$header="MIME-Version: 1.0\r\n";
$header.='From:"ENSIT Geeks Club"<contact@ensitGeeksclub.com>'."\n";
$header.='Content-Type:text/html; charset="utf-8"'."\n";
$header.='Content-Transfer-Encoding: 8bit';

if(mail("hadjsassiscompany@gmail.com", "Tuto", "bonjour Mahdi !", $header)){
}else{
	echo "error";
}

?>
