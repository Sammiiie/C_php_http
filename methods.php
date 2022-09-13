<?php

function printArray($value)
{
    echo "<pre>", print_r($value, true), "</pre>";
}
/**
 * @param $url
 * @return mixed
 */
function getCall($url)
{
    $curl = curl_init();
    if (!$curl) {
        "Something went wrong";
    } else {

        curl_setopt_array($curl, array(
            CURLOPT_URL => "https://zingerad.zingerwallet.com/api/v1/$url/",
            CURLOPT_RETURNTRANSFER => true,
            CURLOPT_ENCODING => '',
            CURLOPT_MAXREDIRS => 10,
            CURLOPT_TIMEOUT => 0,
            CURLOPT_FOLLOWLOCATION => true,
            CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
            CURLOPT_CUSTOMREQUEST => 'GET',
            CURLOPT_SSL_VERIFYHOST => 0, // Sloves Error:SSL certificate problem: unable to get local issuer certificate
            CURLOPT_SSL_VERIFYPEER => 0  //Ensure to verify on production
        ));

        $response = curl_exec($curl);

        $response = json_decode($response, true);
        if (curl_errno($curl)) {
            echo 'Error:' . curl_error($curl);
        }
        curl_close($curl);
        return $response;
    }
}

function getCallWithBody($url, $body)
{
    $curl = curl_init();

    curl_setopt_array($curl, array(
        CURLOPT_URL => "https://zingerad.zingerwallet.com/api/v1/$url/",
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => '',
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 0,
        CURLOPT_FOLLOWLOCATION => true,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => 'GET',
        CURLOPT_POSTFIELDS => "$body",
        CURLOPT_HTTPHEADER => array(
            'Content-Type: application/json'
        ),
    ));

    $response = curl_exec($curl);

    curl_close($curl);
    return $response;
}
