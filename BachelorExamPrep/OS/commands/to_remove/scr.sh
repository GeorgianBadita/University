#!/bin/bash


fileName=$1
longest=""
longestSize=0

for F in $fileName/*; do
        VAR=$(echo $F | awk -F "/" '{print $NF}')
        echo $VAR
        if [ $(echo $VAR | grep -v "^\.") ]; then
                len=$(echo $VAR | wc -c);
                if [ $len -gt $longestSize ]; then
                        longest=$VAR
                        longestSize=$len
                fi
        fi
done

echo $longest $longestSize
