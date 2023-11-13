<?php

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require '../vendor/phpmailer/phpmailer/src/Exception.php';
require '../vendor/phpmailer/phpmailer/src/PHPMailer.php';
require '../vendor/phpmailer/phpmailer/src/SMTP.php';

class Mailer
{
	private $mail;

	public function __construct()
	{
		// Create a new PHPMailer instance
		$this->mail = new PHPMailer();

		// Enable debugging (optional)
		$this->mail->SMTPDebug = 2;

		// Set up your SMTP configuration
		$this->mail->isSMTP();
		$this->mail->Host = 'smtp.gmail.com';
		$this->mail->SMTPAuth = true;
		$this->mail->Username = 'ensitgeeksclub@gmail.com';
		$this->mail->Password = 'ezfv isqo bhtx wfcf';
		$this->mail->SMTPSecure = 'tls'; // use 'ssl' for SSL encryption
		$this->mail->Port = 587; // adjust the port if necessary

		// Set up the email content
		$this->mail->setFrom('ensitgeeksclub@gmail.com', 'Ensit Geeks Club');
		$this->mail->isHTML(true);
	}

	public function sendMail($to, $subject, $body)
	{
		// Clear any previous recipients
		$this->mail->ClearAllRecipients();

		// Set recipient
		$this->mail->addAddress($to);

		// Set subject and body
		$this->mail->Subject = $subject;
		$this->mail->Body = $body;

		// Send the email
		if ($this->mail->send()) {
			return 'Mail sent successfully';
		} else {
			return 'Error: ' . $this->mail->ErrorInfo;
		}
	}
}

// Example usage:
$mailer = new Mailer();
$result = $mailer->sendMail('mahdihadjsassi1@gmail.com', 'Tuto', 'Bonjour Mahdi !');
echo $result;

?>
