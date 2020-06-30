#!/bin/bash


FILENAME="dir_ex1"
$(mkdir -p $FILENAME)
for i in $(seq 1 $1); do
        start=$i
        final=$(($start+5))
              
        content=$(sed -n "${start},${final}p" 'passwd.fake')
        echo "$content"
        echo "$content" >> "${FILENAME}/file_${start}"
done
