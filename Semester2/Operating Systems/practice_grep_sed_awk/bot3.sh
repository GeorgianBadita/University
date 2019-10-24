#!/bin/bash

for file in *.txt; do
	LINES=$(wc -l $file | grep -o "^[0-9]* ")
	if [ $LINES -lt 10 ]; then
		cat $file
	else
		#echo $(head -n +5 $file)
		#echo $(tail -n -5 $file)
		IFS='\n'
		for line in $(head -n +5 $file); do
			echo $line
		done

		for line in $(tail -n -5 $file); do
			echo $line
		done
		IFS=''
	fi
done
