#!/bin/bash





for f in $(find $1 -type f); do
   if [[ $f == *.log ]]; then
        SORTCONTENT=$(cat $f | sort);
        $(rm $f)
        $(echo "$SORTCONTENT" >> $f)
   fi
done
