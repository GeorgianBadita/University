




dir=$1

for F in $(find $dir -type f); do
 if file $F | grep -q "ASCII" ; then
        echo $F
 fi
done
