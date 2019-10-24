#!/bin/bash

COUNT=0
SUM=0
for F in $(find $1 -type f); do
	if [[ $F == *.txt ]]; then	
		NUM=$(wc -l $F | grep -o "^[0-9]*") 	
		SUM=$(($SUM+$NUM))
		COUNT=$(($COUNT+1))
	fi
done

if [ $COUNT -eq 0 ]; then
	echo "Nu exista fisiere text in director"
	exit 0
fi

SUM=$(($SUM/$COUNT))
echo $SUM
exit 0

