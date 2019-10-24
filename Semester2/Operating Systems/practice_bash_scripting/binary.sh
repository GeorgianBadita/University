#!/bin/bash

for F in $(find /usr/bin -type f); do
	if $(file $F | grep -q ":.*ELF"); then
		echo $F
	fi
done
