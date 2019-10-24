#!/bin/bash
SUM=0

read N

for i in $(seq 1 $N); do
    read x
	SUM=$(($SUM+$x))
done

expr="$SUM/$N"

echo $expr | bc -l | xargs printf "%.3f"
