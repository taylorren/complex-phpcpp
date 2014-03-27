<?php

$c=new trComplex\Complex(-3,-4);
echo $c->mod()."\n";

$d=new trComplex\Complex(4,3);
$e=$d->add($c)->add($c);

echo ($d->mod()."\n");
echo ((string)$d."\n");
       
echo ($e->mod()."\n");

$f=new \DateTime();
try
{
    $g=$d->add($f); //Error!
}
catch (Exception $e)
{
    echo "Something horrible happened.";
}
