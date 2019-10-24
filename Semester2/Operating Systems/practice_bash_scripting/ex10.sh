#!/bin/bash

for F in $(find $1 -type f); do
	PERM=$(stat -c "%a" $F)
	if [ $PERM -eq 755 ]; then
		echo "Press [Y/N] to change permission of $F to 744"
		read OPT
		TO_CHECK="Y"
		if [ "$OPT" == "$TO_CHECK" ]; then
			$(chmod 744 $F)
		fi
	fi
done
