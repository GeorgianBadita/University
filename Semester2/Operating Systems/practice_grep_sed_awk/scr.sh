#!/bin/bash

echo $0

for arg in $*; do
	if [ ! -f $arg -a ! -d $arg ];then
		echo $arg
	fi
done
