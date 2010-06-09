/*
 *  Process.cpp
 *  paging
 */

#include "Process.h"

//Constructor
Process::Process(float a, float b, float c, char *argv[]){
	A = a;
	B = b;
	C = c;
	
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
}

void Process::createPages(){
	for(int i = 0; i < this->size/pageSize; i ++){
		Page temp(pageSize);
		pages.push_back(pageSize);
	}
	
}

void Process::setW(int k){
	if(!dirty){
		w = (111*k + size)%size;
		dirty = true;
	}
}
