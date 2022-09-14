<?php
include("methods.php");

$url = @$argv[1];
$body = @$argv[2];
$s3 = @$argv[3];

echo "Api call happens here\n";

if ($url != "" && $body == "") {
    $url = "check-pos-get-banks";
    $banks = getCall($url);
} else {
    $respone = getCallWithBody($url, $body);
    if($url = "check-pos"){
        if($respose['response_code'] == 00 && $respose['can_transfer'] == true){
            echo 1;
        }else{
            echo 0;
        }
     }
}
// printArray($banks);