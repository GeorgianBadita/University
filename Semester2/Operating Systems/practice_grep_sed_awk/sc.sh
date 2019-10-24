#!/bin/bash


for elem in $*; do
	if [ $(($elem % 15)) -eq 0 ]; then
		echo $elem
	fi
done
