/*
 *  FrameTable.h
 *  paging
 */
#include <deque>
#include <queue>
#include <vector>

using namespace std;

class Page{	
	int pageId;
	int pageSize;
public:
	int process, number, inTime, outTime;
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
	void replace(Page, int);
public:
	bool lru, ran;
	FrameTable (int, int, char);
	int request (Page, int);
	int faults[5];
	vector<float> residency[5];
	
	int randomNumber(int hi){
		const float scale = rand()/float(RAND_MAX);
		return int(scale*hi);
	}
};


