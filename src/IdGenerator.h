#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class IdGenerator
{
	unsigned maxId;
	vector<unsigned> freedIds;

	public:	
	IdGenerator();
	IdGenerator( unsigned currentMaxId );
	~IdGenerator();
//	void setMaxId( unsigned newMaxId );
	void freeId( unsigned freedId );
	unsigned newId();
};

#endif
