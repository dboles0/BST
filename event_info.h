//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #4 

//event_info.h file

#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

using namespace std;

int const SIZE = 100;
int const KEY_WORD_SIZE = 20;
  

struct event_info
{
    char * event_name;         //name given to the event
    char * location;           //place where the event will take place
    char * date;               //starting date of the event as MM/DD/YYYY 
    char * time;               //time when the event starts
    char * description;        //description of the what to expect at event
    char ** key_word;           //head to store the key word nodes
    int key_word_num;

    event_info();
    ~event_info();
    //int delete_key_word(key_node * head);
    int copy(const event_info & to_add);
    int create_entry(char * an_event_name, char * a_location, char * a_date, char * a_time, char * a_description, char * a_key_word);
    int load();
};


