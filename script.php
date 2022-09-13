<?php
include("methods.php");

$s1 = @$argv[1];
$s2 = @$argv[2];
$s3 = @$argv[3];

echo "Api call happens here\n";

if ($s1 != "" && $s2 == "") {
    $url = "check-pos-get-banks";
    $banks = getCall($url);
} else {
    $respone = getCallWithBody($s1, $s2);
}
// printArray($banks);