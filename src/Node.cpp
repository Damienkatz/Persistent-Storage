#include "Node.h"

Node::~Node()
{
	//TODO
}

Node::Node( unsigned newId, Node* newParentNode, Node* newLeftChild, Node* newRightSibling, char* userData )
{
	id = newId;
	parent = newParentNode;
	leftChild = newLeftChild;
	rightSibling = newRightSibling;
	data = userData;
}

void Node::print()
{
	cout << "Node at " << this << ". Id = " << id << ", parent =  " << parent << ", LC = " << leftChild << ", RS = " << rightSibling << " data = " << data <<  "\n";
}

Node* Node::getLeftChild()
{
	return leftChild;
}

void Node::setLeftChild( Node* newLeftChild )
{	
	leftChild = newLeftChild;
	//save(); //TODO подумать - надо ли оно тут
}

Node* Node::getRightSibling()
{
	return rightSibling;
}

void Node::setRightSibling( Node* newRightSibling )
{	
	rightSibling = newRightSibling;
//	save(); //TODO подумать - надо ли оно тут
}

char* Node::getData()
{
	return data;
}

void Node::setData( char* newData )
{
	data = newData;
//	save();
}

unsigned Node::getId()
{
	return id;	
}

void Node::setId( unsigned newId )
{
	id = newId;
//	save();
}

Node* Node::getParent()
{
	return parent;	
}

void Node::setParent( Node* newParent )
{
	parent = newParent;
//	save();
}

Node* Node::findMostRightChild()
{
	Node* result = NULL;
	if( leftChild != NULL )
	{
		result = leftChild;
		while( result->getRightSibling() != NULL )
			result = result->getRightSibling();
		return result;
	}
	return result;
}
