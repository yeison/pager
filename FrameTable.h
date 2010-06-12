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
	int process, number;
	static int count;
	Page(){pageId = count++;}
	Page(int s){
		pageId = count++;
		pageSize = s;
	}
	Page(int s, int p, int n){
		pageId = count++;
		pageSize = s;
		process = p;
		number = n;
	}
	//Overload the == operator to define equality by pageId.
	bool operator== (Page that){
		return pageId == that.pageId;
	}
};

class FrameTable{
	int machineSize;
	int pageSize;
	int frames;
	int frame_ptr;
	deque<Page> frameVector;
	void fifoReplace(Page);
public:
	FrameTable (int, int);
	int request (Page);
};


