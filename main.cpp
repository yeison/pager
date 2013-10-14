#include "main.h"
//0 Pages at the beginning of this program.
int Page::count = 0;

void faultMessage(int p, int ref, int pageNumber, int time){
	printf("\nProcess %i references word %i (page %i) at time %i", p, ref, pageNumber, time);
}

int main(int argc, char *argv[]){
	int machineSize, pageSize, processSize, jobMix, numberOfReferences;
	string R;

	// Convert argument string values to integers
	machineSize = atoi(argv[1]);
	pageSize = atoi(argv[2]);
	processSize = atoi(argv[3]);
	jobMix = atoi(argv[4]);
	numberOfReferences = atoi(argv[5]);
	R = argv[6];
	// Read the type of the replacement algorithm. There are 3 possibilities.  I use string.compare
	// to figure out which case is used.
	char type = R.compare("lru");

	cout << "The Machine Size is " << machineSize << endl;
	cout << "The Page Size is " << pageSize << endl;
	cout << "The Process Size is " << processSize << endl;
	cout << "The Job mix is " << jobMix << endl;
	cout << "The number of references per process is " << numberOfReferences << endl;
	cout << "The replacement algorithm is " << R << endl;

	int processes;
	queue<Process> processQueue;

	//Determine the proper "Job Mix"
	switch (jobMix) {
		case 1:
			processes = 1;
			for(int i = 0; i < processes; i++)
				processQueue.push(Process(1, 0, 0, i+1, argv));
			break;
            
		case 2:
			processes = 4;
			for(int i = 0; i < processes; i++)
				processQueue.push(Process(1, 0, 0, i+1, argv));
			break;
            
		case 3:
			processes = 4;
			for(int i = 0; i < processes; i++)
				processQueue.push(Process(0, 0, 0, i+1, argv));
			break;
            
		case 4:
			processes = 4;
			processQueue.push(Process(.75, .25, 0, 1, argv));
			processQueue.push(Process(.75, 0, .25, 2, argv));
			processQueue.push(Process(.75, .125, .125, 3, argv));
			processQueue.push(Process(.5, .125, .125, 4, argv));

		default:
			break;
	}


    
	//Read the list of random numbers.
    LineReader *reader = new LineReader("random-numbers.txt");
    FrameTable *frameTable = new FrameTable(machineSize, pageSize, type);



    
//   	int k = 1;
//    
//    while (!processQueue.empty()) {
//        Process process = processQueue.front();
//        processQueue.pop();
//        
//        process.setNextReference(k);
//        
//        // Increment to next process
//        k < processes ? k++:k=1;
//
//    }


	int k = 1;
	int time = 1;
	for(int j = 0; j < numberOfReferences*processes; ){
		Process process = processQueue.front();
		process.setNextReference(k);
        
		for(int i = 0; i < QUANTUM && j < numberOfReferences*processes && process.refRemaining > 0; i++, j++){

			int ran = reader->nextRan();
			double y = ran/(2147483648 + 1.0);
	
            int pageNumber = process.w/pageSize;
            
			faultMessage(k, process.w, pageNumber, time);
			frameTable->request(process.pages[pageNumber], time);
            
			process.w = process.driver(y, process.w );
            
			//One less reference remaining for this p (process).
			process.refRemaining--;
			time++;
            
		}
        
        // Keep k in between 1 and 4
		k < processes ? k++:k=1;
        
        
		processQueue.pop();
		processQueue.push(process);

	}

	cout << endl;

	//Sum the total number of faults. In addition, calculate the overall average residency.
	int totalFaults = 0;
	int i;
	float overall = 0;
    int overallIters = 0;
    
	for (i = 1; i <= processes; i++) {
		totalFaults += frameTable->faults[i];

		vector<float>::iterator iter;
		iter = frameTable->residency[i].begin();
		int j = 0;
		float total = 0;
		while(iter != frameTable->residency[i].end()){
			total += *iter;
			++iter;
			j++;
		}

		float avg = total/j;
   	    overall += total;
        overallIters += j;
		total = 0;
        
		printf("\nProcess %i had %i faults and %f average residency.", i, frameTable->faults[i], avg);

	}

	printf("\nTotal number of faults is %i, and the overall average residency is %f.\n", totalFaults, overall/overallIters);

}



