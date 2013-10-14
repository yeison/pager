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

// W is word
void Process::setNextReference(int k){
	if(!dirty){
		w = (111*k)%size;
		dirty = true;
	}
}

//The driver determines what kind of reference is being made.
int Process::driver(double y, int w){
	if (y < this->A)
		return (w + 1 + this->size)%this->size;
	else if (y < this->A + this->B)
		return (w - 5 + this->size)%this->size;
	else if (y < this->A + this->B + this->C)
		return (w + 4 + this->size)%this->size;
	else
		return randomNumber(this->size-1);
}

//Return a random number between 0 and hi (From GotAPI.com).
int Process::randomNumber(int hi)
{
	const float scale = rand()/float(RAND_MAX);
	return int(scale*hi);
}
