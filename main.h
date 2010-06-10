/*
 *  main.h
 *  paging
*/

#include <stdlib.h>
#include <iostream>
#include <queue>
#include <cstdlib>
#include "LineReader.h"
#include "Process.h"

using namespace std;

#define MAXINT 2147483647
#define Q 3


int driver(double, int, Process);
int randomNumber(int);

int prevFrameNumber = 1;

void faultMessage(int p, int ref, int pageNumber, int frameNumber){
	if(frameNumber < 0){
		frameNumber = (-frameNumber) - 1;
		printf("Process %i references word %i (page %i):\nFAULT, using free frame %i\n", p, ref, pageNumber, frameNumber);
	}
	else{
		printf("Process %i references word %i (page %i):\nhit in frame %i\n", p, ref, pageNumber, frameNumber);
		prevFrameNumber = frameNumber;
	}
}

