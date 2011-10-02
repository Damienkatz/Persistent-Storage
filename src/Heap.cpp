#include "Heap.h"
 
inline int availFieldLength() { return sizeof( unsigned ); }
inline int blockSizeFieldLength() { return sizeof( unsigned ); }
inline int fillFlagFieldLength() { return sizeof( short ); }
inline int nextFreeBlockFieldLength() { return sizeof( unsigned ); }
inline int initLength() { return availFieldLength() + blockSizeFieldLength() + fillFlagFieldLength() + nextFreeBlockFieldLength(); }

Heap::Heap()
{
	int fileDescriptor;
	fileDescriptor = open( HEAP_FILE, O_RDWR | O_CREAT | O_EXCL , S_IRUSR | S_IWUSR );
	if( fileDescriptor != -1 )
	{
		//создаём файл минимальный длины с размеченным пустым блоком памяти
		
		//cout << "init length = " << initLength() << "\n";
		//lseek( fileDescriptor, initLength(), SEEK_SET );
		lseek( fileDescriptor, 2 * sizeof( unsigned ), SEEK_SET );
		write( fileDescriptor, "", 1 );
		lseek( fileDescriptor, 0, SEEK_SET );
		memory = ( char* )mmap( 0, initLength(), PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0 );
		close( fileDescriptor );
		//sprintf( memory, "%x%x%ih%x", availFieldLength(), UINT_MAX - initLength(), 0, 0 );
		sprintf( memory, "%x", UINT_MAX - ( unsigned )initLength() );
		cout << "Записал по идее " << UINT_MAX << " - " << ( unsigned )initLength() << " = " << UINT_MAX - ( unsigned )initLength() << "\n";
	}
	else
	{
		fileDescriptor = open( HEAP_FILE, O_RDWR, S_IRUSR | S_IWUSR );
		memory = ( char* )mmap( 0, initLength(), PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0 );
	//	checkHeap();//проверяем на целостность
		close( fileDescriptor );
		sscanf( memory, "%x", &avail );
		cout << "avail = " << avail << "\n";
	}

}

Heap::~Heap()
{
};
