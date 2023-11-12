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

// Fetch all candidates ordered by state descending
$requeteTeam = "SELECT * FROM team ORDER BY state ";
$resultTeam = mysqli_query($link, $requeteTeam);

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1">
    <title>Control Candidates</title>
    <link rel="stylesheet" href="https://maxst.icons8.com/vue-static/landings/line-awesome/line-awesome/1.3.0/css/line-awesome.min.css">
    <link rel="stylesheet" href="css/style.css">
    <link rel="icon" href="../assets/logo-geeks.png"/>
</head>

<body>

<input type="checkbox" id="nav-toggle">
<div class="sidebar">
    <div class="sidebar-brand">
        <table>
            <tr>
                <td><img src="geeks.png" style="width: 45px; margin-right: -7px; border-radius:40%; "></td>
                <td><h2 onclick="window.location.href='/'" style="cursor:pointer;margin-top: 7px; margin-left: 2px; color: white;">Geeks Club</h2> </td>
            </tr>
        </table>
    </div>
    <div class="sidebar-menu">
        <ul>
            <li>
                <span class="las la-home"></span>
                <span style="cursor: pointer" onclick="window.location.href='/dash/'">Mon Dashoard</span>
            </li>
            <li>
                <span class=" las la-users"></span>
                <span style="cursor: pointer" onclick="window.location.href='control_candidates.php'">Control Candidates</span>
            </li>
            <li>
                <span class="active las la-users"></span>
                <span style="cursor: pointer" onclick="window.location.href='control_teams.php'">Control Teams</span>
            </li>
            <li>
                <span class=" las la-code"></span>
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
            </label> Control Teams
        </h2>

        <div class="search-wrapper">
            <span class="las la-search"></span>
            <input type="search" placeholder="Rechercher" id="myInput" onkeyup='tableSearch()' />
        </div>
    </header>

    <main>
        <div class="recent-grid" >
            <div class="projects">
                <div class="">
                    <div class="card-header">
                        <h3>Teams</h3>
                    </div>

                    <div class="card-body">
                        <div class="">
                            <table width="120%" id ="myTable" data-filter-control="true" data-show-search-clear-button="true">
                                <thead>
                                <tr>
                                    <td>Team Tag</td>
                                    <td>Leader</td>
                                    <td>State</td>
                                </tr>
                                </thead>
                                <tbody>
                                <?php while ($row = mysqli_fetch_assoc($resultTeam)) { ?>
                                    <tr style="cursor: pointer" onclick="window.location.href='teams.php?tag=<?php echo $row['team_tag']; ?>'">
                                        <td><?php echo $row['team_tag']; ?></td>
                                        <td><?php echo $row['leader_username']; ?></td>
                                        <td><?php echo $row['state']; ?></td>
                                    </tr>
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
    function tableSearch() {
        let input, filter, table, tr, td1, txtValue;

        // Initializing Variables
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
</script>

</html>
