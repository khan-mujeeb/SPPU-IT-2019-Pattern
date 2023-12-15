#!/bin/sh

create()
{
	
	if [ -e addressbook.txt ];
	then
		echo "already exist"
	else
		touch addressbook.txt
		echo "created "
	fi
}

insert() 
{
		echo "Enter full name"
		read full_name
		
		echo "Enter contact number "
		read contact
		
		echo "enter email address"
		read email
		
		echo "$full_name 	$contact 	$email" >> addressbook.txt
		echo "contact added successfully"
}

view()
{
if [ ! -s addressbook.txt ];  
then 
	echo -e "THE ADDRESSBOOK IS EMPTY !!! \n"
else
	sed -n 'p' addressbook.txt  
	
fi
}


while [ true ]
do
	echo "*********Main Menu**********"
	echo "1. Create Addressbook"
	echo "2. Insert Contact"
	echo "3. view"
	echo "7. exit "
	
	echo "enter your choice  "
	read choice
	case $choice in
		1) create ;;
		2) insert ;;
		3) view ;;
		7) exit ;;
		*) echo "enter valid choice" ;;
	esac
done