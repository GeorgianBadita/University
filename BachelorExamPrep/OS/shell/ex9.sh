#!/bin/bash

files=()
for F in $(find -type f); do
       files+=( $F )
done

for ind1 in ${!files[@]}; do
      for ind2 in ${!files[@]}; do
        if [ $ind1 -ne $ind2 ]; then
                md51=$(md5sum ${files[$ind1]} | awk '{print $1}');
                md52=$(md5sum ${files[$ind2]} | awk '{print $1}');
                 
                if [[ $md51 == $md52 ]]; then
                        echo "Files ${files[$ind1]} is the same as ${files[$ind2]}"
                fi
        fi
      done
done
