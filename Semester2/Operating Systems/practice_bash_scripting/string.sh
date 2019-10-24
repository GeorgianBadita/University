#!/bin/bash

#Programul cauta in toate fisierele .c sau .txt, dandu-se c sau txt ca si primul parametru iar ca si al 2-lea parametru se da textul de cautat
#De asemenea ca si al 3-lea parametru se va da directorul cautat

opt=${1-"txt"}
name=${2-"."} #daca nu se da nimic de cautat, putem cauta orice
dir=${3-${HOME}}

for F in $(find $dir -name *.$opt); do
	grep_var=$(grep $name $F)
	if [ -z "$grep_var" ]; then
		continue
	fi
	echo $F
done

