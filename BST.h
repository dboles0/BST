//Donald C Boles
//ID: 903512976
//CS_163 Spring 2017
//Program Assignment #4 

//BST.h file

/* node class for a linked base binary tree
@file */


#include"event_info.h"

struct node
{
    event_info data; 
    node * left;
    node * right;    
};

class binary_node_tree

{
public: 
    binary_node_tree(); 
    binary_node_tree(int key_item_num);
    ~binary_node_tree(); 
    int insert(event_info & new_data);   
    int height();
    bool display_all();
    int remove_name(char * match);
    int remove_node(node * & root_ptr);
    //int delete_duplicate_key();
    event_info * retrieve(char * match);
    int load(binary_node_tree & load, event_info & events);
    int remove_key(char * match);

protected:
    //called by the destructor to delete all nodes in the tree
    int destroy_tree(node *& root_ptr);
    //int delete_key_word(key_node * &head);
    int insert(node * &root_ptr, event_info & new_data);
    int height (node * root_ptr);
    bool display_all(node * root_ptr, bool success);
    //int display_key_list(key_node * head);
    int remove_name(node *& root_ptr, char * match);
    //int inorder_successor(node * & root_ptr);
    //int compare_match(node * &root_ptr);
    int remove_key(node *& root_ptr, char * match);
    //int remove_key_match(node * &root_ptr);
    event_info * retrieve(node * root_ptr, char * match);

private:
    node * root_ptr;           //root of the tree
    char ** key_word_array;   
};

bool again();
