#include "song.h"
struct list
{
	music_entry entry;//objects that hold each information of the song
	list * next;//a next pointer to the next entry
};
//Class that organizes implemenation of the hash table
class table
{
	public:
		table(int size = 5);//constructor
		~table();//default destructor
		bool insert(char keyword1[], char keyword2[], char keyword3[], const music_entry & to_add);//insert data to the hash table
		bool remove (char name_toremove[]);//remove data based on an artist name
		bool display_all();
		int hashfunction(char keywords1[], char keyword2[], char keyword3[]);// hash_function that will give us a key value to determine where the data is found
		bool search (char keyword1_toadd[], char keyword2_toadd[], char keyword3_toadd[]);//search for a particular data based on its key value and display the content
		bool write ();//write to a file
		bool read ();//read to a file
	private:
		list ** hash_table;//initialize the hash table
		int hash_table_size;//initialize the size of the table
		list * temp;
		list * prev;
};
