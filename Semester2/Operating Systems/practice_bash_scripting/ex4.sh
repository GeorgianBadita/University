#!/bin/bash

for F in $(find . -perm -o+w); do #Fisierele ce pot fi scrise de toti
	echo $F
	mv $F $F".all"
done
