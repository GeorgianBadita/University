#!/bin/bash

sum=0
for F in  $(ls -i $F | awk '{print $1}');do
	((sum+=$F))
done

echo $sum

