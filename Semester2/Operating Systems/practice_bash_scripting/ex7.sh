#!/bin/bash

for F in $*; do
	if [ -f $F ]; then
		cat $F | sort | uniq -c | sort -n -r | sed 's/^ *[0-9]//g' 
	fi
done
