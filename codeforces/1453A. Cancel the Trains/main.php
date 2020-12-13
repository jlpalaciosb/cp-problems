<?php

$f = fopen('php://stdin', 'r');

function to_int_arr($arr) {
    return array_map(function ($arri) {
        return intval($arri);
    }, $arr);
}

function solve($n, $m) {
    global $f;
    $a = to_int_arr(explode(' ', fgets($f)));
    $b = to_int_arr(explode(' ', fgets($f)));
    $ans = 0;
    for ($i = 0, $j = 0; $i < $n and $j < $m;) {
        if ($a[$i] < $b[$j]) {
            $i++;
        } elseif ($a[$i] > $b[$j]) {
            $j++;
        } else {
            $ans++;
            $i++;
            $j++;
        }
    }
    echo "${ans}\n";
}

$t = intval(fgets($f));
while ($t) {
    [$n, $m] = to_int_arr(explode(' ', fgets($f)));
    solve($n, $m);
    $t -= 1;
}

fclose($f);
