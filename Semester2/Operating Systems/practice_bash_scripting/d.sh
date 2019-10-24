#!/bin/bash -x 

read char


if [ $char="y" -o $char="Y" ]; then
	echo "YES"
elif [ $char="n" -o $char="N" ]; then
	echo "NO"
fi
