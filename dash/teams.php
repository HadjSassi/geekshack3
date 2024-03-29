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

//tous les infos sur le candidat
$requete1 = "select * from team where team_tag = '$tag'";
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
            </label> <?php echo $tag; ?>
        </h2>

    </header>

    <main>
        <!-- Add the following code to display the image and the button for the selected candidate -->
        <main>
            <?php
            // Fetch the candidate information
            if ($row = mysqli_fetch_assoc($result1)) {
                ?>
                <div class="candidate-info">
                    <h3>Team Information</h3>
                    <p>Team Id: <?php echo $row['id_team']; ?></p>
                    <p>Team Tag: <?php echo $row['team_tag']; ?></p>
                    <p>Credentials: <?php echo $row['login'] . ':' . $row['password']; ?></p>
                    <p>Leader Username: <?php echo $row['leader_username']; ?></p>
                    <p>Member 2: <?php echo $row['member_one_username']; ?></p>
                    <p>Member 3: <?php echo $row['member_two_username']; ?></p>
                    <p>State: <?php echo $row['state']; ?></p>
                </div>

                <!-- Display the image -->
                <div class="candidate-image">
                    <h3>Student Proof</h3>
                    <?php
                    $imagePath = '../' . $row['preuve']; // Change this path to the actual path
                    ?>
                    <img  style="max-width: 100%; height: auto"  src="<?php echo $imagePath; ?>" alt="Student Proof">
                </div>
                <!-- Accepter button and form -->
                <form id="acceptForm" action="update_team_state.php?tag=<?php echo $row['team_tag']; ?>" method="post">
                    <!-- Add a hidden input field to pass the username to the server -->
                    <input type="hidden" disabled name="username" value="<?php echo $row['team_tag']; ?>">

                    <!-- Stylish Accepter button -->
                    <button class="btn btn-info" type="button" onclick="acceptCandidate()">Accepter</button>
                </form>
                <script>
                    // JavaScript function to handle the button click
                    function acceptCandidate() {
                        var confirmAccept = confirm("Are you sure you want to accept this team?");
                        if (confirmAccept) {
                            // Submit the form
                            document.getElementById('acceptForm').submit();
                        }
                    }
                </script>
            <?php } ?>
        </main>

    </main>

</div>

</body>
</html>
