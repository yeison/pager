/*
 *  main.h
 *  paging
 *
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
	float A, B, C;
	int size;
	Process ();
	Process (float, float, float, int);
};

//Constructor
Process::Process (float a, float b, float c, int S){
	A = a;
	B = b;
	C = c;
	size = S;
}

Process::Process (){
}

int driver(double, int, Process);
int randomNumber(int);

