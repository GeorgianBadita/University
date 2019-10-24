#!/bin/bash


for F in $(find -type f); do
	if [[ $F == *.txt ]]; then
		NUM=$(wc -l $F | grep -o  "[0-9]*")
		if [ $NUM -lt 10 ]; then
			cat $F
		else
			for line in  $(head -n+5 $F); do
				echo $line
			done
			for line in $(tail -n-5 $F); do
				echo $line
			done
		fi
	fi
done
