<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $problemNumber = $_POST['problemNumber'];
    $source = '../problems_all/' . $problemNumber;
    $destination = '../problems/' . $problemNumber;

    // Recursive copy of the folder
    function copyFolder($src, $dst) {
        $dir = opendir($src);
        @mkdir($dst);

        while (($file = readdir($dir))) {
            if ($file != '.' && $file != '..') {
                if (is_dir($src . '/' . $file)) {
                    copyFolder($src . '/' . $file, $dst . '/' . $file);
                } else {
                    copy($src . '/' . $file, $dst . '/' . $file);
                }
            }
        }

        closedir($dir);
    }

    copyFolder($source, $destination);
    echo "Folder copied successfully!";
} else {
    echo "Invalid request method.";
}
?>
