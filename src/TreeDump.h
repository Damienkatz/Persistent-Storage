#ifndef TREEDUMP_H
#define TREEDUMP_H

#include "Heap.h"
#include "Node.h"

using namespace std;

class TreeDump
{
	Heap heap;
	unsigned root;

	unsigned getRoot();
	void setRoot( unsigned newRootIndex );
	
	void save();
	void restore();
	void suicide();
	
	public:
	TreeDump();
	~TreeDump();
	
//	void storeNode( Node* newNode );
//	void restoreNode( Node* restoringNode );
//	void deleteNode( Node* nodeToDel );
};

#endif
