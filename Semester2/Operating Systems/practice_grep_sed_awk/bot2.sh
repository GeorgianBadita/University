#!/bin/bash

for name in $(find $1 -type f); do
	VAR=$(echo $name | grep -o "/[^/]*$")
	if echo $VAR | grep -q "[0-9]\{5\}"; then
		echo $name
	fi
done
