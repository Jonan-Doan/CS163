#include "song.h"
//initialize all the information of the song to NULL
using namespace std;
music_entry::music_entry()
{
	artist= NULL;
	song= NULL;
	album= NULL;
	keyword1 = NULL;
	keyword2 = NULL;
	keyword3 = NULL;
	descriptions= NULL;
} 
//deallocate all memory of the information of the song
music_entry::~music_entry()
{
	if(artist)
	{
		delete[] artist;
	}
	if(song)
	{
		delete[] song;
	}
	if(album)
	{
		delete[]album;
	}
	if(keyword1)
	{
		delete[]keyword1;
	}
	if(keyword2)
	{
		delete[]keyword2;
	}
	if(descriptions)
	{
		delete[]descriptions;
	}
}
//initialize the dynamic array
bool music_entry::initialize(char artist_toadd[], char song_toadd[], char album_toadd[], char keyword1_toadd[], char keyword2_toadd[], char keyword3_toadd[], char description_toadd[])
{
	
	if(!artist_toadd || !song_toadd || !album_toadd || !keyword1_toadd || !keyword3_toadd || !description_toadd) return false;
	artist = new char [strlen(artist_toadd)+1];
	strcpy (artist, artist_toadd);
	song = new char [strlen(song_toadd)+1];
	strcpy (song, song_toadd);
	album = new char [strlen(album_toadd)+1];
	strcpy (album, album_toadd);
	keyword1 = new char [strlen(keyword1_toadd)+1];
	strcpy (keyword1, keyword1_toadd);
	keyword2 = new char [strlen(keyword2_toadd)+1];
	strcpy (keyword2, keyword2_toadd);
	keyword3 = new char [strlen(keyword3_toadd)+1];
	strcpy (keyword3, keyword3_toadd);
	descriptions = new char [strlen(description_toadd)+1];
	strcpy (descriptions, description_toadd);
}
//copy the information  into a single object
bool music_entry::copy(const music_entry & to_add)
{
	return initialize(to_add.artist, to_add.song, to_add.album,to_add.keyword1,to_add.keyword2,to_add.keyword3,to_add.descriptions);
}

//display the data
bool music_entry::display()
{
	cout<< "Artist: "<<artist<<endl;
	cout<< "Song: "<<song<<endl;
	cout<< "Album: "<<album<<endl;
	cout<< "Keyword: "<<keyword1<<" , "<<keyword2<<" , "<<keyword3<<endl;
	cout<< "Descriptions: "<<descriptions<<endl<<endl;
}

//If there is a match with the name the user want to type with a pre-existing artist name return true

bool music_entry::compare_artist(char to_compare[])
{
	if(strcmp(to_compare,artist)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
