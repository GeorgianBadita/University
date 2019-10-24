#!/bin/bash

function count (){
        F=$1
        echo "Includes in $F: "
        printf "\n\n"
        includes=$(cat $F | sed "s/ //g" | grep -o "#include<.*>")
        IFS=$"\n"
        for include in $includes; do
                printf "%s" $include
        done
        IFS=$" "
        printf "\n\n"
        return 0;
}

while [ $1 ]; do
   if [ -d $1 ]; then
        for F in $(find $1 -type f);do
                name=$(basename $F)
                if echo $name | grep -q "^.*\.[ch]$"; then
                        count $F
                fi
        done
   else
        echo "$1 is not a directory!"
   fi
   shift
done

