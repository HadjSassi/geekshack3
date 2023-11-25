<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
//ajouter la notion de temps au  score et la notion d'ordre de resolution
use function PHPSTORM_META\type;

session_start() ?>
<div style="height: 100%; width:100%">
    <?php
    $score = 0;

    //////////////////Fonction de compilation//////////////////
    function Compiler($compilerFile)
    {

        $prob_name = $_SESSION['namep'];
        $user = $_SESSION['ID'];
        $inputContent = "";
        $score_final = 0;
        $nb_test = 0;
        // echo "
        // 	<br>
        // 			<div class='scrollbar' id='scroll' style='height:90%;'>
        // 			<table class='table'>
        // 			<thead class='thead-dark'>
        // 			  <tr>
        // 				<th scope='col'>Input</th>
        // 				<th scope='col'>Output</th>
        // 				<th scope='col'>Expected output</th>
        // 				<th scope='col'>Score</th>
        // 			  </tr>
        // 			</thead>
        // 			<tbody>";
        // 			error_log(system('time f'));
        $timeExec = 0;
        $_SESSION["index"] = 0;
        $_SESSION["seconds"] = 0;
        $_SESSION["numProb"] = 0;
        for ($i = 1; $i <= 10; $i++) {
            // echo "problems/".$prob_name."/input".$i.".txt";
            // echo "<br>";
            $_SESSION["numProb"] = $i;
            if (file_exists("problems/" . $prob_name . "/input" . $i . ".txt")) {
                //echo "l'erreur est là, chemin du fichier !!";
                $nb_test++;
                $inputContent = file_get_contents("problems/" . $prob_name . "/input" . $i . ".txt");
                $before = intval(microtime(true) * 1000);
                include("compilers/" . $compilerFile);
                $after = intval(microtime(true) * 1000);
                $timeExec += $after - $before;
            }

        }

        // echo "<br>";
        // echo " </tbody>
        // 	</table>
        // </div>";
        $score = $score_final;

        switch ($_SESSION['niveau']) {
            case 'easy':
                $score_final = $score_final + $score_final * 0.1;
                $bonuse = 10;
                break;

            case 'medium':
                $score_final = $score_final + $score_final * 0.2;
                $bonuse = 20;
                break;
            case 'hard':
                $score_final = $score_final + $score_final * 0.3;
                $bonuse = 30;
                break;
        }

        $pourcentage = number_format($score * 10 / $nb_test, 2);
        ///My change
        $team_id = $_SESSION['id_team'];
        $namep = $_SESSION['namep'];

        require './config.php';
        $sql = "select " . $namep . " from  score where id_team =" . $team_id . ";";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        $res = $stmt->fetchAll();
        if ($pourcentage == 100) {
            $sql = "select sum(" . $namep . ") from  score ;";
            $stmt = $conn->prepare($sql);
            $stmt->execute();
            $scoreTousEquipesParProbleme = $stmt->fetchAll()[0][0];
            $avrege = ($scoreTousEquipesParProbleme - $res[0][0]) / ($numberOfTeam * 100);
            $score_final += $bonuse * pow((1 - $avrege), 2);
            $score_final = number_format($score_final, 3);
        }
        if ($res[0][0] <= 160) {
            try {
                $sql = "UPDATE score set " . $namep . "=" . $score_final . " where id_team =" . $team_id . ";";
                $stmt = $conn->prepare($sql);
                $stmt->execute();
            } catch (PDOException $e) {
                echo "<script>console.log('" . $e->getMessage() . "');</script>";
            }
        }
        echo "<center>";
        //echo "<table><tr>";
        //echo "<td><img src=\"images/icons/score.png\" width=\"100\" height=\"80\"></td>";
        echo "<td><h5 style='color:white;font-family:Titillium Web, sans-serif;'>Execution Time :" . intval($_SESSION["seconds"] * 1000) . "ms</h5></td>";
        echo "<td><h3 style='color:white;font-family:Titillium Web, sans-serif;'>Total Score in this Probleme :" . intval($score_final) . " ( <b style=\"color:#ff7676;\">$pourcentage%</b> )</h3></td>";
        echo "<td><h4 style='color:white;font-family:Titillium Web, sans-serif;'>TESTS :" . round($pourcentage * 10 / 100) . "/10</h4></td>";

        //echo "</tr></table>";

        // if ($pourcentage ==100) {
        // 	//echo "<table><tr>";
        // 	//echo "<td style=\"text-align:center;\"><h3 style=\"padding-right: 30px;  margin:0 auto; color:white;\">Bravo vous avez arrivé à atteindre un bon score !</h3></td>";
        // 	echo "<img src=\"images/icons/coupe.png\" width=\"100\" height=\"120\">";
        // 	//echo "</tr></table>";
        // }
        // else if($pourcentage>0 && $pourcentage<100){
        // 	echo "<img src=\"images/icons/happy.png\" width=\"100\" height=\"120\">";
        // }
        // else{
        // 	echo "<img src=\"images/icons/cry.png\" width=\"100\" height=\"120\">";
        // }
        echo "</center>";
    }

    ////////////////////////////////////////////////////////////////////////

    $languageID = $_POST["language"];
    error_reporting(0);
    $code = $_POST["code"];
    if (
        strpos($code, "system") || strpos($code, "subprocess") || strpos($code, "ProcessBuilder") || strpos($code, "command")
        || strpos($code, "Runtime.getRuntime().exec")
        || strpos($code, "regex.Matcher") || strpos($code, "regex.Pattern")
    ) {
        echo "<pre>Not allowed to execute system command!</pre>";
    } else {
        error_log("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
        switch ($languageID) {
            case "c":
            {
                $prob_name = $_SESSION['namep'];
                $code = $_POST["code"];
                $id = $_SESSION['ID'];

                $filename_code = "main.c";
                $filename_error = "error.txt";

                $CC = "gcc";
                $command = $CC . " -lm " . $filename_code;
                $command_error = $command . " 2>" . $filename_error;
                $file_code = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_code, "w+");

                fwrite($file_code, $code);
                fclose($file_code);
                exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_code");
                shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command_error);
                Compiler("c.php");

                //include("compilers/c.php");
                break;
            }

            case "cpp11":
            {
                $prob_name = $_SESSION['namep'];
                $code = $_POST["code"];
                $id = $_SESSION['ID'];
                $CC = "g++ --std=c++11";
                $filename_code = "main.cpp";
                $filename_error = "error.txt";
                $command = $CC . " -lm " . $filename_code;
                $command_error = $command . " 2>" . $filename_error;
                $file_code = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_code, "w+");

                fwrite($file_code, $code);
                fclose($file_code);
                exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_code");
                shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command_error);
                Compiler("cpp11.php");
                //include("compilers/cpp11.php");
                break;
            }
            case "java":
            {
                $prob_name = $_SESSION['namep'];
                $id = $_SESSION['ID'];
                $CC = "javac";
                $out = "timeout 5s java Main";
                $code = $_POST["code"];
                //$input=$_POST["input"];

                $filename_code = "Main.java";
                $filename_error = "error.txt";
                $command = $CC . " " . $filename_code;
                $command_error = $command . " 2>" . $filename_error;


                //if(trim($code)=="")
                //die("The code area is empty");

                $file_code = fopen("scode/" . $id . "/" . $prob_name . "/" . $filename_code, "w+");

                fwrite($file_code, $code);
                fclose($file_code);
                exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_code");

                exec("cd scode/" . $id . "/" . $prob_name . "; " . "chmod 777 $filename_error");

                shell_exec("cd scode/" . $id . "/" . $prob_name . "; " . $command_error);
                Compiler("java.php");
                //include("compilers/java.php");
                break;
            }
            case "python3.2":
            {
                Compiler("python3.php");
                //include("compilers/python3.php");
                break;
            }
        }
    }
    ?>
</div>