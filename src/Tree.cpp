#include "Tree.h"

Tree::Tree()
{	
	root = NULL;
}

Tree::~Tree()
{
	//TODO
}


unsigned Tree::newId()
{
	return idGenerator.newId();
}

Node* Tree::findNodeById( Node* rootNode, unsigned id )
{
	Node* result = NULL;
	if( rootNode != NULL )
	{
		//cout << "looking at: \n";
		//rootNode->print();
		if( rootNode->getLeftChild() != NULL )
		{
			//cout << "look left from " << rootNode->getId() << "\n";
			result = findNodeById( rootNode->getLeftChild(), id );
			if( result != NULL )
				return result;
		}
		//cout << "check myself" << rootNode->getId() << "\n";
		if( rootNode->getId() == id )
			return rootNode;
		if( rootNode->getRightSibling() != NULL )
		{
			//cout << "look right from " << rootNode->getId() << "\n";
			result = findNodeById( rootNode->getRightSibling(), id );
			if( result != NULL )
				return result;
		}
	}
	return result;
}

void Tree::addNode( char* userData, unsigned parentId )
{
	if( parentId == 0  )
	{
		//cout << "New root!";
		Node* newNode = new Node( newId(), NULL, NULL, NULL, userData );
		root = newNode;
		//root->print();
	}
	else
	{
		//cout << "try to find node by id\n";
		Node* parentNode = findNodeById( root, parentId );
		if( parentNode != NULL )
		{
			Node* newNode = new Node( newId(), parentNode, NULL, NULL, userData );
			Node* parentMostRight = parentNode->findMostRightChild();
			if( parentMostRight != NULL )
				parentMostRight->setRightSibling( newNode );
			else
				parentNode->setLeftChild( newNode );
		}
	}
}

void Tree::deleteNode( unsigned id )
{
	Node* node = findNodeById( root, id );
	if( node != NULL )
	{
		if( node->getLeftChild() == NULL && node->getRightSibling() == NULL )
		{
			if( node->getParent() == NULL )
				root = NULL;
			else 	
				if( node->getParent()->getLeftChild() == node )
					node->getParent()->setLeftChild( NULL );
				else
				{
					Node* it = node->getParent()->getLeftChild();
					while( it->getRightSibling() != node )
						it = it->getRightSibling();
					it->setRightSibling( NULL );
				}	
		}
		else
			if( node->getLeftChild() == NULL )
			{
				if( node->getParent()->getLeftChild() == node )
					node->getParent()->setLeftChild( node->getRightSibling() );
				else
				{
					Node* it = node->getParent()->getLeftChild();
					while( it->getRightSibling() != node )
						it = it->getRightSibling();
					it->setRightSibling( node->getRightSibling() );
				}	
			}
			else
				if( node->getRightSibling() == NULL )
				{
					if( node->getParent() != NULL )
					{
						if( node->getParent()->getLeftChild() != node )
						{
							Node* it = node->getLeftChild();
							while( it != NULL )
							{
								it->setParent( node->getParent() );
								it = it->getRightSibling();
							}
							it = node->getParent()->getLeftChild();
							while( it->getRightSibling() != node )
								it = it->getRightSibling();
							it->setRightSibling( node->getLeftChild() );
						}
						else
						{
							node->getParent()->setLeftChild( node->getLeftChild() );
							node->getLeftChild()->setParent( node->getParent() );
							Node* it = node->getLeftChild()->getRightSibling();
							while( it != NULL )
							{
								it->setParent( node->getLeftChild() );
								it = it->getRightSibling();
							}
							if( node->getLeftChild()->getLeftChild() != NULL )
								node->getLeftChild()->findMostRightChild()->setRightSibling( node->getLeftChild()->getRightSibling() );
							else
								node->getLeftChild()->setLeftChild( node->getLeftChild()->getRightSibling() );
							node->getLeftChild()->setRightSibling( NULL );
						}
					}
					else
					{
						root = node->getLeftChild();
						node->getLeftChild()->setParent( node->getParent() );
						Node* it = node->getLeftChild()->getRightSibling();
						while( it != NULL )
						{
							it->setParent( node->getLeftChild() );
							it = it->getRightSibling();
						}
						if( node->getLeftChild()->getLeftChild() != NULL )
							node->getLeftChild()->findMostRightChild()->setRightSibling( node->getLeftChild()->getRightSibling() );
						else
							node->getLeftChild()->setLeftChild( node->getLeftChild()->getRightSibling() );
						node->getLeftChild()->setRightSibling( NULL );
					}
				}
				else
				{

					Node* it = node->getLeftChild();
					while( it != NULL )
					{
						it->setParent( node->getParent() );
						it = it->getRightSibling();
					}
					node->findMostRightChild()->setRightSibling( node->getRightSibling() );
					if( node->getParent()->getLeftChild() == node )
						node->getParent()->setLeftChild( node->getLeftChild() );
					else
					{
						Node* it = node->getParent()->getLeftChild();
						while( it->getRightSibling() != node )
							it = it->getRightSibling();
						it->setRightSibling( node->getLeftChild() );
					}
				}
	cout << "Ща освобожу id\n";
	idGenerator.freeId( node->getId() );
	delete node;
	}
}

void Tree::printTree( Node* rootNode )
{
	if( rootNode != NULL )
	{
		//cout << "try check left. i\'m at " << rootNode << " and my id is "  << rootNode->getId() << "\n";
		if( rootNode->getLeftChild() != NULL )
		{
			//cout << "go print left\n";
			printTree( rootNode->getLeftChild() );
		}
		rootNode->print();
		if( rootNode->getRightSibling() != NULL )
			printTree( rootNode->getRightSibling() );
	}
}

Node* Tree::getRoot()
{
	return root;
}
