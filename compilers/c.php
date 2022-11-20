<?php
	session_start();
	$prob_name=$_SESSION['namep'];
	$id=$_SESSION['ID'];
	
	$out="timeout 5s ./a.out";
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
		
		echo $seconds;
		if ($seconds >= 5){
			$output = "timeout expired";
		}
		

		// echo "<tr>
		// 	<td><pre>".$input."</pre></td>
		// 	<td><pre>".$output."</pre></td>
		// 	<td><pre>".$expectedOutput."</pre></td>
		// 	<td><pre>".$score."</pre></td>
		// </tr>";

        //echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
	}
	else 
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
	// 	if ($seconds >= 5){
	// 		$output = "timeout expired";
	// 	}
		
	// 	echo "<tr>
	// 		<td><pre>".$input."</pre></td>
	// 		<td><pre>".$output."</pre></td>
	// 		<td><pre>".$expectedOutput."</pre></td>
	// 		<td><pre>".$score."</pre></td>
	// 	</tr>";
    //     //echo "<textarea id='div' class=\"form-control\" name=\"output\" rows=\"10\" cols=\"50\">$output</textarea><br><br>";
	// }
	// else
	{
		//echo "<pre>$error</pre>";
		$check=1;

		// echo "<tr>
		// 	<td><pre>".$input."</pre></td>
		// 	<td><pre>".$error."</pre></td>
		// 	<td><pre>".$expectedOutput."</pre></td>
		// 	<td><pre>".$score."</pre></td>
		// </tr>";
	}
	

?>
