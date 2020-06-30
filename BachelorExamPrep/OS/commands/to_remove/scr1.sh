while [ $1 ]; do
       
        if [ $(echo $1 | grep "^[1-9][0-9]*$") ]; then
                if [ $(($1%2)) -eq 0 ]; then
                        echo $1 " e numar par"
                        break
                fi
        fi
        shift
done
