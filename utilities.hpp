#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SearchTree.h"
#include "SLinkedList.h"

using namespace std;


SearchTree<Entry<string, string> >* buildBST_fromDatafile(const std::string& filename) {
	std::ifstream f(filename.c_str());
	if (!f)
		throw std::runtime_error("cannot open data file");

	std::string s;

	getline(f, s);
	std::string magic("CPSC131 Project3 raw data file");
	if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))
		throw std::runtime_error("incorrect data file");
	getline(f, s);

	std::string firstName, movie;
    char a;
    
	SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;

	// TO DO: implement the creation of a binary search tree
    
    while (!f.eof()) { //check to see if we're at the end of the file
        while(f.get(a)) {
            if (a == ','){ //check for the ',' and stop the loop appending to first name
                break;
            }
            else {
                firstName+=a; //append char to first name
            }
        }
        while(f.get(a)) {
            if (a == '\n'){ //check for newline and break the current loop
                break;
            }
            else if (a != '\r') { //check for weird windows whitespace in txt file and passover
                movie+=a; //append movie with the new char
            }
        }
        if(firstName != "" && movie != "") { //check and see if both name and movie have an actual value
            std::cout << firstName << " " << movie << endl; //display per request
            bst->insert(firstName, movie); //insert the name and movie
        }
        firstName.clear(); //reset first name
        movie.clear(); //reset movie
    }
    
	f.close();

	return bst;
}

// TO DO: You need to implement a function to print a singly linked list in reverse order
void printInReverseOder(SNode<Entry<string,string> >* node) //make a SLL to print from in que fashion
{
	SLinkedList<SNode<Entry<string, string>>> temp_SLL; //SLL copy to store actual SLL
	SNode<Entry<string, string>> temp_node; //node copy to hold actual node
	Entry<string, string> temp_entry; //entry copy to hold actual entry
	
	//load the SLL with exsiting actual nodes to print later, treating as an enqueue
	while(node->getnext() != NULL)
	{
		temp_SLL.addFront(*node); // adds current node into SLL
		node = node->getnext(); //updates current node to be used next iteration
	}
	
	cout << "Printing in reverse order: \n";
	
	//print the temp SLL to output in reverse order, treating as a dequeue
	while(!temp_SLL.empty())
	{
		temp_node = temp_SLL.front(); //gets front of SLL list
		temp_entry = temp_node.getElem(); //gets element to print
		cout << temp_entry.key() << " ";// prints elements key "name"
		cout << temp_entry.value() << endl;// prints elements value "movie" and makes a new line
		temp_SLL.removeFront(); //removes the front element of the SLL to have the next element be first for the next iteration
	}
	return;

}


