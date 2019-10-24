#!/bin/bash 


CMD=""
CMP=";"

for C in $*; do
	if [ "$C" = "$CMP" ]; then
		$CMD
		CMD=""
	else
		CMD=$CMD" "$C
	fi	
done

