<?php

$c=new Complex(-3,-4);
echo $c->mod()."\n";

$d=new Complex(4,3);
$e=$d->add($c);

echo ($d->mod()."\n");
echo ((string)$d."\n");
       
var_dump($e);

echo ($e->mod()."\n");
