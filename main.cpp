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

int main(int argc, char *argv[]){
	
	int M, P, S, J, N;
	
	//Convert Input string values to integers
	M = atoi(argv[1]);
	P = atoi(argv[2]);
	S = atoi(argv[3]);
	J = atoi(argv[4]);
	N = atoi(argv[5]);
	
	
	for(int i = 1; i < argc; i++)
		cout << argv[i] << " ";
	cout << endl;

	int processes;
	queue<Process> pQue;

	//Determine the proper "Job Mix"
	switch (J) {
		case 1:
			processes = 1;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(1, 0, 0, S));
			break;
		case 2:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(1, 0, 0, S));
			break;
		case 3:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(0, 0, 0, S));
			break;
		case 4:
			pQue.push(Process(.75, .25, 0, S));
			pQue.push(Process(.75, 0, .25, S));
			pQue.push(Process(.75, .125, .125, S));
			pQue.push(Process(.5, .125, .125, S));
					  
		default:
			break;
	}

	LineReader reader("random-numbers.txt");
	FrameTable ft(M, P);
	int ran = reader.nextRan();
	double y = ran/(MAXINT + 1);
	
	int w = 111;
	Process p = pQue.front();
	for(int i = 0; i < Q; i++){
		w = driver(y, (w + p.size)%p.size, p);
		cout << w << endl;
	}
	
}

int driver(double y, int w, Process p){
	if (y < p.A)
		return (w + 1 + p.size)%p.size;
	else if (y < p.A + p.B)
		return (w - 5 + p.size)%p.size;
	else if (y < p.A + p.B + p.C)
		return (w + 4 + p.size)%p.size;
	else
		return randomNumber(p.size);
}


//Return a random number between 0 and hi (From GotAPI.com).
int randomNumber(int hi)
{
	const float scale = rand()/float(RAND_MAX);
	return int(scale*hi);
}