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
	int w;
	vector<Page> pages;
	float A, B, C;
	int size, pageSize, refRemaining, number;
	
	Process();
	Process (float, float, float, int, char**);	
	
	void createPages();
	void setW(int);
};
