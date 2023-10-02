<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $problemNumber = $_POST['problemNumber'];
    $folderToDelete = '../problems/' . $problemNumber;

    // Recursive function to delete a folder and its contents
    function deleteFolder($dir) {
        if (!is_dir($dir)) {
            return false;
        }

        $files = array_diff(scandir($dir), array('.', '..'));
        foreach ($files as $file) {
            (is_dir("$dir/$file")) ? deleteFolder("$dir/$file") : unlink("$dir/$file");
        }

        return rmdir($dir);
    }

    // Delete the folder and its contents
    if (deleteFolder($folderToDelete)) {
        echo "Folder deleted successfully!";
    } else {
        echo "Error deleting folder.";
    }
} else {
    echo "Invalid request method.";
}
?>
