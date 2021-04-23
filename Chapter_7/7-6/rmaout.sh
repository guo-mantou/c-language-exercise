#!/bin/bash

# rm a.out in specified directory

if [ $# != 1 ]
then
    echo Usage: ./rmaout.sh 'dir'
    exit
fi

# rm
if [ ! -d $1 ]
then
    echo 'The directory does not seem to exit!'
    exit
fi

find $1 -name 'a.out' -delete

