<?php
session_start();
$prob_name = $_SESSION['namep'];
$id = $_SESSION['ID'];
// Read timeout value from file, default to 3 seconds if not available
$timeoutFilePath = "problems/".$prob_name."/titre.txt";
$timeing = (file_exists($timeoutFilePath) && ($lines = file($timeoutFilePath)) && isset($lines[1])) ? intval(trim($lines[1])) : 5;
$timeing /= 10;
$CC = "timeout ".$timeing."s python3";
$code = $_POST["code"];
//$input = $_POST["input"];
$input = $inputContent;
$filename_code = "main.py";
$filename_in = "input.txt";
$IterationInput = $inputContent;
$filename_error = "error.txt";
$command = $CC . " " . $filename_code;
$command_error = $command . " 2>" . $filename_error;
$score = 0;

//if(trim($code)=="")
//die("The code area is empty");

$file_code = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_code, "w+");
exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_code");
echo system("perf stat ./scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_code");
fwrite($file_code, $code);
fclose($file_code);

$file_in = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_in, "w+");
fwrite($file_in, $input);
fseek($file_in, 1);
fclose($file_in);

exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_error");
exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_in");


$expectedOutput = file_get_contents("problems/" . $prob_name . "/output" . $i . ".txt");
if (trim($input) == "") {
    $executionStartTime = microtime(true);
    shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command_error . " < " . $filename_in);
    $executionEndTime = microtime(true);
    $error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $filename_error);
    if (trim($error) != "") {
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command . " < " . $filename_in);
        echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
            <h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
			<h4 style="font-family: Titillium Web, sans-serif;color:white;">' . $error . '</h4></fieldset>';
        $_SESSION["index"]++;
    } else {
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command . " < " . $filename_in);
        if ($expectedOutput == trim($output)) {
            $score = 10;
            $score_final += 10;
        }


        $seconds = $executionEndTime - $executionStartTime;
        $seconds = sprintf('%0.8f', $seconds);

        if ($seconds >= $timeing && $_SESSION["index"] == 0) {
            echo '
			<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
				<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired:  Time Exceeded > '.$timeing.' </h3>
			</fieldset>';
            $_SESSION["index"]++;
        }
        if ($expectedOutput != trim($output) && $_SESSION["index"] == 0) {
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


        //  echo "<tr>
        //  	<td><pre>".$input."</pre></td>
        //  	<td><pre>".trim($output,"\n")."</pre></td>
        //  	<td><pre>".$expectedOutput."</pre></td>
        //  	<td><pre>".$score."</pre></td>
        //  </tr>";
    }
} else {
    $executionStartTime = microtime(true);
    shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command_error . " < " . $filename_in);
    $executionEndTime = microtime(true);
    $error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $filename_error);
    // echo "test ".strpos("Error",$error);


    //erreur syntaxe
    if (strpos($error, "Error") != false) {
        if ($_SESSION["index"] == 0 && $error != "") {
            echo '
			<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
			<h4 style="font-family: Titillium Web, sans-serif;color:white;">' . $error . '</h4>
			</fieldset>';
            $_SESSION["index"]++;
        }

        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command . " < " . $filename_in);
        $outputEval = trim($output, "\n");
        if ($expectedOutput == $outputEval) {
            $score = 10;
            $score_final += 10;
        }

        $seconds = $executionEndTime - $executionStartTime;
        $seconds = sprintf('%0.8f', $seconds);
        if ($seconds >= $timeing && $_SESSION["index"] == 0) {
            $output = "timeout expired";
            echo '
			<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired:  Time Exceeded > '.$timeing.'</h3>
			</fieldset>';
            $_SESSION["index"]++;

        }

        if ($expectedOutput != $outputEval && $_SESSION["index"] == 0) {

            if ($_SESSION["index"] == 0) {
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
        }
    } else {
        /*
        something wrong here !

        */
        $command = $command_error . " < " . $filename_in;
        $executionStartTime = microtime(true);
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command . " < " . $filename_in);
        $executionEndTime = microtime(true);
        $outputEval = trim($output, "\n");
        if ($expectedOutput == $outputEval) {
            $score = 10;
            $score_final += 10;
        }

        $seconds = $executionEndTime - $executionStartTime;
        $seconds = sprintf('%0.8f', $seconds);

        if ($seconds >= $timeing && $_SESSION["index"] == 0) {
            $output = "timeout expired";
            echo '
					<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
						<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired:  Time Exceeded > '.$timeing.'</h3>
					</fieldset>';
            $_SESSION["index"]++;

        }

        if ($expectedOutput != $outputEval && $_SESSION["index"] == 0) {
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
    }


    // echo "<tr>
    // 	<td><pre>".$input."</pre></td>
    // 	<td><pre>".trim($output,"\n")."</pre></td>
    // 	<td><pre>".$expectedOutput."</pre></td>
    // 	<td><pre>".$score."</pre></td>
    // </tr>";
}
$_SESSION["seconds"] += $seconds;
?>