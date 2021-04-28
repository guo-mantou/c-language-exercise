#!/bin/bash
# compile bluetooth *.c to executable file

# judge argument's number
if [ $# != 2 ]
then
    echo Usage: ./$0 [filename] [filename.c]
    exit
fi


gcc -g -o $1 $2 -lbluetooth
