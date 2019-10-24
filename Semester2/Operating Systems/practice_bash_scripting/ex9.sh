#!/bin/bash

FILE=$1
for F in $(find $FILE  -type f); do
	NAME=$(echo "$F" | grep -o '[^/]*$')
	echo $NAME
	if [ ${#NAME} -lt 8 ]; then
		DATA=$(file $F)
		if echo $DATA | grep -q "ASCII text"; then
			printf "%s\n" $(head -n+10 $F)
		fi
	fi
done
