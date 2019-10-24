#!/bin/bash

#executes commands recieved in the command line and 
#stops its execution for x seconds
#x first parameter in the command line

pause=$1
CMD=""
shift 

while [ $1 ] ; do
	if [ "$1" == ";" ]; then
		$CMD
		CMD=""
		shift
		continue
	fi
	CMD=$CMD" "$1
	sleep $pause
	shift
done

