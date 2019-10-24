#!/bin/bash

#First argument name of the program
#Second argument the output file



COMPILE=$(gcc -Wall -g -o $1 $1".c")
$COMPILE
RUN=$(./$1 > $2)
$RUN
