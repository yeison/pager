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

void faultMessage(int k, int ref, int pageNumber, int frameNumber){
	printf("%i references\n", k);
}

