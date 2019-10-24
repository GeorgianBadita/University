#!/bin/bash 

declare -i sum_file=0
declare -i sum_compl=0
	

while [ $1 ]; do
	if [ -f $1 ]; then
		num=$(cat $1 | awk ' BEGIN {cnt=0}{if(length($0) % 2 == 1) cnt=cnt+1} END {print cnt}')
		sum_file=$(($sum_file + $num))		
	else 
		complex=$(echo $1 | sed 's/[^+]*+//g'| sed 's/[^-]*-/-/g' | awk -F "i" '{print $1}')
		sum_compl=$(($sum_compl+$complex))
	fi
	shift
done

echo $sum_file
echo $sum_compl
