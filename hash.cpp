#include "hash.h"
//initialize each element of the hash table
using namespace std;
table::table(int size) //This function is not working properly
{
	hash_table = new list*[size];
	for(int i= 0; i<size; ++i)
	{
		hash_table[i]= NULL;
	}
	hash_table_size = size;
	temp = NULL;
	prev = NULL;
}
//deallocate memory of each element of the hash table
table::~table()
{
	for(int i = 0; i<hash_table_size; ++i)
	{
		list * entry = hash_table[i];
		while(entry != NULL)
		{
			list * prev = entry;
			entry = entry->next;
			delete prev;
		}
	}
}
//add up all the keyword's ascii value and return the key value
int table::hashfunction(char keyword1_toadd[], char keyword2_toadd[], char keyword3_toadd[])
{
	int sum = 0;
	for(int i = 0; keyword1_toadd[i] != '\0'; ++i)
	{
		sum+=keyword1_toadd[i];
	}
	for(int i = 0; keyword2_toadd[i] != '\0'; ++i)
	{
		sum+=keyword2_toadd[i];
	}
	for(int i = 0; keyword3_toadd[i] != '\0'; ++i)
	{
		sum+=keyword3_toadd[i];
	}
	return sum%hash_table_size;
}
//Insert the data the user want to add and insert it into its respective hash bucket
bool table::insert(char keyword1[], char keyword2[], char keyword3[], const music_entry & to_add)
{
	int hash_value = hashfunction(keyword1, keyword2, keyword3);
	if(hash_table[hash_value] == NULL)// if the there isn't any data in the hash bucket 
	{
		hash_table[hash_value] = new list;
		if(!hash_table[hash_value]->entry.copy(to_add))// return false if the data is not added
		{
			delete temp;
			return false;
		}
		hash_table[hash_value]->next = NULL;
		return true;
	}
	else // if there is already data in the hash bucket
	{
		temp = hash_table[hash_value];
		hash_table[hash_value] = new list;
		hash_table[hash_value] ->next = temp;
		hash_table[hash_value] ->entry.copy(to_add);
		return true;
	}
}
//Remove the data in the hash table based on the artist name
bool table::remove (char artist_to_search[])
{
	for(int i = 0; i<hash_table_size; ++i)
	{
		list * temp = hash_table[i];
		list * previous = NULL;
		while(temp != NULL && strcmp(temp->entry.artist, artist_to_search) != 0)
		{

			prev = temp;
			temp = temp->next;
		}
		if(strcmp(temp->entry.artist, artist_to_search) == 0)
		{
			prev ->next = temp ->next;
			delete temp;
			return true;
		}
		
	}
	return false;
}
//display all the content of the hash table
bool table::display_all() 
{
	list * current = NULL;
	for(int i=0; i<hash_table_size; ++i)
	{
		list * current = hash_table[i];
		while(current)
		{
			current->entry.display(); // the content has not been displayed return f
			current = current->next;
		}
	}
	return true;
}
//Search for data and display data based on key value
bool table::search(char keyword1_toadd[], char keyword2_toadd[], char keyword3_toadd[])
{
	int hash_value = hashfunction(keyword1_toadd, keyword2_toadd, keyword3_toadd);
	list *temp = hash_table[hash_value];
	while(temp != NULL)
	{
		if(strcmp(temp->entry.keyword1, keyword1_toadd) == 0||strcmp(temp->entry.keyword2, keyword2_toadd) == 0||strcmp(temp->entry.keyword3, keyword3_toadd)==0) // once it finds a match
		{
			temp->entry.display();
			return true;
		}
		else
			return false;
		temp = temp->next;
	}
}

