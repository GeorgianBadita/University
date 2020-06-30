#!/bin/bash



for f in $(find $1 -type f); do
        if  file $f | grep -q "ASCII"; then
                echo "Printing from ${f}..."
                echo "$(head -n 3 $f)"
        fi
done
