#!/bin/bash

START=1

while [ ! $START -eq 201 ]; do
	printf "%d\t" $START
	if [ $(($START % 5)) -eq 0 ];then
		printf "\n"
	fi
	START=$(($START + 1))
done
