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
$link = mysqli_connect('localhost', 'root', "geeks_hack_2023", 'geekshack3');


//nb des particiapnts 
$requete2= "select team_tag,username,nom,prenom,email,phone,ecole from team,candidat where team.leader_username = candidat.username;";
$result2 = mysqli_query($link, $requete2);
$nb_condidat = $result2->num_rows;

function getProblemDetails($problemFolder) {
    $problemFiles = glob($problemFolder . '/* *.html');
    $difficulty = "unknown";  // Default difficulty if not determined
    $problemNumber = basename($problemFolder);

    // Read the problem name from "titre.txt"
    $titreFilePath = $problemFolder . '/titre.txt';
    if (file_exists($titreFilePath)) {
        $problemName = file_get_contents($titreFilePath);
    } else {
        $problemName = "Unknown Problem Name";
    }

    foreach ($problemFiles as $file) {
        $fileName = basename($file);

        // Assuming the filename is in the format "prob1 easy.html"
        $fileParts = explode(' ', $fileName);
        if (count($fileParts) >= 2) {
            // Extracting difficulty from the filename
            $difficulty = str_replace('.html', '', $fileParts[1]);
        }
    }

    return array(
        'problemNumber' => $problemNumber,
        'problemName' => $problemName,
        'difficulty' => $difficulty
    );
}

$problemsData = array();

// Get problem details for each problem folder
$problemFolders = glob('../problems_all/prob*/', GLOB_ONLYDIR);
foreach ($problemFolders as $problemFolder) {
    $problemDetails = getProblemDetails($problemFolder);
    $problemsData[] = $problemDetails;
}

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1">
    <title>Dashboard GeeksHack</title>
    <link rel="stylesheet" href="https://maxst.icons8.com/vue-static/landings/line-awesome/line-awesome/1.3.0/css/line-awesome.min.css">
    <link rel="stylesheet" href="css/style.css">
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
                <span class="active las la-code"></span>
                <span class="active">Control Codes</span>
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
            </label> Mon Dashoard
        </h2>

        <div class="search-wrapper">
            <span class="las la-search"></span>
            <input type="search" placeholder="Rechercher" id="myInput" onkeyup='tableSearch()' />
        </div>
    </header>

    <main>
        <div class="recent-grid" >
            <div class="projects">
                <div class="card">
                    <div class="card-header">
                        <h3>Problems</h3>
                    </div>

                    <div class="card-body">
                        <div class="table-responsive">
                            <table width="120%"  id ="myTable" data-filter-control="true" data-show-search-clear-button="true">
                                <thead>
                                <tr>
                                    <td>Problem Number</td>
                                    <td>Problem Name</td>
                                    <td>Problem Difficulty</td>
                                    <td>Actions</td>
                                </tr>
                                </thead>
                                <tbody>
                                <?php foreach ($problemsData as $problem) { ?>
                                    <tr>
                                        <td onclick="window.location.href='../problems_all/<?php echo $problem['problemNumber']; ?>/<?php echo $problem['problemNumber']; ?> <?php echo $problem['difficulty']; ?>.html'"
                                            style="cursor: pointer;"><?php echo $problem['problemNumber']; ?></td>
                                        <td onclick="window.location.href='../problems_all/<?php echo $problem['problemNumber']; ?>/<?php echo $problem['problemNumber']; ?> <?php echo $problem['difficulty']; ?>.html'"
                                            style="cursor: pointer;"><?php echo $problem['problemName']; ?></td>
                                        <td onclick="window.location.href='../problems_all/<?php echo $problem['problemNumber']; ?>/<?php echo $problem['problemNumber']; ?> <?php echo $problem['difficulty']; ?>.html'"
                                            style="cursor: pointer;"><?php echo $problem['difficulty']; ?></td>

                                        <td>
                                            <button class="btn btn-primary" style="margin-right: 3%;" onclick="copyProblemFolder('<?php echo $problem['problemNumber']; ?>')">Add</button>
                                            <button class="btn btn-danger" style="" onclick="deleteProblemFolder('<?php echo $problem['problemNumber']; ?>')">Revoke</button>
                                        </td>
                                    </tr>
                                <?php } ?>
                                </tbody>
                            </table>
                        </div>
                    </div>

                </div>
            </div>

            <div class="customers">

                <div class="card">
                    <div class="card-header">
                        <h3>Mes Participants</h3>
                    </div>

                    <div class="card-body">
                        <?php while ($row = mysqli_fetch_array($result2)) { ?>
                            <div class="customer">
                                <div class="info">
                                    <div>
                                        <h4>    <?php echo $row['team_tag'].' <> '.$row['username'].' <br> <h5>'.$row['nom'].' '.$row['prenom'].'</h5>' ?> </h4>
                                        <small> <?php echo $row['ecole'].' <> '.$row['phone'] ?> </small>
                                    </div>
                                </div>
                                <div class="contact">
                                    <a href="mailto: <?php echo $row['email'] ?> ">  <span class="las la-envelope-open" ></span></a>
                                </div>
                            </div>

                        <?php } ?>
                    </div>
                </div>
            </div>

        </div>
    </main>

</div>

</body>
<script>
    function tableSearch() {
        let input, filter, table, tr, td1, txtValue;

        //Intialising Variables
        input = document.getElementById("myInput");
        filter = input.value.toUpperCase();
        table = document.getElementById("myTable");
        tr = table.getElementsByTagName("tr");

        for (let i = 0; i < tr.length; i++) {
            td1 = tr[i].getElementsByTagName("td")[0];
            td2 = tr[i].getElementsByTagName("td")[1];
            if (td1 || td2) {
                txtValue =( td1.textContent || td1.innerText)+( td2.textContent || td2.innerText);
                if (txtValue.toUpperCase().indexOf(filter) > -1) {
                    tr[i].style.display = "";
                } else {
                    tr[i].style.display = "none";
                }
            }
        }

    }


    function pickUp(){
        score = document.getElementById("score");
    }

    function copyProblemFolder(problemNumber) {
        // Send an AJAX request to the PHP script to copy the folder
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "copy_folder.php", true);
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xhr.onreadystatechange = function () {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    alert("Folder copied successfully!");
                } else {
                    alert("Error copying folder: " + xhr.statusText);
                }
            }
        };
        xhr.send("problemNumber=" + problemNumber);
    }
    function deleteProblemFolder(problemNumber) {
        // Send an AJAX request to the PHP script to copy the folder
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "delete_folder.php", true);
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
        xhr.onreadystatechange = function () {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    alert("Folder deleted successfully!");
                } else {
                    alert("Error deleting folder: " + xhr.statusText);
                }
            }
        };
        xhr.send("problemNumber=" + problemNumber);
    }
</script>
</html>
