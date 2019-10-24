#!/bin/bash

CMD=""
ARG=""
for C in $*; do
	if [ "$C" == ";" ]; then
		$CMD $ARG
		CMD=""
		ARG=""
	elif [ -z "$CMD" ]; then
		CMD=$C
	else
		ARG="$ARG $C"
	fi
done

if [ -n "$CMD" ]; then
	$CMD $ARG
fi
