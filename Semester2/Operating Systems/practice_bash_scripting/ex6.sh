#!/bin/bash

while [ $1 ]; do
	FILE=$1
	WORD=$2
	COUNT=$3
	#echo $FILE" "$WORD" "$COUNT
	cat $FILE | awk -v word=$WORD -v count=$COUNT '{AP = 0; for(i = 1; i<=NF; i++)if($i == word)AP=AP+1} {if(AP == count) print $0}'
	shift 3
done
