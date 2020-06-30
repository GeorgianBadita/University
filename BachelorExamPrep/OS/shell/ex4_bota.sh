#!/bin/bash

for file in $(ls $1); do
        if echo $file | grep -q "[0-9]\{5,\}"; then
                echo $file
        fi
done
