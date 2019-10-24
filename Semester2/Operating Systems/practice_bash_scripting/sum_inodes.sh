#!/bin/bash

SUM=0
for F in *; do
	NUM=$(stat $F | grep "Inode:" | awk '{print $4}')
	SUM=$(($SUM+$NUM))
done

echo $SUM
