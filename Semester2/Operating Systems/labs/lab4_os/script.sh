#!/bin/bash

sum=0
maxim=-1
minim=1000000000
nr=0
for entry in $(find -L); do
	if [ -f $entry ]; then
		val_to_be_added=$(wc -c $entry | awk '{print $1}')
		((nr+=1))
		if [ $val_to_be_added -gt  $maxim ]; then
			maxim=$val_to_be_added
		fi
		if [ $val_to_be_added -lt $minim ]; then
			minim=$val_to_be_added
		fi
		((sum+=val_to_be_added))
	fi
done
((sum-=minim))
((sum-=maxim))
((sum/=nr))
echo $sum

