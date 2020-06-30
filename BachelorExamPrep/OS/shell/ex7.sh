#!/bin/bash

for line in "$(df -h)"; do
     echo "$line" | tail -n +2 | awk '{print $1" " $5}'
done
