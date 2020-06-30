#!/bin/bash


FOUND=0;
for f in $(find $1 -type f); do
      if [ $FOUND -gt 1 ]; then
        break
      fi
      if [[ $f == *.c ]]; then
        if [ $(wc -l $f | cut -d" " -f1) -gt 500 ]; then
                echo $f
                FOUND=$(($FOUND+1))
        fi
      fi
done
