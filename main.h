/*
 *  main.h
 *  paging
*/

#include <stdlib.h>
#include <iostream>
#include <queue>
#include <cstdlib>
#include "LineReader.h"
#include "FrameTable.h"

using namespace std;

#define MAXINT 2147483647
#define Q 3


//Process class defines probabilities.
class Process{
	bool dirty;
public:
	int w;
	Page pages[];
	float A, B, C;
	int size;
	int pageSize;
	Process ();
	Process (float, float, float, int, int);
	void createPages();
	void setW(int);
};

//Constructor
Process::Process(float a, float b, float c, int S, int P){
	A = a;
	B = b;
	C = c;
	size = S;
	pageSize = P;
}

Process::Process(){
}

void Process::createPages(){
	for(int i = 0; i < this->size/pageSize; i ++)
		pages[i] = Page(pageSize);
	
}

void Process::setW(int k){
	if(!dirty){
		w = (111*k + size)%size;
		dirty = true;
	}
}


int driver(double, int, Process);
int randomNumber(int);

