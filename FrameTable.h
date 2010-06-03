/*
 *  FrameTable.h
 *  paging
 */
#include <deque>
#include <queue>

using namespace std;

class FrameTable{
	int machineSize;
	int pageSize;
	int frames;
	deque<int> frameVector;
public:
	FrameTable (int, int);
	bool request (int);
};

class Page{	
	int pageId;
	int pageSize;
public:
	static int count;
	Page(){pageId = count++;}
	Page(int s){
		pageId = count++;
		pageSize = s;
	}
};
