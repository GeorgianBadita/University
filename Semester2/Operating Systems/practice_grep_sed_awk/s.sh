#!/bin/bash


for arg in $*; do
	if [ ! -f $arg ]; then
		$arg >> "a.txt"
	fi
done
