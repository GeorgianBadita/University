#!/bin/bash

DIR1=$1
DIR2=$2

for F1 in $(find $1); do
	var1=$(echo $F1 | sed 's|[^/]*/||g')
	for F2 in $(find $2); do
		var2=$(echo $F2 | sed 's|[^/]*/||g')
		if [ "$var1" == "$var2" ]; then
			echo $F2 
		fi
	done
done
