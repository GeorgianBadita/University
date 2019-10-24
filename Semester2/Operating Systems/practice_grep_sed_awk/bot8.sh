#!/bin/bash

for file in $(find $1 -type f); do
	name=$(echo $file | grep -o '/[^/]*$')
	len=$(echo $name | wc -m)
	len=$(($len-2))
	#echo $file
	if [ $len -lt 8 ]; then
	#	echo $file
		if [[ $name == *.txt ]]; then
			IFS='\n'
			for line in $(head -n +10 $file); do
				echo $line
			done
			IFS=' '
		fi
	fi
	
done
