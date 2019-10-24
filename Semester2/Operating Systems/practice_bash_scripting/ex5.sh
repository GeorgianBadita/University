#!/bin/bash

touch temporary

for param in $*; do
	if [ -f $param ]; then	
		echo $param > temporary
	    echo $(awk -F/ '{print $NF}' temporary)
   	    echo $(wc -c $param | grep -o "[0-9]* ")
        echo $(wc -l $param | grep -o "[0-9]* ")	
	elif [ -d $param ]; then
		echo $param > temporary
		echo $(awk -F/ '{print $NF}' temporary)
		NR=0
		for F in $(find $param -type f); do
			NR=$(($NR+1))
		done
		echo "Directorul contine $NR fisiere"
	else
		echo "Parametrii sunt incorecti"
		exit 1
	fi
done

rm temporary
