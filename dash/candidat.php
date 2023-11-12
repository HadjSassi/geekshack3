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
$tag = $_GET['id'];

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

//tous les infos sur le candidat
$requete1 = "select * from candidat where username = $tag";
$result1 = mysqli_query($link, $requete1);
$nb_team = $result1->num_rows;



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
                <span class="las la-users"></span>
                <span style="cursor: pointer" onclick="window.location.href='control_candidates.php'">Control Candidates</span>
            </li>
            <li>
                <span class="las la-users"></span>
                <span style="cursor: pointer" onclick="window.location.href='control_teams.php'">Control Teams</span>
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
        <!-- Add the following code to display the image and the button for the selected candidate -->
        <div class="recent-grid">
            <div class="projects">
                <div class="card">
                    <div class="card-header">
                        <h3>Problemes</h3>
                    </div>
                    <div class="card-body">
                        <div class="table-responsive">
                            <table width="100%" id="myTable" data-filter-control="true" data-show-search-clear-button="true">
                                <thead>
                                <tr>
                                    <td>Problem</td>
                                    <td>Score</td>
                                    <td>Preuve Etudiant</td>
                                    <td>Action</td>
                                </tr>
                                </thead>
                                <tbody>
                                <?php if ($row = mysqli_fetch_array($result1)) { ?>
                                    <?php
                                    $num_problems = (count($row) - 1) / 2;
                                    for ($i = 1; $i <= $num_problems; $i++) {
                                        $prob_column = 'prob' . $i;
                                        $preuve_etudiant_column = 'preuve_etudiant' . $i;
                                        ?>
                                        <tr style="cursor: pointer">
                                            <td>Problem <?php echo $i; ?></td>
                                            <td><?php echo $row[$prob_column]; ?></td>
                                            <!-- Display the image -->
                                            <td><img src="<?php echo $row[$preuve_etudiant_column]; ?>" alt="Preuve Etudiant" style="max-width: 100px; max-height: 100px;"></td>
                                            <!-- Add a button for accepting registration -->
                                            <td>
                                                <button onclick="acceptRegistration('<?php echo $tag; ?>', '<?php echo $row[$preuve_etudiant_column]; ?>')">Accept Registration</button>
                                            </td>
                                        </tr>
                                    <?php } ?>
                                <?php } ?>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </main>

</div>

</body>
<script>
    function acceptRegistration(username, preuveEtudiant) {
        // You can implement your logic here to handle the registration acceptance
        // For example, you can send an AJAX request to a PHP script that updates the database
        // and performs any other necessary actions.

        // For demonstration purposes, let's show an alert.
        alert('Registration accepted for ' + username);

        // You can redirect or perform any other actions after accepting the registration.
    }
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
