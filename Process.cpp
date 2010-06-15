/*
 *  Process.cpp
 *  paging
 
 An instance of Process contains much of the input data.  In addition, the probabilities
 for A, B, C, and random type references are contained in the process.
 
 */

#include "Process.h"

//Constructor
Process::Process(float a, float b, float c, int n, char *argv[]){
	A = a;
	B = b;
	C = c;
	number = n;
	
	//Convert argument string values to integers
	int M, P, S, J, N;
	M = atoi(argv[1]);
	P = atoi(argv[2]);
	S = atoi(argv[3]);
	J = atoi(argv[4]);
	N = atoi(argv[5]);
	
	size = S;
	pageSize = P;
	refRemaining = N;
	
	createPages();
	dirty = false;

}

void Process::createPages(){
	for(int i = 0; i < this->size/pageSize; i ++){
		Page temp(pageSize, number, i);
		pages.push_back(temp);
	}
	
}

void Process::setW(int k){
	if(!dirty){
		w = (111*k + size)%size;
		dirty = true;
	}
}
