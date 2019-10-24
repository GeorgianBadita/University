#!/bin/bash

#Script care afiseaza o ierarhie de directoare sub forma unui arbore

#verificam daca a fost trimis doar un parametru
if [ $# -gt 1 ]; then
	echo "tree: numar de argumente eronat" >&2
	echo "utilizare: tree [director]" >&2
	exit 1
fi

#daca primul parametru nu e director, eroare

if [ $# -eq 1 ]; then
	if [ ! -d $1 ]; then
		echo "$0: $1 nu ete director">&2
		echo "utilizare: tree [director]">&2
		exit 1
	fi
fi

IFS=$'\n'
arr=($(find $1 -exec  ls -l {} \; | awk '{print $5}'))

for item in ${arr[*]}; do
	echo $item
done
IFS=$' '
find $1 -print | sort | sed -e 's|[^/]*/|  |g' |\
						sed -e 's/\(\<.*\>\)/+- \1/'
