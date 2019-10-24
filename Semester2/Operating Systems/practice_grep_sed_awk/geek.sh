#!/bin/bash

NUM=$1
SUM=0

echo "Input: " $NUM

while [ ! $NUM -eq 0 ]; do
	CIF=$(($NUM % 10))
	SUM=$(($SUM + $CIF))
	NUM=$(($NUM / 10))
done 

echo "Output: " $SUM


