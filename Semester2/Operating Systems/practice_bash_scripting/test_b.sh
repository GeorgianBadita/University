#!/bin/bash

for user in $*; do
	if grep -q "^$user" /etc/passwd; then
		nr_proc=$(ps -ef | grep "^$user" | awk '{print $1}' | uniq -c | awk '{print $1}')
		echo "$user has $nr_proc processe"
	else
		echo "$user is an invalid user!"
	fi
done
