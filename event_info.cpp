//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #4 

//event_info.cpp file

#include "event_info.h"

//default constructor for the event info struct
event_info::event_info()
{
    event_name = NULL;
    location = NULL;
    date = NULL;
    time = NULL;
    description = NULL;
    key_word = NULL;
    key_word = new char * [KEY_WORD_SIZE]; 
    for(int i=0; i<KEY_WORD_SIZE; ++i)
    	key_word[i] = NULL; 
    key_word_num = 0;
   
     
}

//destructor to deallocate the information saved to the struct
event_info::~event_info()
{
   if(event_name) 
	delete [] event_name; 
   if(location) 
	delete [] location;       
   if(date) 
	delete [] date;       
   if(time) 
	delete [] time;   
   if(description)
	delete [] description;  
   for(int i=0; i<key_word_num; ++i)
   {
       delete [] key_word[i];
   }
   if(key_word)
	delete [] key_word;  

}


//take the informtation form the client to store to struct so we can place the information to the BST
int event_info::create_entry(char * an_event_name, char * a_location, char * a_date, char * a_time, char * a_description, char * a_key_word)
{
    event_name = new char [strlen(an_event_name)+1];
    strcpy(event_name, an_event_name);
    location = new char [strlen(a_location)+1];
    strcpy(location, a_location);
    date = new char [strlen(a_date)+1];
    strcpy(date, a_date);
    time = new char [strlen(a_time)+1];
    strcpy(time, a_time);
    description = new char [strlen(a_description)+1];
    strcpy(description, a_description);
    for(int i=0; i<key_word_num; ++i)
    {
	key_word[i] = new char[strlen(key_word[i])+1];
	strcpy(key_word[i], key_word[i]);
    }
    key_word_num = key_word_num;
}

//copy function to take the infomrtiaon form the user and copy it 
//into the tree.
int event_info::copy(const event_info & to_add)
{
    event_name = new char [strlen(to_add.event_name)+1];
    strcpy(event_name, to_add.event_name);
    location = new char [strlen(to_add.location)+1];
    strcpy(location, to_add.location);
    date = new char [strlen(to_add.date)+1];
    strcpy(date, to_add.date);
    time = new char [strlen(to_add.time)+1];
    strcpy(time, to_add.time);
    description = new char [strlen(to_add.description)+1];
    strcpy(description, to_add.description);
    for(int i=0; i<to_add.key_word_num; ++i)
    {
	key_word[i] = new char[strlen(to_add.key_word[i])+1];
	strcpy(key_word[i], to_add.key_word[i]);
    }
    key_word_num = to_add.key_word_num;
}
