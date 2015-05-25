#!/bin/bash
HELLO=Hello 
function hello {
    local HELLO=World
    echo $HELLO
}
echo $HELLO
hello
echo $HELLO

one=1
Number=32
Count=0 

function how {
    one=`expr $Count + 1`
    echo $one
}
how
how
how
echo $one 

#
#function progress{
#    Count=`expr $Count + $one`
#    echo -e "\033[33m $Count/$Number \033[0m"
#}
#progress
#progress
