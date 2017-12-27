//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #4 

//@BST.cpp

#include"BST.h"

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
constructor 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//default constructor 
binary_node_tree::binary_node_tree()
     :root_ptr(NULL), key_word_array(NULL)   
{
    node * right = NULL; 
    node * left = NULL; 
}   //end default constructor

//perameterized constructor
binary_node_tree::binary_node_tree(int key_item_num)
{
    key_item_num = 0;
}
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
destructor 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//default destructor used as a wraper function to deallocate
//the tree's data
binary_node_tree::~binary_node_tree()
{
    destroy_tree(root_ptr);
}
//recursive call to destroy all the nodes in a tree
int binary_node_tree::destroy_tree(node *& root_ptr)
{
    if(!root_ptr) return 0;
    int ret = destroy_tree(root_ptr->left) + destroy_tree(root_ptr->right);
    
    delete root_ptr;
    root_ptr = NULL;
    ++ret;
    return ret;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 1 add item to tree
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//wrapper function for the insert function
int binary_node_tree::insert(event_info & new_data)
{
    return insert(root_ptr, new_data);
}

//insert into the binary search tree and return the number
//of nodes in the path form the root_ptr to the new node
int binary_node_tree::insert(node * &root_ptr, event_info & new_data)
{
    if(!root_ptr)  //base case
    {
        root_ptr = new node;
        root_ptr->data.copy(new_data);
        root_ptr->left = root_ptr->right = NULL;
        return 1; 
    }
    if(strcmp(new_data.event_name, root_ptr->data.event_name) < 0) 
        return insert(root_ptr->left, new_data) +1;
    return insert(root_ptr->right, new_data) +1;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 2 hight of tree
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//wrapper function to get the height of the tree
int binary_node_tree::height()
{
    return height(root_ptr);
}

//recusive call that returns the height of the tree
int binary_node_tree::height (node * root_ptr)
{
    if(!root_ptr) return 0;
    return max (height(root_ptr->left), height(root_ptr->right))+1;
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 3 display the tree
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//wrapper display all function to view the tree structure
bool binary_node_tree::display_all()
{
   bool success = false;
   display_all(root_ptr, success);
}

//dispaly all function to view all the nodes in the tree
bool binary_node_tree::display_all(node * root_ptr, bool success)
{ 
    int cnt = 0;  
    if(!root_ptr) return success;
    display_all(root_ptr->left, success);
    cout << root_ptr->data.event_name << "\n"
         << root_ptr->data.location << "\n"
         << root_ptr->data.date << "\n"
         << root_ptr->data.time << "\n"
         << root_ptr->data.description << "\n";
    for(int i=0; i<root_ptr->data.key_word_num; ++i)
    {   
        ++cnt;
        cout << "Key Word:" << cnt << " " << root_ptr->data.key_word[i] << endl;
    } 
    cout << endl; 
    display_all(root_ptr->right, success);
    success = true;
    return success; 
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 4 delete node based on name
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//wrapper function for the removal funciton 
int binary_node_tree::remove_name(char * match)
{
    return remove_name(root_ptr, match);
}

//removal of a node
int binary_node_tree::remove_name(node *& root_ptr, char * match)
{
    if(!root_ptr) return 0;
    //if match the same as root 
    if(strcmp(root_ptr->data.event_name, match) == 0) 
    {
	remove_node(root_ptr);
    }
    //if root is greater match traverse left 
    else if(strcmp(root_ptr->data.event_name, match) > 0)
    {
    	remove_name(root_ptr->left, match);  
    }
    //if not found then it is greater than root 
    else 
    	remove_name(root_ptr->right, match);  
}           //end of remove_name
/*
//finds the inorder successor to help with the deletion functions
int binary_node_tree::inorder_successor(node * root_ptr)
{
   if(!root_ptr) return 0;
   inorder_successor(root_ptr->left);
   if(root_ptr->right) 
   {
       root_ptr = root_ptr->right; 
   }
       return 1; 
}
*/
//remove the node that is passed into the function
int binary_node_tree::remove_node(node * & root_ptr)
{
        //case with no children
        if (!root_ptr->left && !root_ptr->right) 
        {
	    delete root_ptr;
	    root_ptr = NULL;
        }
        //case with one child
        else if (!root_ptr->left && root_ptr->right) 
        {
            node * temp = root_ptr; 
            root_ptr = root_ptr->left;
            delete temp;
            temp = NULL;
        }
        else if (root_ptr->left && !root_ptr->right) 
        {
            node * temp = root_ptr; 
            root_ptr = root_ptr->right;
            delete temp;
            temp = NULL;
        }
 
        //case with two children
        else
        {
            node * temp = root_ptr; 
            node * current = root_ptr->right;
            node * previous = NULL;
            while(current->left)
            {  
                previous = current;
                current = current->left;
            }
            root_ptr->data.copy(current->data);
            if(previous = NULL)
            {
                root_ptr->right = current->right;
            }
            else 
            previous->left = current->right;
            delete current; 
        }  
        return 1; 
}
/* 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 5 delete entry with found key words
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
//wrapper function for the removal funciton 
int binary_node_tree::remove_key(char * match)
{
    return remove_name(root_ptr, match);
}

//removal of a node if key word is found
int binary_node_tree::remove_key(node *& root_ptr, char * match)
{
    if(!root_ptr) return 0;
    //loop throught each key word entry
    for(int i=0; i<root_ptr->data.key_word_num; ++i)
    {
    //if match the same as root 
    if(strcmp(root_ptr->data.key_word[i], match) == 0) 
    remove_node(root_ptr);
    }   //end for loop
    //case for root is greater than the match 
    if(strcmp(root_ptr->data.event_name, match) > 0)
    {
    	remove_name(root_ptr->left, match);  
    }
    //if not found then it is greater than root 
    else 
    	remove_name(root_ptr->right, match);  
}           //end of remove_name

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - 6 retrieve match data 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//wrapper funciton for retrieve function
event_info * binary_node_tree::retrieve(char * match)
{ 
   return retrieve(root_ptr, match);
}

//preorder traversal to check for a match and return bool bsaed on success
event_info * binary_node_tree::retrieve(node * root_ptr, char * match)
{
   if(!root_ptr) return NULL;
   else if(strcmp(root_ptr->data.event_name, match) == 0) return & root_ptr->data; 
   else if(root_ptr->data.event_name > match) 
       retrieve(root_ptr->left, match);
   else 
        retrieve(root_ptr->right, match);
}

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
functioins - load in file 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//check if there is a connection to the file, if connection
//is found deep copy then call insert to load informaiton to BST
int binary_node_tree::load(binary_node_tree & load, event_info & events)
{  
    int DESCRIPTION = 300;
    char l_event_name[SIZE];
    char l_location[SIZE];
    char l_date[SIZE];
    char l_time[SIZE];
    char l_description[DESCRIPTION];
    char l_key_word[SIZE];
    char key_word[SIZE];
    char * key_word_ptr;
    int key_word_num;
    int cnt;
    
    ifstream in_file;                              //create object 
    in_file.open("Events.txt");                    //open txt file
    if (in_file)
    {
        //prime the pump
        in_file.get(l_event_name, SIZE, '|');
	in_file.ignore(SIZE, '|');
        events.event_name = new char[strlen(l_event_name) + 1];
        strcpy(events.event_name, l_event_name); 

	while (in_file && !in_file.eof()) 
	{
            in_file.get(l_location, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            events.location = new char[strlen(l_location) + 1];
            strcpy(events.location, l_location); 
	   
            in_file.get(l_date, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            events.date = new char[strlen(l_date) + 1];
            strcpy(events.date, l_date); 
            
            in_file.get(l_time, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            events.time = new char[strlen(l_time) + 1];
            strcpy(events.time, l_time); 

            in_file.get(l_description, DESCRIPTION, '|');
	    in_file.ignore(SIZE, '|');
            events.description = new char[strlen(l_description) + 1];
            strcpy(events.description, l_description); 
 
            //read in until we find the end of the line             
	    in_file.get(l_key_word, SIZE, '\n');
	    in_file.ignore(SIZE, '\n');
            
            //use strtok to split the read in information  
	    key_word_ptr = strtok(l_key_word, ",");
          
            //brake apart the key word seperated by commas, and store in
            //linked list 
            events.key_word_num = 0;
            while(key_word_ptr != NULL)
            {
	        events.key_word[events.key_word_num] = new char[strlen(key_word_ptr) + 1];
                strcpy(events.key_word[events.key_word_num], key_word_ptr);
                ++events.key_word_num;
	        key_word_ptr = strtok(NULL, ",");
            }

	     
            //insert the file into the bst 
            load.insert(events); 
	    ++cnt; //increase index
            
	    //Prime the pump
	    in_file.get(l_event_name, SIZE, '|');
	    in_file.ignore(SIZE, '|');
            if(strlen(l_event_name) > 0) 
            {            
            events.event_name = new char[strlen(l_event_name) + 1];
            strcpy(events.event_name, l_event_name); 
            }
            

	}                                         //end while
        //close the connectoin to the out file
	in_file.close();
	in_file.clear();
   }                                              //end if	
                                                 //end load 
}

//bool value to continue entering entries until false
bool again()
{
    char response;
    cout <<"Would you like to add another? Y/N ";
    cin >> response;
    cin.ignore(100, '\n');
    if (toupper(response)== 'N')
    {    
	return false;
    }
    else 
    { 
        return true;
    }
}
