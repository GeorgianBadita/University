#!/bin/bash





for user in $(cut -d" " -f1 "who.fake"); do
      echo "$(grep "^$user" "ps.fake" | cut -d" " -f1)"
done | sort | uniq -c 
