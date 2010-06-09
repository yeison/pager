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
	int size, pageSize, refRemaining;
	
	Process();
	Process (float, float, float, char**);	
	
	void createPages();
	void setW(int);
};
