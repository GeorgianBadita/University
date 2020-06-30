#!/bin/bash

THISPID=$$
while [ true ]; do
        echo "Start monitoring.."
        for prog in $@; do
             
             if ps -ef | grep -q $prog; then
                     var=$(ps -ef | grep $prog | awk '{print $2}')
#echo "This pid: $$, var pid: $var"
                     if [ "$var" != "$THISPID" ]; then
                        
                        echo "This pid: $$"
                        echo "Killing process with $prog with pid: $var..."
                        $(kill -9 $var >> /dev/null 2>&1)
                     fi
             fi
             
        done
        sleep 2
done
