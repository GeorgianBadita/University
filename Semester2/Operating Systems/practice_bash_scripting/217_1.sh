#!/bin/bash

prod=1
nr_txt=0

while [ $1 ]; do
	if [ -d $1 ]; then
		for F in $(find $1 -type f); do
			var=$(echo $F | sed 's|[^/]*/||g' | grep ".txt")
			if [ -n "$var" ]; then
				nr_txt=$(($nr_txt+1))
			fi
		done
	else
		is_num=1
		has_only_dig=$(echo $1 | grep '[^-0-9]')
		if [ -n "$has_only_dig" ]; then
			is_num=0;
		fi
		
		if [ $is_num -eq 1 ]; then
			num=$1
			if [ $num -lt 100 ]; then
				prod=$(($prod*$num))
			fi
		fi
	fi
	shift
done

echo $nr_txt
echo $prod
