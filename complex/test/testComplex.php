<?php

$c=new trComplex\Complex(-3,-4);
echo $c->mod()."\n";

$d=new trComplex\Complex(4,3);

echo $c->add($d)->mod()."\n";

echo ((string)$d."\n");
       
$f=new \DateTime();
$g=$d->add($f); //Error!
