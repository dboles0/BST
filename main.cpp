//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #4 

//main.cpp file


#include "BST.h"

int main()
{
    int selection = 0;               //menu option form the user
    bool valid = false;              //do while condition to be met
    event_info * found = NULL;       //return value to show if entry exists
    char match[SIZE];                //variable to check for key word matches
    char find_event[SIZE];           //variable to check if event name exists
    char t_response[SIZE];           //response from the user for delete
    char t_event_name[SIZE];         //temp event name to copy into node
    char t_location[SIZE];           //temp location to copy into node
    char t_date[SIZE];               //temp date to copy into node
    char t_time[SIZE];               //temp time to copy into node
    char t_description[SIZE];        //temp description to copy into node
    char t_key_word[SIZE];           //temp key word to copy into node

    binary_node_tree tree;           //initiate the binary tree
    event_info to_add;               //initiate the class to store event info 
    
    tree.load(tree, to_add);

    //menu loop to work with the tree
    do 
    { 
	cout << "\n\n\n\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~ Cal Events Menu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	cout << "\tselect one of the follwoing numeric options:\n" << endl;
	cout << "\t\t1: add to the list" << endl;
	cout << "\t\t2: display the tree's hight" << endl;
	cout << "\t\t3: display the list" << endl;
	cout << "\t\t4: remove event based on event name" << endl;
	cout << "\t\t5: remove events based on key word" << endl;
	cout << "\t\t6: check to see if event is in the list" << endl;
	cout << "\t\t7: exit the program" << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
	cout <<"Enter a response: ";
	cin >> selection; 
	cin.ignore(100, '\n');

	switch (selection)
	{
	    case(1):

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Binary Search Tree Entry
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
		cout << "New Event" << endl;

		do
		{ 
		    //get BST entry form user
		    cout << "Event Name: " << endl;
		    cin.get(t_event_name, 100); cin.ignore(100, '\n');
		    cout << "Location: " << endl;
		    cin.get(t_location, 100); cin.ignore(100, '\n');
		    cout << "Date: " << endl;
		    cin.get(t_date, 100); cin.ignore(100, '\n');
		    cout << "Time: " << endl;
		    cin.get(t_time, 100); cin.ignore(100, '\n');
		    cout << "Descriptioin: " << endl;
		    cin.get(t_description, 100); cin.ignore(100, '\n');
		    cout << "Key Words: " << endl;
		    cin.get(t_key_word, 100); cin.ignore(100, '\n');

		    //insert response into the tree and test the sucssess
		    if(!to_add.create_entry(t_event_name, t_location, t_date, t_time, t_description, t_key_word))
			cerr << "\nsaving the entries was unsuccessfull\n" << endl;
		    
		    //insert response into the tree and test the sucssess
		    if(!tree.insert(to_add))
		    cerr << "\nthe information was not added to the list\n" << endl;
		     
		}while(again());
                
		break;

	    case(2):

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Binary Search Tree health
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
		cout << "\nThe height of your tree is: " << tree.height() << endl;
 
		break;

	    case(3):

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Binary Search Tree display
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
		if(!tree.display_all())
		    cerr << "\nYour list is empty\n" << endl; 
                
		break;

	    case(4):
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Delete Binary Search Tree Entry
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
                cout << "what entry would you like to delete\n" << endl;
                cin.get(t_response, 100); cin.ignore(100, '\n');
                tree.remove_name(t_response);
		break;
            
           case(5):
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Remove All Key Word Matches that the user passes in
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
                cout << "what entry would you like to delete based on the key word: " << endl;
                cin.get(match, 100); cin.ignore(100, '\n');
                tree.remove_key(match);

		break;
	    
            case(6):
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Search Binary Search Tree
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
                cout << "enter an event name to check if it is in the list: " << endl;
                cin.get(find_event, 100); cin.ignore(100, '\n');
                found = tree.retrieve(find_event);
                 
                if(found)
                    cout << "the event is in the list" << endl;
                else
                    cout << "entry not found" << endl;

		break;

            case(7):
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Exit
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
		valid = true;
		break;

	    default:
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		  Sanitize Input Information
		  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 */
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Enter valid numeric entry: " << endl;
		cin >> selection;
		cin.ignore(100, '\n'); 
		break;
        }              //end switch

    } while(!valid);   //end do while

};                    //end main
