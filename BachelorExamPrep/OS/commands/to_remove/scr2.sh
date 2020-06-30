

SUM=0
while [ $SUM -lt 11 ]; do
        echo "BAGA BA UN NUMAR: "
        read number
        SUM=$(($SUM+$number))

        echo "SUMA: " $SUM  
done
