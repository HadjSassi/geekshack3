<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1">
    <title>Login - Dashboard GeeksHack</title>
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
                <td><img src="geeks.png" style="width: 45px; margin-right: -7px; border-radius:40%; "></img></td>
                <td><h2 onclick="window.location.href='/'" style="cursor:pointer;margin-top: 7px; margin-left: 2px; color: white;">Geeks Club</h2> </td>
            </tr>
        </table>
    </div>
</div>

<div class="main-content">
    <header>
        <h2>
            <label for="nav-toggle">
                <span class="las la-bars"></span>
            </label> Login
        </h2>
    </header>

    <main>
        <div class="cards">
            <h3>Hello Administrator Hadj Sassi Mahdi</h3>
            <form action="auth.php" method="POST" class="login-form">
                <label for="password">Please enter the admin Password:</label>
                <input type="password" style="" id="password" name="password" required>
                <button type="submit" style="margin-top: 10%;" class="btn btn-primary">Login</button>
            </form>
        </div>
    </main>

</div>

</body>

</html>
