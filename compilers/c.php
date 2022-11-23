<?php
	session_start();
	$prob_name=$_SESSION['namep'];
	$id=$_SESSION['ID'];
	
	$out="timeout 2s ./a.out";
	$code=$_POST["code"];
	//$input=$_POST["input"];
	$input=$inputContent;
	$filename_code="main.c";
	$filename_error="error.txt";
	$filename_in="input.txt";
	
	$executable="a.out";

	$check=0;
	$score=0;

	//if(trim($code)=="");
	$file_in=fopen("scode/".$id."/".$prob_name."/".$filename_in,"w+");
	fwrite($file_in,$input);
	fclose($file_in);
	exec("cd scode/".$id."/".$prob_name."; "."chmod 777 $executable"); 
	exec("cd scode/".$id."/".$prob_name."; "."chmod 777 $filename_error");

	
	$error=file_get_contents("scode/".$id."/".$prob_name."/".$filename_error);
	$executionStartTime = microtime(true);

	$expectedOutput = file_get_contents("problems/".$prob_name."/output".$i.".txt");
	if(trim($error)=="")
	{	
		if(trim($input)=="")
		{
			$output=shell_exec("cd scode/".$id."/".$prob_name."; ".$out);
		}
		else
		{
			$out=$out." < ".$filename_in;
			$output=shell_exec("cd scode/".$id."/".$prob_name."; ".$out);
		}
		
		if($expectedOutput==trim($output,"\n")){
			$score = 10;
			$score_final += 10 ;
		}
		$executionEndTime = microtime(true);
		$seconds = $executionEndTime - $executionStartTime;
		$seconds = sprintf('%0.8f', $seconds);
		
		if ($seconds >=2 && $_SESSION["index"]==0){
			echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
			<h3 style="font-family: Titillium Web, sans-serif;">Timeout Expired</h3>
			</fieldset>';
			$_SESSION["index"]++;
		}

		if($expectedOutput!=trim($output,"\n") && $_SESSION["index"]==0){
			echo '
				<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
					<h3 style="font-family: Titillium Web, sans-serif;">Test Error</h3>
					<h4 style="font-family: Titillium Web, sans-serif;color:white;">Input :'.' '.$input.'</h4>
					<h4 style="font-family: Titillium Web, sans-serif;color:white;">Expected Output :'.' '.$expectedOutput.'</h4>
					<h4 style="font-family: Titillium Web, sans-serif;color:white;">Your Output :'.' '.$output.'</h4>
				</fieldset>';
			$_SESSION["index"]++;
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
	else
	{
		//echo "<pre>$error</pre>";
		$check=1;
		if($_SESSION["index"]==0)
		{
			echo '<fieldset style="border: none;border: none;box-shadow: 5px 4px 2px #010c14;color: #ff7676;border-radius: 2em;padding: 0.5em 2em;" >
				<h3 style="font-family: Titillium Web, sans-serif;">Error</h3>
				<h4 style="font-family: Titillium Web, sans-serif;color:white;">'.$error.'</h4></fieldset>';
				$_SESSION["index"]++;
		}
		// echo "<tr>
		// 	<td><pre>".$input."</pre></td>
		// 	<td><pre>".$error."</pre></td>
		// 	<td><pre>".$expectedOutput."</pre></td>
		// 	<td><pre>".$score."</pre></td>
		// </tr>";
	}
	$_SESSION["seconds"]+=$seconds;


?>
