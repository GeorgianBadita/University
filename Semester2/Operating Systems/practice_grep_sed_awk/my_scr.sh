#!/bin/bash

SUM=0

for file in *; do
	VAR=$(stat $file)
	if echo $VAR | grep -q 'Modify: [0-9]\{4\}-06'; then
		TO_ADD=$(echo $(du -b $file) | awk '{print $1}')
		SUM=$(($SUM+$TO_ADD)) 
	fi
	#echo $(stat $file | grep "Modify: [0-9]\{4\}-06")
done

echo $SUM
