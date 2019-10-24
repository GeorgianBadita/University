#!/bin/bash

#Aplicatia verifica daca un anumit director a ramas sau nu nemodificat
#din t in t secunde (argument primit in linia de comandata)
#directorul va fi de asemenea primit in linia de comanda

t=${1-60}
dir=${2-${HOME}}
x=$(ls -l $dir)

while true
do
	sleep $t
	y=$(ls -l $dir)	
	if [ "$x" != "$y" ]; then
		echo "Directorul $dir a fost modificat"
		exit
	else
		echo "Nu s-a modificat nimic, mai dormim $t secunde"
	fi
done


