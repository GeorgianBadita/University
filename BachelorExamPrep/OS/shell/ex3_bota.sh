#!/bin/bash


if [ $# -lt 1 ];then
        echo "Not enough arguments"
        echo "Usage $0 directory_name"
        exit 1
fi


NUMFILES=0
SUMLINES=0
for f in $(find $1 -type f); do
        if file $f | grep -q "\<ASCII text\>"; then
                SUMLINES=$(($SUMLINES+$(wc -l $f | cut -d" " -f1)))
                NUMFILES=$(($NUMFILES+1))
        fi
done

if [ $NUMFILES -gt 0 ]; then
        echo "Avg is: $(($SUMLINES/$NUMFILES))"
else
        echo "No text files were found"
fi

