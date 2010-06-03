#include "main.h"

int main(int argc, char *argv[]){
	
	int M, P, S, J, N;
	
	//Convert argument string values to integers
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
	
	Process p = pQue.front();
	int w = (111 + p.size)%p.size;
	
	for(int i = 0; i < Q; i++){
		int ran = reader.nextRan();
		double y = ran/(MAXINT + 1.0);
		cout << w << " ";
		cout << ft.request(w) << " " << y << endl;
		w = driver(y, (w + p.size)%p.size, p);
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
		return randomNumber(p.size-1);
}


//Return a random number between 0 and hi (From GotAPI.com).
int randomNumber(int hi)
{
	const float scale = rand()/float(RAND_MAX);
	return int(scale*hi);
}