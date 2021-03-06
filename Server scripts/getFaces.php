<?php
$filenameArray = [];

$dir = "faces/"; 

function scan_dir($dir) {
    $ignored = array('.', '..', '.svn', '.htaccess');

    $files = array();    
    foreach (scandir($dir) as $file) {
        if (in_array($file, $ignored)) continue;
        $files[$file] = filemtime($dir . '/' . $file);
    }

    asort($files);
    $files = array_keys($files);

    return ($files) ? $files : false;
}

echo json_encode(scan_dir($dir));
?>