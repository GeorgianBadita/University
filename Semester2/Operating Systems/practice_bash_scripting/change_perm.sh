#!/bin/bash 

for F in $(find $1  -type f); do
	IFS=$'\n'
	for line in $(ls -l $F); do
		if echo $line | grep -o 'rw-r--r--';then
			name=$(echo $line | awk '{print $NF}')
			$(chmod 700 $name)
		fi
	done
	IFS=$" "
done
