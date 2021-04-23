#!/bin/bash

# gcc command for compile C source file

# judge argument's number
if [ $# != 1 ]
then
    echo Usage: ./compile.sh '*.c'
    exit
fi

# gcc
gcc -g $1 -o a.out
