#!/bin/bash


for param in $*; do
	if [ -f $param ];then
		echo "It's a file: " $(wc -m $param)
	elif [ -d $param ];then
		NR=0
		for f in $(find $param -type f);do
			NR=$(($NR+1))
		done
		echo "It's a dir: " $param " " $NR
	fi
done
