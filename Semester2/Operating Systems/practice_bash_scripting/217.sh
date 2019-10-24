#/bin/bash

WORD=$1

shift

cnt=0

for F in $*; do
	if  cat $F | grep -q $WORD; then
		cnt=$(($cnt+1))
	fi
done

echo $cnt
