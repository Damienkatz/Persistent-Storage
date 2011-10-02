#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "IdGenerator.h"
#include <iostream>

using namespace std;

class Tree
{
	Node* root;
	IdGenerator idGenerator;
	Node* findNodeById( Node* root, unsigned id );
	unsigned newId();
	
	public:
	Tree();
	~Tree();
	void addNode( char* userData, unsigned parentId = 0 );
	void deleteNode( unsigned id );
	void printTree( Node* rootNode );
	Node* getRoot();
};

#endif
