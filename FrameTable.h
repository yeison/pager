/*
 *  FrameTable.h
 *  paging
 */
#include <deque>
#include <queue>

using namespace std;

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
	//Overload the == operator to define equality by pageId.
	bool operator== (Page that){
		return this->pageId == that.pageId;
	}
};

class FrameTable{
	int machineSize;
	int pageSize;
	int frames;
	deque<Page> frameVector;
public:
	FrameTable (int, int);
	bool request (Page);
};
