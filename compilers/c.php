<?php
session_start();
$prob_name = $_SESSION['namep'];
$id = $_SESSION['ID'];
// Read timeout value from file, default to 3 seconds if not available
$timeoutFilePath = "problems/".$prob_name."/titre.txt";
$timeing = (file_exists($timeoutFilePath) && ($lines = file($timeoutFilePath)) && isset($lines[1])) ? intval(trim($lines[1])) : 5;
$timeing /= 10;
$out = "timeout ".$timeing."s ./a.out";
$code = $_POST["code"];
//$input=$_POST["input"];
$input = $inputContent;
$filename_code = "main.c";
$filename_error = "error.txt";
$filename_in = "input.txt";

$executable = "a.out";

$check = 0;
$score = 0;

//if(trim($code)=="");
$file_in = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_in, "w+");
fwrite($file_in, $input);
fclose($file_in);
exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $executable");
exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_error");


$error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $filename_error);
$seconds = 0;

$expectedOutput = file_get_contents("problems/" . $prob_name . "/output" . $i . ".txt");
if (trim($error) == "") {
    if (trim($input) == "") {
        $executionStartTime = microtime(true);
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
        $executionEndTime = microtime(true);
        $seconds = $executionEndTime - $executionStartTime;
        $seconds = sprintf('%0.8f', $seconds);
    } else {
        $out = $out . " < " . $filename_in;
        $executionStartTime = microtime(true);
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
        $executionEndTime = microtime(true);
        $seconds = $executionEndTime - $executionStartTime;
        $seconds = sprintf('%0.8f', $seconds);
    }

    if ($expectedOutput == trim($output, "\n")) {
        $score = 10;
        $score_final += 10;
    }


    if ($seconds >= $timeing && $_SESSION["index"] == 0) {
        echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired</h3>
			</fieldset>';
        $_SESSION["index"]++;
    }

    if ($expectedOutput != trim($output, "\n") && $_SESSION["index"] == 0) {
        if ($_SESSION["numProb"] <= 5) { // Check if it's one of the first four test cases
            echo '
            <fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
                <h3 style="font-family: Titillium Web, sans-serif;">Test Error</h3>
                <pre style="font-size:20px;color:white;">Input :<br>' . $input . '</pre>
                <pre style="font-size:20px;color:white;">Expected Output :<br>' . $expectedOutput . '</pre>
                <pre style="font-size:20px;color:white;">Your Output :<br>' . $output . '</pre>
            </fieldset>';
            $_SESSION["index"]++;
        }
    }


    // echo "<tr>
    // 	<td><pre>".$input."</pre></td>
    // 	<td><pre>".$output."</pre></td>
    // 	<td><pre>".$expectedOutput."</pre></td>
    // 	<td><pre>".$score."</pre></td>
    // </tr>";

    //echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
}
// else
// if(!strpos($error,"error"))
// {
// 	if(trim($input)=="")
// 	{
// 		$output=shell_exec("cd scode/".$id."/".$prob_name."; ".$out);
// 	}
// 	else
// 	{
// 		$out=$out." < ".$filename_in;
// 		$output=shell_exec("cd scode/".$id."/".$prob_name."; ".$out);
// 	}
// 	// echo "<pre>$output</pre><br><br>";
// 	$executionEndTime = microtime(true);
// 	$seconds = $executionEndTime - $executionStartTime;
// 	$seconds = sprintf('%0.2f', $seconds);

// 	//echo $seconds;
// 	if ($seconds >= 5 && $_SESSION["index"]==0){
// 		$output = "timeout expired";
// 		echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
// 		<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired</h3>
// 		</fieldset>';
// 		$_SESSION["index"]++;

// 	}

// // 	echo "<tr>
// // 		<td><pre>".$input."</pre></td>
// // 		<td><pre>".$output."</pre></td>
// // 		<td><pre>".$expectedOutput."</pre></td>
// // 		<td><pre>".$score."</pre></td>
// // 	</tr>";
// //     //echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
// // }
else {
    //echo "<pre>$error</pre>";
    $check = 1;
    if ($_SESSION["index"] == 0) {
        echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
				<h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
				<h4 style="font-family: Titillium Web, sans-serif;color:white;">' . $error . '</h4></fieldset>';
        $_SESSION["index"]++;
    }
    // echo "<tr>
    // 	<td><pre>".$input."</pre></td>
    // 	<td><pre>".$error."</pre></td>
    // 	<td><pre>".$expectedOutput."</pre></td>
    // 	<td><pre>".$score."</pre></td>
    // </tr>";
}
$_SESSION["seconds"] += $seconds;


?>
