<?php
session_start();
$prob_name = $_SESSION['namep'];
$id = $_SESSION['ID'];

$filename_error = "error.txt";

$out = "timeout 2s ./a.out";

$runtime_file = "runtime.txt";
//$input=$_POST["input"];
$input = $inputContent;
$filename_in = "input.txt";


$runtime_error_command = $out . " 2> " . $runtime_file;

$score = 0;
//if(trim($code)=="")
//die("The code area is empty");
//$sh=exec("pwd");


$file_in = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_in, "w+");
fwrite($file_in, $input);
fclose($file_in);

$error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $filename_error);
echo "<script>console.log(`$error`);</script>";


$expectedOutput = file_get_contents("problems/" . $prob_name . "/output" . $i . ".txt");

if (trim($error) == "") {
    $executionStartTime = microtime(true);
    shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $runtime_error_command);
    $executionEndTime = microtime(true);
    $runtime_error = file_get_contents("scode/" . $id . "/" . $prob_name . "/" . $runtime_file);
    if (trim($input) == "") {
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
    } else {
        $out = $out . " < " . $filename_in;
        $output = shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $out);
    }

    if ($expectedOutput == trim($output, "\n")) {
        $score = 10;
        $score_final += 10;
    }


    $seconds = $executionEndTime - $executionStartTime;
    $seconds = sprintf('%0.2f', $seconds);

    //echo $seconds;
    if ($seconds >= 2 && $_SESSION["index"] == 0) {
        $output = "timeout expired";
        echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired</h3>
			</fieldset>';
        $_SESSION["index"]++;
    }

    if (trim($runtime_error) != "" && $_SESSION["index"] == 0) {
        echo '
			<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
				<h3 style="font-family: Titillium Web, sans-serif;">Run Time Error</h3>
				<h4 style="font-family: Titillium Web, sans-serif;color:white;">' . $runtime_error . '</h4>
			</fieldset>';
        $_SESSION["index"]++;
    }

    if ($expectedOutput != trim($output, "\n") && $_SESSION["index"] == 0) {
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
    // 	<td><pre>".$output."$runtime_error</pre></td>
    // 	<td><pre>".$expectedOutput."</pre></td>
    // 	<td><pre>".$score."</pre></td>
    // </tr>";


    /*if(trim($error)!="")
        echo "<pre>$runtime_error</pre><br><br>";
    echo "<pre>$output</pre><br><br>";*/
    //echo "<pre>$prob_name</pre>";
} else {
    $check = 1;
    if ($_SESSION["index"] == 0) {
        echo '
			<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
				<h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
				<h4 style="font-family: Titillium Web, sans-serif;color:white;">' . $error . '</h4>
			</fieldset>';
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