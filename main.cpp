#include"hash.h"
using namespace std; 
int main()
{
	table my_song;// object of the hash_table class
	music_entry to_add, an_entry; //object of the music_entry class
	char artist_toadd[ARTIST_SIZE];//array that hold the artist name
	char artist_to_search[100];
	char song_toadd[100];//array that hold the song title name
	char album_toadd[100];//array that hold the album neme
	char keyword1_toadd[100];//array that hold the keyword1
	char keyword2_toadd[100];//array that hold the keyword2
	char keyword3_toadd[100];//arraty that hold the keyword3
	char description_toadd[100];//array that hold the descriptions of the song
	char response;// char variable that will hold the letter if the user want to repeat their choice
	char choice;// char variable that will hold the  letter of what the user want to do for the program
	bool error = false;// bool variable that will prompt if there is something wrong with the program
	do
	{ 
		cout<<"Please type I if you want to insert a new data, please type R if you want to remove a data, please type S if you want to seacrch for a data, please type L if you want to load pre-existing data"
			<<" ,please type D if you want to display all the data, Please type W if you want to write to a file."<<endl<<endl;
		cin>>choice;
		cin.ignore(100, '\n');
		choice=toupper(choice);
		if(choice == 'I')//if the user want to insert
		{
			//get data
			//

			cout<<"Please type a artist name: ";
			cin.get(artist_toadd, ARTIST_SIZE); 
			cin.ignore (100, '\n');
			cout<<"Please enter the song title: ";
			cin.get(song_toadd, SONG_SIZE); 
			cin.ignore(100, '\n');
			cout<<"Please enter the album name: ";
			cin.get(album_toadd, ALBUM_SIZE); 
			cin.ignore (100, '\n');
			cout<<"Please type three keywords that relate to the song"<<endl;
			cout<<"Keyword 1: ";
			cin.get(keyword1_toadd, KEYWORDS_SIZE); 
			cin.ignore(100, '\n');
			cout<<"Keyword 2: ";
			cin.get(keyword2_toadd, KEYWORDS_SIZE); 
			cin.ignore(100, '\n');
			cout<<"Keyword 3: ";
			cin.get(keyword3_toadd, KEYWORDS_SIZE); 
			cin.ignore(100, '\n');
			cout<<"Please enter the description for the song."<<endl;
			cin.get(description_toadd, DESCRIPTION_SIZE); cin.ignore(100, '\n');

			//pass in data to the initializer
			to_add.initialize(artist_toadd,album_toadd, song_toadd, keyword1_toadd, keyword2_toadd, keyword3_toadd, description_toadd);

			//pass in the object to_add along with the keyword to insert
			error= my_song.insert(keyword1_toadd, keyword2_toadd, keyword3_toadd, to_add);
			if(error = false)
			{
				cout<<"There were something wrong about the program please type again."<<endl;
			}
		}
		if(choice == 'R')//if they want to remoe
		{
			//get artist name
			cout<<"Please type a artist to remove a song based on its artist."<<endl;
			cin.get(artist_to_search, ARTIST_SIZE); 
			cin.ignore (100, '\n');

			//pass in the artist name to the remove function
			error = my_song.remove(artist_to_search);
			if(error = false)//if there is an error
			{
				cout<<"There were something wrong about the program please type again."<<endl;//prompt user for error
			}
		}
		if(choice == 'L')//if they want to load
		{
			//my_song.read();//read in the data
			//
			ifstream in_file;// Create a file variable for input
			in_file.open("song.txt");//open the file
			if(in_file)// indicate if we are successful with connecting to the file
			{
				while (in_file && in_file.peek() != EOF)// While we are successful
				{
					in_file.get(artist_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(song_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(album_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(keyword1_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(keyword2_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(keyword2_toadd,100,'|');
					in_file.ignore(100,'|');
					in_file.get(description_toadd,100,'|');
					in_file.ignore(100,'|');

					to_add.initialize(artist_toadd,album_toadd, song_toadd, keyword1_toadd, keyword2_toadd, keyword3_toadd, description_toadd);

					//pass in the object to_add along with the keyword to insert
					error= my_song.insert(keyword1_toadd, keyword2_toadd, keyword3_toadd, to_add);
					if(error = false)
					{
						cout<<"There were something wrong about the program please type again."<<endl;
					}





				}
				in_file.close(); // close the file
				in_file.clear();
			}


		}
		if(choice == 'S')//if they want to search
		{

			//get keyword
			//

			cout<<"Please type three keywords that relate to the song"<<endl;
			cout<<"Keyword 1: ";
			cin.get(keyword1_toadd, KEYWORDS_SIZE); cin.ignore(100, '\n');
			cout<<"Keyword 2: ";
			cin.get(keyword2_toadd, KEYWORDS_SIZE); cin.ignore(100, '\n');
			cout<<"Keyword 3: ";
			cin.get(keyword3_toadd, KEYWORDS_SIZE); cin.ignore(100, '\n');

			//pass keyword to search function
			my_song.search(keyword1_toadd, keyword2_toadd, keyword3_toadd);

		}
		if(choice == 'D')//if they want to display
		{
			error=my_song.display_all();
			if(error = false)//if there is an error occurred
			{
				cout<<"There were something wrong about the program please type again."<<endl;//prompt error
			}

		}
		if(choice == 'W')//if they want to write
		{
			my_song.write();//write data to the extern file
		}
	}while(choice != 'Q');//If they want to quit from the program
	return 0;
}
