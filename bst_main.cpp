#include <iostream>
#include <string>
# include "SLinkedList.h"
#include "SearchTree.h"
#include "utilities.hpp"
#include <cassert>

int main() {

	SearchTree<Entry<string, string> > *bst1;
	SearchTree<Entry<string, string> > *bst2;
	Position<Entry<string, string> > p;
	SLinkedList<Entry<string, string>> *sll1;
	SLinkedList<Entry<string, string>> *sll2;
	cout << "==== datafile test ====" << endl;

	bst1 = buildBST_fromDatafile("datafile1.txt");
	bst2 = buildBST_fromDatafile("datafile2.txt");
	assert(bst1->size() == 171);
	assert(bst2->size() == 171);
	p = bst1->find("Steven");
	assert((*p).value() == "Hands of Stone");
	cout << "datafile1 is loaded successfully" << endl;
	p = bst2->find("Steven");
	assert((*p).value() == "Hands of Stone");
	cout << "datafile2 is loaded successfully" << endl;

	cout << "==== findPath test ====" << endl;
	sll1 = bst1->findPath("Steven");
	cout << "Steven: " << sll1->size() << " steps" << endl;
	sll2 = bst2->findPath("Steven");
	cout << "Steven: " << sll2->size() << " steps" << endl;
	printInReverseOder(sll2->gethead());

	delete(sll1); 	sll1 = NULL;
	delete(sll2);   sll2 = NULL;
	cout << "==== Your own name test ====" << endl;

	// TO DO : you need to search your own first name here
	string myownFirstName = "put your own first name here" ;

	sll1 = bst1->findPath(myownFirstName);
	cout << myownFirstName << ": " << sll1->size() << " steps" << endl;
	sll2 = bst2->findPath(myownFirstName);
	cout << myownFirstName << ": " << sll2->size() << " steps" << endl;
	printInReverseOder(sll2->gethead());
	delete(sll1);
	delete(sll2);
	delete(bst1);
	delete(bst2);
	return 0;
}

