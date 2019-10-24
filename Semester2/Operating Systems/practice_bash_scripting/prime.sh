#!/bin/bash

function prime(){
	NUM=$1
	if [ $1 -lt 2 ]; then
		return 0
	elif [ $1 -eq 2 ]; then
		return 1
	elif [ $(($1 % 2)) -eq 0 ]; then
		return 0
	fi
	for (( count = 3; count <= $(($1/2)); count+=2 )); do
		if [ $(($1 % count)) -eq 0 ]; then
			return 0
		fi
	done
	return 1
}

while true; do
	echo "1. Give a number: "
	echo "2. Close the app"
	read opt
	if [ $opt -eq 2 ]; then
		exit 0
	else
		read num
		prime $num
		if [ $? -eq 1 ]; then
			echo "The number $num is prime"
		else
			echo "The number $num is not prime"
		fi
	fi
done
