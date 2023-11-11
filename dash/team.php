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

//if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_GET['action']) && $_GET['action'] === 'apply') {
//    if (isset($_POST['input_value'])) {
//        $input_value = $_POST['input_value'];
//
//        // Add any additional processing or actions here
//    } else {
//        echo "Input value is not set or empty.";
//    }
//}

$link = mysqli_connect('localhost', 'root', "geeks_hack_2023", 'geekshack3');

//tous les scores de team
$requete1 = "select score.* from score,team where team.id_team = score.id_team and team.team_tag ='$tag';";
$result1 = mysqli_query($link, $requete1);
$nb_team = $result1->num_rows;

//nb des particiapnts
$requete2 = "select username,nom,prenom,email,phone,member_one_username,member_two_username,ecole from team,candidat where team.leader_username = candidat.username and team.team_tag = '$tag';";
$result2 = mysqli_query($link, $requete2);
$nb_condidat = $result2->num_rows;


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
            </label> Solutions de <?php echo $tag; ?>
        </h2>

    </header>

    <main>
        <div class="cards">

            <p>
                <button class="btn btn-primary" onclick="sortTable()">Sort</button>
            </p>
        </div>
        <!--Tableau-->
        <div class="recent-grid">
            <div class="projects">
                <div class="card">
                    <div class="card-header">
                        <h3>Problemes</h3>
                    </div>

                    <div class="card-body">
                        <div class="table-responsive">
                            <table width="100%" id="myTable" data-filter-control="true"
                                   data-show-search-clear-button="true">
                                <thead>
                                <tr>
                                    <td>Problem</td>
                                    <td>Score</td>
                                </tr>
                                </thead>
                                <tbody>
                                <?php if ($row = mysqli_fetch_array($result1)) { ?>
                                    <?php
                                    $num_problems = (count($row) - 1) / 2;
                                    for ($i = 1; $i <= $num_problems; $i++) {
                                        $prob_column = 'prob' . $i;
                                        ?>
                                        <tr style="cursor: pointer"
                                            onclick="window.location.href='probByTeam.php?tag=<?php echo $tag; ?>&prob=<?php echo $i; ?>'">
                                            <td>Problem <?php echo $i; ?></td>
                                            <td><?php echo $row[$prob_column]; ?></td>
                                        </tr>
                                    <?php } ?>

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
                        <h3><?php echo $tag ?> Participants</h3>
                    </div>

                    <div class="card-body">
                        <?php while ($row = mysqli_fetch_array($result2)) { ?>
                            <div class="customer">
                                <div class="info">
                                    <div>
                                        <h4> Leader
                                            : <?php echo $row['username'] . '<br>' . $row['nom'] . ' ' . $row['prenom'] ?> </h4>
                                        <h4> Member1 : <?php echo $row['member_one_username'] ?> </h4>
                                        <h4> Member2 : <?php echo $row['member_two_username'] ?> </h4>
                                        <small> <?php echo $row['ecole'] . ' <> ' . $row['phone'] ?> </small>
                                    </div>
                                </div>
                                <div class="contact">
                                    <a href="mailto: <?php echo $row['email'] ?> "> <span
                                                class="las la-envelope-open"></span></a>
                                </div>
                            </div>

                        <?php } ?>
                    </div>
                </div>
               <!-- <div class="cards" style="margin-top: 5%; margin-left: 20%;">
                    <form action="?tag=<?php /*echo $tag; */?>&action=apply" method="post">
                        <input type="number" style="width: 150%;" name="input_value" required>
                        <input type="submit" class="btn btn-primary" value="Apply"/>
                    </form>
                </div>-->
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
                txtValue = (td1.textContent || td1.innerText) + (td2.textContent || td2.innerText);
                if (txtValue.toUpperCase().indexOf(filter) > -1) {
                    tr[i].style.display = "";
                } else {
                    tr[i].style.display = "none";
                }
            }
        }

    }


    function pickUp() {
        score = document.getElementById("score");
    }
</script>


<script>
    function sortTable() {
        var table, rows, switching, i, x, y, shouldSwitch;
        table = document.getElementById("myTable");
        switching = true;

        while (switching) {
            switching = false;
            rows = table.rows;

            for (i = 1; i < (rows.length - 1); i++) {
                shouldSwitch = false;
                x = parseInt(rows[i].getElementsByTagName("TD")[1].innerHTML);
                y = parseInt(rows[i + 1].getElementsByTagName("TD")[1].innerHTML);

                if (x < y) {
                    shouldSwitch = true;
                    break;
                }
            }

            if (shouldSwitch) {
                rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
                switching = true;
            }
        }
    }

</script>
</html>
