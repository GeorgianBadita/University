#!/bin/bash

FINAL=99

for i in $(seq 1 $FINAL); do
	if [ $(($i%2)) -eq 2 ]; then
		echo $i
		fi

	done
