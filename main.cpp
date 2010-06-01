#include <stdlib.h>
#include <iostream>
#include <queue>
#include "LineReader.h"
#include "FrameTable.h"

using namespace std;

#define MAXINT 2147483647

//Process class defines probabilities.
class Process{
	float A, B, C;
public:
	Process ();
	Process (float, float, float);
};

//Constructor
Process::Process (float a, float b, float c){
	A = a;
	B = b;
	C = c;
}

Process::Process (){
}

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
				pQue.push(Process(1, 0, 0));
			break;
		case 2:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(1, 0, 0));
			break;
		case 3:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(0, 0, 0));
			break;
		case 4:
			pQue.push(Process(.75, .25, 0));
			pQue.push(Process(.75, 0, .25));
			pQue.push(Process(.75, .125, .125));
			pQue.push(Process(.5, .125, .125));
					  
		default:
			break;
	}

	LineReader reader("random-numbers.txt");
	FrameTable ft(10, 10);
	int ref = reader.nextRef();
	cout << ft.request(ref) << endl;
	cout << ft.request(ref) << endl;
}