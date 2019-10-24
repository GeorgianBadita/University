#!/bin/bash

#Se dau directoare ca si argumente, calculati dimensiunea medie a acestora

COUNT=$#
if [ $COUNT -eq 0 ]; then
        echo "No arguments given!"
        exit 1
fi
SUM=0
for D in $*; do
  if [ -d $D ]; then
         DIR_SZ=$(du -b  $D | tail -n-1 | awk '{print $1}')     
         SUM=$(($SUM + $DIR_SZ))
  else 
         echo "The argument $D is not a directory!"
         COUNT=$(($COUNT-1))
  fi
done

if [ $COUNT -eq 0 ]; then
        echo "None of the arguments were directories!"
        exit 1
fi
SUM=$((SUM/COUNT))

echo $SUM                                                                               
