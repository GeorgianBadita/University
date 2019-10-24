#!/bin/bash

CMD=""
for i in $*; do
	if [ "$i" == ";" ]; then
		$CMD
		CMD=""
		continue
	fi 
	CMD=$CMD" "$i
	
done
