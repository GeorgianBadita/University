#!/bin/bash

COUNT=0
SUM=0

for file in $(find $1 -type f); do
	if [[ $file == *.txt ]]; then
		NUM=$(wc -l $file | grep -o "^[0-9]*")
		SUM=$(($SUM+$NUM))
		COUNT=$(($COUNT+1))
	fi
done

SUM=$(($SUM/$COUNT))
echo $SUM
exit 0
