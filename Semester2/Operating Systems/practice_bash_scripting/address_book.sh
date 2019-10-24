#!/bin/bash

#This application is a address book, which has the following functionalities:
#search a person by name
#add a new person by giving: full name, phone number, emial
#edit a person
#delete a person
#TODO: add an option to send an emial to a certain person


function search_person(){ #Function to search a person in the addr_book
	NAME=$1
	ISLST=0
    for FILEN in $(grep -o "^[^0-9]*"  addr_file.txt ); do
        if [ "$NAME" = "$FILEN" ]; then
             ISLST=1
         fi
    done
	return $ISLST
}

while true; do
	$(sed -i '/^$/d' addr_file.txt)
	echo "
		  1. To add a new person
		  2. To search a person
		  3. To edit a person
		  4. To delete a person
		  5. To print the address book
		  6. To close the app"
	read OPT
	if [ "$OPT" = "6" ]; then	#TO CLOSE THE APP
		exit 0

	elif [ "$OPT" = "1" ]; then	#ADDING A NEW PERSON
		echo "Give the name of the person: "
		read NAME
		echo "Give the phone number of the person: "
		read PNUMBER
		echo "Give the emial of the person: "
		read EMIAL
		PERSON=$NAME" "$PNUMBER" "$EMIAL" "
		echo $PERSON >> addr_file.txt

	elif [ "$OPT" = "5" ]; then	#PRINT THE LIST OF PEOPLE
		cat addr_file.txt		#TODO: MAKE THIS LOOK FANCY

	elif [ "$OPT" = "2" ]; then #SEARCH A PERSON BY NAME
		echo "Give the person to search: "
		read NAME
		search_person $NAME
		ISLST=$?
		if [ $ISLST -eq 0 ]; then
			echo "The person does not appear on the list"
		else
            echo $(grep "$NAME" addr_file.txt);
		fi
	elif [ "$OPT" = "4" ]; then		
		echo "Give the name of the person to delete: "
		read TODEL
		search_person $TODEL
		ISLST=$?
		if [ $ISLST -eq 0 ]; then
			echo "The person does not appear on the list"
		else
			echo "The person was deleted!"
			$(sed -i "s/$TODEL.*$//"  addr_file.txt) #TODO: smth wrong here
		fi
	fi
	

done
