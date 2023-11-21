<?php
session_start();
$score = 0;
$input = $inputContent;
$prob_name = $_SESSION['namep'];
$id = $_SESSION['ID'];
$CC = "javac";
// Read timeout value from file, default to 3 seconds if not available
$timeoutFilePath = "problems/".$prob_name."/titre.txt";
$timeing = (file_exists($timeoutFilePath) && ($lines = file($timeoutFilePath)) && isset($lines[1])) ? intval(trim($lines[1])) : 2;
$out = "timeout ".$timeing."s java Main";
//$input=$_POST["input"];

$filename_error = "error.txt";
$filename_in = "input.txt";
$runtime_file = "runtime.txt";
$executable = "*.class";
$runtime_error_command = $out . " 2>" . $runtime_file;
$file_in = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_in, "w+");
fwrite($file_in, $input);
fclose($file_in);


$error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $filename_error);

$expectedOutput = file_get_contents("problems/" . $prob_name . "/output" . $i . ".txt");
if (trim($error) == "") {
    $executionStartTime = microtime(true);
	shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $runtime_error_command);
    $executionEndTime = microtime(true);

	$runtime_error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $runtime_file);
	if (trim($input) == "") {
		$output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
		// echo "<script>console.log('cc');</script>";
	} 
	else {
		$out = $out . " < " . $filename_in;
		$output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
	}

	if ($expectedOutput == trim($output, "\n")) {
		$score = 10;
		$score_final += 10;
	}

	$seconds = $executionEndTime - $executionStartTime;
	$seconds = sprintf('%0.8f', $seconds);

	if ($seconds >= $timeing && $_SESSION["index"]==0) {
		echo '
		<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired</h3>
		</fieldset>';
		$_SESSION["index"]++;
		
	}
	
	if (trim($runtime_error) != "" && $_SESSION["index"]==0){
		echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Run Time Error</h3>
			<h4 style="font-family: Titillium Web, sans-serif;color:white;">'.$runtime_error.'</h4></fieldset>';
		$_SESSION["index"]++;
	}
	
	if($expectedOutput!=trim($output,"\n") && $_SESSION["index"]==0){
        if ($_SESSION["numProb"] <= 4) { // Check if it's one of the first four test cases
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
	// 	<td><pre>".trim($output,"\n")."</pre></td>
	// 	<td><pre>".$expectedOutput."</pre></td>
	// 	<td><pre>".$score."</pre></td>
	// </tr>";

	//echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
		// echo "<tr>
		// 				<td><pre>" . $input . "</pre></td>
		// 				<td><pre>" . trim($output, "\n") . "<br><pre>$runtime_error</pre></pre></td>
		// 				<td><pre>" . $expectedOutput . "</pre></td>
		// 				<td><pre>" . $score . "</pre></td>
		// 			</tr>";
	
		
		// echo "<tr>
		// 			<td><pre>" . $input . "</pre></td>
		// 			<td><pre>" . trim($output, "\n") . "</pre></td>
		// 			<td><pre>" . $expectedOutput . "</pre></td>
		// 			<td><pre>" . $score . "</pre></td>
		// 		</tr>";
	
	//echo "<pre>$output</pre>";
	//echo "<pre>".strpos($runtime_error,"java.util.NoSuchElementException")."</pre>";
	//echo "$output";
	//echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
} else 
// if (trim($error) == "") {
// 	//echo "<pre>$error</pre>";
// 	if (trim($input) == "") {
// 		$output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
// 	} else {
// 		$out = $out . " < " . $filename_in;
// 		$output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
// 	}
// 	/* for runtime error */
// 	if ($expectedOutput == trim($output, "\n")) {
// 		$score = 10;
// 		$score_final += 10;
// 	}

// 	$executionEndTime = microtime(true);
// 	$seconds = $executionEndTime - $executionStartTime;
// 	$seconds = sprintf('%0.8f', $seconds);

// 	if ($seconds >= 5) {
// 		$output = "timeout expired";
// 	}
// 	echo "<tr>
// 					<td><pre>" . $input . "</pre></td>
// 					<td><pre>" . trim($output, "\n") . "<br><pre>$error</pre></pre></td>
// 					<td><pre>" . $expectedOutput . "</pre></td>
// 					<td><pre>" . $score . "</pre></td>
// 				</tr>";
// 	//echo "$output";
// 	//echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
// } 
// else 
{
	if($_SESSION["index"]==0){
		echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
			<h4 style="font-family: Titillium Web, sans-serif;color:white;">'.$error.'</h4></fieldset>';
		$_SESSION["index"]++;
	}
	// echo "<tr>
	// 				<td><pre>" . $input . "</pre></td>
	// 				<td><pre>" . $error . "pre></td>
	// 				<td><pre>" . $expectedOutput . "</pre></td>
	// 				<td><pre>" . $score . "</pre></td>
	// 			</tr>";
}

$_SESSION["seconds"]+=$seconds;
