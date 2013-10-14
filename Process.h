/*
 *  Process.h
 *  paging
 */
#include <vector>
#include "FrameTable.h"

//Process class defines probabilities.
class Process{
	bool dirty;
public:
    // Word
	int w;
	vector<Page> pages;
	float A, B, C;
	int size, pageSize, refRemaining, number;
	
	Process();
	Process (float, float, float, int, char**);	
	
	void createPages();
	void setNextReference(int);
    int driver(double y, int w);
    int randomNumber(int hi);

};
