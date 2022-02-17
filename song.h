#include <iostream>
#include <cctype>
#include<fstream>
#include <cstring>
#include <string.h>

//Jonan Doan
//The program design is to ask the user if they want to display, search,insert, remove , load, or write to file and execute whatever they want to do with the program. If they want to display the program will
//display all the content of the hash table. If they want to search, the application will search for a particular hash bucket and display its content. If they want to insert than the program will insert the data
//based on its key value. if they want to remove the program will ask the user to type a artist name and remove data connecting to the artist. If they want to load th program will read the data from external data file
//if they want to write to a file the program will write all the conetn of tha hash table to the external data file.
const int ARTIST_SIZE = 40;//constant size for the artist
const int SONG_SIZE = 40;//constant size for the song
const int ALBUM_SIZE = 40;//const size for the album
const int KEYWORDS_SIZE= 40;//const size for each keyword
const int DESCRIPTION_SIZE= 40;//const size for the description
const char outfile[]= "songselect.txt";//create a file called songselect.txt
// class that organizes implementation of dynamic array information
class music_entry
{
	public:
		music_entry();//default constructor
		~music_entry();//default destructor
		bool initialize(char artist_toadd[], char song_toadd[], char album_toadd[], char keyword1_toadd[], char keyword2_toadd[], char keyword3_toadd[], char description_toadd[]);//initialize each dynamic array to hold
		//the static array being passed in
		bool copy(const music_entry & to_add);//copy all the data of the initialize function and copy it into an music_entry object
		bool compare_artist(char to_compare[]);//return the value if there is a match found between the artist name the user is searching for and pre-existing artist
		bool display();
		friend class table;
	private:
		char * artist;//pointer that hold the name of the artist
		char * song;//poointer that hold the song title
		char * album;//pointer that hold the album name
		char * keyword1;//pointer that hold keyword1
		char * keyword2;//pointer that hold keyword2
		char * keyword3;//pointer that hold keyword3
		char * descriptions;//pointer that hold the description of the song
};

