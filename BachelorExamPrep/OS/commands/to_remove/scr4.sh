


f=`find . -type f`
d=`find . -type d`

for x in $f; do
     for y in $d; do
        echo $f $d
        if [ $x = $y ]; then
                echo "OK"
        fi
     done
done
