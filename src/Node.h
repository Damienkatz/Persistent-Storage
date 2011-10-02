#ifndef NODE_H
#define NODE_H

#include "TreeDump.h"
#include <cstddef>
#include <iostream>

using namespace std;

class Node
{
	unsigned id;
	Node* parent;
	Node* leftChild;
	Node* rightSibling;
	char* data;
	
	
	
	//TreeDump storage;
	//save();
	//load();
	//suicide();

	public:
	Node( unsigned id, Node* parentNode, Node* leftChild, Node* rightSibling, char* userData );
	~Node();
	Node* getLeftChild();
	void setLeftChild( Node* newLeftChild );
	Node* getRightSibling();
	void setRightSibling( Node* newRightSibling );
	char* getData();
	void setData( char* newData );
	unsigned getId();
	void setId( unsigned newId );
	Node* getParent();
	void setParent( Node* newParent );
	Node* findMostRightChild();
	void print();
};

#endif
