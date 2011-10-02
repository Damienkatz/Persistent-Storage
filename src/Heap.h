#ifndef HEAP_H
#define HEAP_H

#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <limits.h>
 #include <stdio.h>

#define HEAP_FILE "./.heap"

using namespace std;

//Класс, представляющий кучу в оперативной памяти
class Heap
{
	char* memory; //указатель на начало кучи
	unsigned avail; //индекс первого свободного блока памяти
	
	void compactMemory(); //уплотнение памяти - производит дефрагментацию памяти, перемещая все занятые блоки памяти к младшим адресам плотно друг к другу, тем самым объединяя всю свободную память в один блок 
	void concatLeft(  );
	void concatRight(  );

	public:
	Heap();
	~Heap();
	void deleteObject(  unsigned  delIndex ); //освобождает блок памяти, занятый объектом по индексу delIndex
	unsigned newObject( unsigned size ); //выделяет память для объекта размером size

};

#endif
