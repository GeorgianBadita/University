#!/bin/bash

arr=($(find $1 -type f | sed 's|[^/]*/||g'))

for item in ${arr[*]}; do
	if [[ $item =~ [\0-9][\0-9][\0-9][\0-9][\0-9] ]]; then
		echo $item
	fi
done
