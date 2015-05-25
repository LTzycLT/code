#!/bin/bash
HELLO=Hello
function gao {
    local HELLO=World
    echo $HELLO
}
echo $HELLO
gao
echo $HELLO
