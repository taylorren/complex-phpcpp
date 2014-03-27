<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

echo "Testing helloWorld in skeleton.so\n";
echo helloWorld('Taylor'); 
echo helloWorld(1234+5678);
echo helloWorld(['string', 123+456]);//
echo "================\n";

$a = 10;
$b = 20;
// swap($a); causes a segment fault
swap($a, $b);
echo $a . "|" . $b . "\n";

$c = 10;
$d = "string";
swap($c, $d);
echo $c . "|" . $d . "\n";

$e = 10;
$f = new \DateTime();
swap($e, $f);
var_dump($e);
var_dump($f);

echo "================\n";

class sampleClass
{

    var $i;

    public function __construct($n)
    {
        $this->i = $n;
    }

}

;

$o1 = new sampleClass(10);
$o2 = new sampleClass(20);

swapObject($o1, $o2);
echo $o1->i . "|" . $o2->i . "\n";

class anotherClass
{
    
}

;
$d1 = new anotherClass();
$d2 = new anotherClass();

try
{
    swapObject($d1, $d2);
} catch (Exception $ex)
{
    echo "Something terrible happened.\n";
}
