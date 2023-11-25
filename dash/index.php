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

//nb des equipes 
$requete1= "select * from team ";
$result1 = mysqli_query($link, $requete1);
$nb_team = $result1->num_rows;

//nb des particiapnts 
$requete2= "select team_tag,username,nom,prenom,email,phone,ecole from team,candidat where team.leader_username = candidat.username;";
$result2 = mysqli_query($link, $requete2);
$nb_condidat = $result2->num_rows;

//calcul de meilleur score
$requete3 = "select max(prob1) as max from score  ;";
$result3= mysqli_query($link, $requete3);

$record = $result3->fetch_array();
$score_max = $record['max'];

 
//
/*$requete4 = "select team.team_tag as nom_equipe , team.leader_username as leader , sum(score.prob1) as sum_score from team , 
             score  where team.id_team = score.id_team  group by team.id_team order by score.id_team DESC ";
             


$result4= mysqli_query($link, $requete4);
*/
//
$requete5 = "select team.team_tag as nom_equipe , 
                    team.leader_username as leader , 
                    score.prob1+ score.prob1 + score.prob3 + score.prob4+ score.prob5 + score.prob6 + score.prob7 + score.prob8+score.prob9 + score.prob10 + score.prob11 + score.prob12 + score.prob13 + score.prob14 + score.prob15 + score.prob16 
                        + score.prob17 as sum_score
             from team ,  score  
             where team.id_team = score.id_team  group by team.id_team order by team.id_team DESC ";


$result5= mysqli_query($link, $requete5);
// Calculate the ranking
$ranking = 1;
$prevScore = PHP_INT_MAX;
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
                    <span class="active las la-home"></span>
                    <span class="active">Mon Dashoard</span>
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
                </label> Mon Dashoard
            </h2>

            <div class="search-wrapper">
                <span class="las la-search"></span>
                <input type="search" placeholder="Rechercher" id="myInput" onkeyup='tableSearch()' />
            </div>
        </header>

        <main>
            <div class="cards">

<!--                <p><button class="btn btn-primary" onclick="sortTable()">Sort</button></p>-->
            </div>
            <!--Tableau-->
            <div class="recent-grid" >
                <div class="projects">
                    <div class="card">
                        <div class="card-header">
                            <h3>Equipes</h3>
                        </div>

                        <div class="card-body">
                            <div class="table-responsive">
                                <table width="100%" id="myTable" data-filter-control="true" data-show-search-clear-button="true">
                                    <thead>
                                    <tr>
                                        <td>Ranking</td>
                                        <td>Nom d'Equipe</td>
                                        <td>Chef d'Equipe</td>
                                        <td>Score</td>
                                    </tr>
                                    </thead>
                                    <tbody>
                                    <?php
                                    while ($row = mysqli_fetch_array($result5)) { ?>
                                        <tr style="cursor: pointer" onclick="window.location.href='team.php?tag=<?php echo $row['nom_equipe']; ?>'">
                                            <td><?php
                                                // Display ranking only when the score changes
                                                if ($row['sum_score'] < $prevScore) {
                                                    echo $ranking;
                                                    $prevScore = $row['sum_score'];
                                                }
                                                ?>
                                            </td>
                                            <td><?php echo $row['nom_equipe']; ?></td>
                                            <td><?php echo $row['leader']; ?></td>
                                            <td style="color: white;"><?php echo $row['sum_score']; ?></td>
                                        </tr>
                                        <?php
                                        $ranking++;
                                    } ?>
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
</script>



<script>
function sortTable() {
  var table, rows, switching, i, x, y, shouldSwitch;
  table = document.getElementById("myTable");
  switching = true;
  /*Make a loop that will continue until
  no switching has been done:*/
  while (switching) {
    //start by saying: no switching is done:
    switching = false;
    rows = table.rows;
    /*Loop through all table rows (except the
    first, which contains table headers):*/
    for (i = 1; i < (rows.length - 1); i++) {
      //start by saying there should be no switching:
      shouldSwitch = false;
      /*Get the two elements you want to compare,
      one from current row and one from the next:*/
      x = rows[i].getElementsByTagName("TD")[2];
      y = rows[i + 1].getElementsByTagName("TD")[2];
      //check if the two rows should switch place:
      if (parseInt(x.innerHTML) < parseInt(y.innerHTML) ) {
        //if so, mark as a switch and break the loop:
        shouldSwitch = true;
        break;
      }
    }
    if (shouldSwitch) {
      /*If a switch has been marked, make the switch
      and mark that a switch has been done:*/
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
    }
  }
}
</script>
<script>
    // Function to sort the table when the page loads
    window.onload = function () {
        sortTable();
    };

</script>
</html>
