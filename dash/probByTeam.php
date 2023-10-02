<?php
session_start();
function authenticate($password) {
    $credentials = json_decode(file_get_contents('credentials.json'), true);
    return isset($credentials['pass']) && $credentials['pass'] === $password;
}

if (!isset($_SESSION['authenticated']) || !$_SESSION['authenticated']) {
    // Redirect to the login page if not authenticated
    header('Location: login.php');
    exit();
}
$tag = $_GET['tag'];
$prob = $_GET['prob'];

$link = mysqli_connect('localhost', 'root', "Magali_1984", 'tsutnnytsu');

$requete1 = "select score.* from score,team where team.id_team = score.id_team and team.team_tag ='$tag';";
$result1 = mysqli_query($link, $requete1);
$nb_team = $result1->num_rows;

$requete2 = "select team_tag,username,nom,prenom,email,phone,ecole from team,candidat where team.leader_username = candidat.username;";
$result2 = mysqli_query($link, $requete2);
$nb_condidat = $result2->num_rows;

$requete3 = "select id_team from team where team_tag ='$tag' ;";
$result3 = mysqli_query($link, $requete3);

$record = $result3->fetch_array();
$idteam = $record['id_team'];

$requete4 = "select prob$prob from score where id_team = '$idteam' ;";
$result4 = mysqli_query($link, $requete4);

$record4 = $result4->fetch_array();
$lastscore = $record4["prob$prob"];




?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1">
    <title>Dashboard GeeksHack</title>
    <link rel="stylesheet"
          href="https://maxst.icons8.com/vue-static/landings/line-awesome/line-awesome/1.3.0/css/line-awesome.min.css">
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="css/codes.css">
    <!--    <link rel="stylesheet" type="text/css" href="../vendor/bootstrap/css/bootstrap.min.css">-->
    <link rel="icon" href="../assets/logo-geeks.png"/>
</head>

<body>

<input type="checkbox" id="nav-toggle">
<div class="sidebar">
    <div class="sidebar-brand">
        <table>
            <tr>
                <td><img src="geeks.png" style="width: 45px; margin-right: -7px; border-radius:40%; "></img></td>
                <td><h2 onclick="window.location.href='/'" style="cursor:pointer;margin-top: 7px; margin-left: 2px; color: white;">Geeks Club</h2> </td>
            </tr>

        </table>

    </div>
    <!--Secciones-del-tablero-->
    <div class="sidebar-menu">
        <ul>
            <li>
                <span class="las la-home"></span>
                <span style="cursor: pointer" onclick="window.location.href='/dash/'">Mon Dashoard</span>
            </li>
            <li>
                <span class="las la-code"></span>
                <span style="cursor: pointer" onclick="window.location.href='control.php'">Control Codes</span>
            </li>
            <li>
                <span class="las la-door-open"></span>
                <span class="" onclick="window.location.href='logout.php'" style="cursor: pointer" >Logout</span>
            </li>

        </ul>
    </div>
</div>

<div class="main-content">
    <header>
        <h2>
            <label for="nav-toggle">
                <span class="las la-bars"></span>
            </label> Solution Problem <?php echo $prob; ?> de <?php echo $tag; ?>
        </h2>

    </header>

    <main>
        <!--Tableau-->
        <div class="recent-grid">
            <div class="projects">
                <div class="card" style="margin-bottom: 5%;">
                    <div class="card-header">
                        <h3>Code Python</h3>
                    </div>
                    <div class="card-body">
                        <?php
                        $codefile = "../scode/$tag/prob$prob/main.py";
                        echo '<br>';
                        if (file_exists($codefile)) {
                            echo '<pre><code class="python">' . htmlspecialchars(file_get_contents($codefile)) . '</code></pre>';
                        } else {
                            echo "Python code not available.";
                        }
                        ?>
                    </div>
                </div>
                <div class="card" style="margin-bottom: 5%;">
                    <div class="card-header">
                        <h3>Code C</h3>
                    </div>
                    <div class="card-body">
                        <?php
                        $codefile = "../scode/$tag/prob$prob/main.c";
                        echo '<br>';
                        if (file_exists($codefile)) {
                            echo '<pre><code class="c">' . htmlspecialchars(file_get_contents($codefile)) . '</code></pre>';
                        } else {
                            echo "C code not available.";
                        }
                        ?>
                    </div>
                </div>
                <div class="card" style="margin-bottom: 5%;">
                    <div class="card-header">
                        <h3>Code C++</h3>
                    </div>
                    <div class="card-body">
                        <?php
                        $codefile = "../scode/$tag/prob$prob/main.cpp";
                        echo '<br>';
                        if (file_exists($codefile)) {
                            echo '<pre><code class="cpp">' . htmlspecialchars(file_get_contents($codefile)) . '</code></pre>';
                        } else {
                            echo "C++ code not available.";
                        }
                        ?>
                    </div>
                </div>
                <div class="card" style="margin-bottom: 5%;">
                    <div class="card-header">
                        <h3>Code Java</h3>
                    </div>
                    <div class="card-body">
                        <?php
                        $codefile = "../scode/$tag/prob$prob/Main.java";
                        echo '<br>';
                        if (file_exists($codefile)) {
                            echo '<pre><code class="java">' . htmlspecialchars(file_get_contents($codefile)) . '</code></pre>';
                        } else {
                            echo "Java code not available.";
                        }
                        ?>
                    </div>
                </div>
            </div>

            <div class="customers">

                <div class="card">
                    <div class="card-header">
                        <h3>Scoring System</h3>
                    </div>

                    <div class="card-body scoring-system">
                        <label for="scoreInput">Enter Score:</label>
                        <input type="number" id="scoreInput" placeholder="Enter score">

                        <button class="btn btn-primary" style="margin-top: 5%; margin-left: 25%;" onclick="setScore()">
                            Set Score
                        </button>

                        <div class="score-buttons">
                            <button class="btn btn-danger" style="margin-top: 5%; margin-left: 34%;"
                                    onclick="adjustScore(-10)">-10
                            </button>
                        </div>
                    </div>
                </div>
            </div>

        </div>
    </main>

</div>


<script>
    function setScore() {
        const scoreInput = document.getElementById('scoreInput');
        const scoreValue = parseFloat(scoreInput.value);

        if (!isNaN(scoreValue)) {
            // Handle setting the score (you can send it to the server or update the UI)
            console.log('Score set to:', scoreValue);
            // Add logic to update the score as needed
            //todo update score set prob$prob = $value where id_team = $idteam ;
            const xhttp = new XMLHttpRequest();
            const tag = "<?php echo $tag; ?>";  // Retrieve tag from PHP variable
            const prob = <?php echo $prob; ?>;  // Retrieve prob from PHP variable
            const idteam = <?php echo $idteam; ?>;  // Retrieve idteam from PHP variable

            xhttp.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    console.log('Score updated successfully:', scoreValue);
                    window.location.href = '/dash/'
                    // You can update the UI or perform any other actions on successful update
                }
            };

            // Send a POST request to your server to update the score
            xhttp.open("POST", "update_score.php", true);
            xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xhttp.send("score=" + scoreValue + "&tag=" + tag + "&prob=" + prob + "&idteam=" + idteam);
        } else {
            alert('Please enter a valid numeric score.');
        }
    }

    function adjustScore(value) {
        const scoreValue = parseFloat(<?php echo $lastscore; ?>)+value;
        console.log(<?php echo $lastscore; ?>);
        console.log(scoreValue);

        if (!isNaN(scoreValue)) {
            // Handle setting the score (you can send it to the server or update the UI)
            console.log('Score set to:', scoreValue);
            // Add logic to update the score as needed
            //todo update score set prob$prob = $value where id_team = $idteam ;
            const xhttp = new XMLHttpRequest();
            const tag = "<?php echo $tag; ?>";  // Retrieve tag from PHP variable
            const prob = <?php echo $prob; ?>;  // Retrieve prob from PHP variable
            const idteam = <?php echo $idteam; ?>;  // Retrieve idteam from PHP variable

            xhttp.onreadystatechange = function () {
                if (this.readyState === 4 && this.status === 200) {
                    console.log('Score updated successfully:', scoreValue);
                    // You can update the UI or perform any other actions on successful update
                    window.location.href = '/dash/'
                }
            };

            // Send a POST request to your server to update the score
            xhttp.open("POST", "update_score.php", true);
            xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xhttp.send("score=" + scoreValue + "&tag=" + tag + "&prob=" + prob + "&idteam=" + idteam);
        } else {
            alert('Please enter a valid numeric score.');
        }
    }
</script>

</body>
</html>
