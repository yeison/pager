#include "main.h"
//0 Pages at the beginning of this program.
int Page::count = 0;

int main(int argc, char *argv[]){
	int M, P, S, J, N;
	string R;

	//Convert argument string values to integers
	M = atoi(argv[1]);
	P = atoi(argv[2]);
	S = atoi(argv[3]);
	J = atoi(argv[4]);
	N = atoi(argv[5]);
	R = argv[6];
	char type = R.compare("lru");

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
				pQue.push(Process(1, 0, 0, i+1, argv));
			break;
		case 2:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(1, 0, 0, i+1, argv));
			break;
		case 3:
			processes = 4;
			for(int i = 0; i < processes; i++)
				pQue.push(Process(0, 0, 0, i+1, argv));
			break;
		case 4:
			processes = 4;
			pQue.push(Process(.75, .25, 0, 1, argv));
			pQue.push(Process(.75, 0, .25, 2, argv));
			pQue.push(Process(.75, .125, .125, 3, argv));
			pQue.push(Process(.5, .125, .125, 4, argv));

		default:
			break;
	}

	LineReader reader("random-numbers.txt");
	FrameTable ft(M, P, type);
	int k = 1;
	int time = 1;
	for(int j = 0; j < N*processes; ){
		Process p = pQue.front();
		p.setW(k);
		for(int i = 0; i < Q && j < N*processes && p.refRemaining > 0; i++, j++){
			int ran = reader.nextRan();
			double y = ran/(MAXINT + 1.0);
			int pageNumber = p.w/P;
			faultMessage(k, p.w, pageNumber);
			ft.request(p.pages[pageNumber], time);
			p.w = driver(y, (p.w + p.size)%p.size, p);
			//One less reference remaining for this p (process).
			p.refRemaining--;
			time++;
		}
		k < processes ? k++:k=1;
		pQue.pop();
		pQue.push(p);
	}

	cout << endl;

	int totalFaults = 0;
	int i;
	float overall;
	for (i = 1; i <= processes; i++) {
		totalFaults += ft.faults[i];

		vector<float>::iterator iter;
		iter = ft.residency[i].begin();
		int j = 0;
		float total;
		while(iter != ft.residency[i].end()){
			total += *iter;
			++iter;
			j++;
		}

		float avg = total/j;
		total = 0;
		printf("\nProcess %i had %i faults and %f average residency.", i, ft.faults[i], avg);

		overall += avg;
	}

	printf("\nTotal number of faults is %i, and the overall average residency is %f.\n", totalFaults, overall/(i-1));

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

