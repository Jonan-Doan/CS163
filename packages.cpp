#include "packages.h"
// constructor for the packages
packages::packages()
{
	sender_name= NULL;
      	phone = NULL;
     	id= NULL;

}
//Destructor for the packages
packages::~packages()
{
	if(sender_name)
	{
		delete [] sender_name;
	}
	if (phone)
	{
		delete [] phone;
	}
	if (id)
	{
		delete [] id;
	}
	sender_name = phone = id = NULL;
}
// Copying a static array of the package information and add it into the dynamic array
int packages::create_entry(char sender_name_toadd [], char phone_toadd [], char id_toadd[])
{
	if (!sender_name_toadd || !phone_toadd || !id_toadd) return 0;
	sender_name = new char [strlen(sender_name_toadd)+1];
	strcpy(sender_name, sender_name_toadd);
	phone = new char [strlen(phone_toadd)+1];
	strcpy(phone, phone_toadd);
	id = new char [strlen(id_toadd)+1];
	strcpy(id, id_toadd);
		
}
// Adding the package information into a package object
int packages::add_packages(const packages & new_packages)
{
	return create_entry(new_packages.sender_name, new_packages.phone, new_packages.id);
}


// Display the package's information
int packages::display_packages() const
{
	cout<< "Name of the sender: "<<sender_name<<endl;
	cout<< "The sender phone number: "<<phone<<endl;
	cout<< "The i.d. of the packages: "<<id<<endl;
}
