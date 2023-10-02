<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GeeksHack Pre-Registration Form</title>
    <link rel="icon" href="assets/logo-geeks.png"/>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/style.css"> <!-- Create a separate CSS file for your custom styles -->
    <style>
        body {
            color: white;
            background-image: url('assets/bg.jpg'); /* Replace with the actual path to your background image */
            /*background-size: cover;*/
            /*background-repeat: no-repeat;*/
            /*background-attachment: fixed;*/
            /*position: relative; !* Make sure the overlay is positioned relative to this element *!*/
            backdrop-filter: blur(10px);
        }
        #errorModalContent {
            color: black;
        }

    </style>
</head>
<body>
<video autoplay loop muted>
    <source src="your-video-file.mp4" type="video/mp4"> <!-- Replace with your video source -->
    Your browser does not support the video tag.
</video>
<div class="container" style="margin-top: -9%;">
    <div class="text-center mt-4 mb-4">
        <h1>GeeksHack Pre-Registration Form</h1>
    </div>

    <form action="inscri.php" method="post" enctype="multipart/form-data" onsubmit="return validatePhoneNumber()">
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="nom">Nom:</label>
                <input type="text" class="form-control" id="nom" name="nom" required>
            </div>

            <div class="form-group col-md-6">
                <label for="prenom">Prénom:</label>
                <input type="text" class="form-control" id="prenom" name="prenom" required>
            </div>
        </div>

        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="email">Email:</label>
                <input type="email" class="form-control" id="email" name="email" required>
            </div>

            <div class="form-group col-md-6">
                <label for="phone">Phone:</label>
                <input type="text" class="form-control" id="phone" name="phone" required>
            </div>
        </div>

        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="ecole">École:</label>
                <input type="text" class="form-control" id="ecole" name="ecole" required>
            </div>

            <div class="form-group col-md-6">
                <label for="preuve_etudiant">Preuve d'étudiant: Photo de la carte étudiant</label>
                <input type="file" class="form-control-file" id="preuve_etudiant" name="preuve_etudiant" required>
            </div>
        </div>

        <div class="text-center">
            <button type="submit" class="btn btn-primary">Submit</button>
        </div>
    </form>
</div>

<video autoplay loop muted>
    <source src="your-video-file.mp4" type="video/mp4"> <!-- Replace with your video source -->
    Your browser does not support the video tag.
</video>
<script>
    function validatePhoneNumber() {
        const phoneNumberInput = document.getElementById('phone');
        const phoneNumber = phoneNumberInput.value;

        // Check if the phone number is exactly 8 digits
        if (!/^\d{8}$/.test(phoneNumber)) {
            displayErrorModal('Phone number must be 8 digits.');
            return false;  // Prevent form submission
        }

        return true;  // Allow form submission
    }
    // Function to display the error message in a modal
    function displayErrorModal(errorMessage) {
        const modal = document.getElementById('errorModal');
        const modalContent = document.getElementById('errorModalContent');
        modalContent.innerText = errorMessage;
        modal.style.display = 'block';
    }

    // Close the modal when the user clicks outside of it
    window.onclick = function(event) {
        const modal = document.getElementById('errorModal');
        if (event.target === modal) {
            modal.style.display = 'none';
        }
    }
</script>

<!-- Add a modal for displaying errors -->
<div id="errorModal" class="modal">
    <div class="modal-content">
        <span class="close" onclick="document.getElementById('errorModal').style.display='none'">&times;</span>
        <div id="errorModalContent"></div>
    </div>
</div>
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
</body>
</html>
