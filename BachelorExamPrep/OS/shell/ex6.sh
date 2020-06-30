#!/bin/bash



for F in $(find $1 -type d); do
        if echo "$(ls -l $F)" | grep -q "^.*w. .*$"; then
                echo "$(ls -l $F)" | awk '{print $1" " $9}'
                
        fi
done
