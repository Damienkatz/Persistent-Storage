#include "IdGenerator.h"

//корректные id > 0
IdGenerator::IdGenerator()
{
	maxId = 0;
}

IdGenerator::IdGenerator( unsigned currentMaxId )
{
	maxId = currentMaxId;
	for( unsigned i = 1; i < maxId; i++ )
		freedIds.push_back( i );
}

IdGenerator::~IdGenerator()
{
	//TODO
}

/*void IdGenerator::setMaxId( unsigned newMaxId )
{
	if( newMaxId > maxId )
		for( unsigned i = maxId + 1; i < newMaxId; i++ )
			freeIds.push_back( i );
	else
		if( newMaxId != maxId )
			for( unsigned i = newMaxId + 1; i < maxId; i++ )
			{
				vector<unsigned>::iterator it;
				it = find( freedIds.begin(), freedIds.end(), i );
				if( it != freedIds.end() )
					freedIds.erase( it );
			}
	maxId = newMaxId;
}*/

void IdGenerator::freeId( unsigned freedId )
{
	cout << "Ну типа освобождаю id " << freedId << " а maxId " << maxId << "\n" ;
	if( freedId == maxId )
	{
		if( maxId != 0 )
			maxId--;
	}
	else
		if( freedId < maxId )
		{
			cout << "Заносим в список свободных id\n";
			freedIds.push_back( freedId ); //TODO а если больше?
		}
}

unsigned IdGenerator::newId()
{
	unsigned result;
	if( !freedIds.empty() )
	{
		result = freedIds.back();
		freedIds.pop_back();
		cout << "Have free ids. Gen id = " << result << "\n";
		return result;
	}
	else
		result = ++maxId;
		cout << "No free ids. Gen id = " << result << "\n";
		return result;
}
