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
public:
	Page pages[];
	float A, B, C;
	int size;
	int pageSize;
	Process ();
	Process (float, float, float, int, int);
	void createPages();
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


int driver(double, int, Process);
int randomNumber(int);

