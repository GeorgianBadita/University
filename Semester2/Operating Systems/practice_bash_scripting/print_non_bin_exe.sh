#!/bin/bash

for F in /usr/bin/*; do
	if echo $(file -b $F) | grep -q -v "^ELF"; then
		echo $F
	fi
#	if [ -n $(file -b $F) | grep -q -v "^ELF" ]; then
#		echo $F
#	fi
done
