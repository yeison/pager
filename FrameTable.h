/*
 *  FrameTable.h
 *  paging
 */
#include <deque>
#include <queue>
#include <vector>
#include <array>
#include <boost/container/map.hpp>

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
    
    int getPageId(){
        return pageId;
    }
    
    pair<int, Page> getPair(){
        return *new pair<int, Page>(pageId, *this);
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
    boost::container::map<int, Page> frameMap;
	deque<Page> frameVector;
	void replace(Page, int);
public:
	bool lru, ran;
	FrameTable (int, int, char);
	int request (Page, int);
    array<int, 5> faults = {0};
	vector<float> residency[5];
	
	int randomNumber(int hi){
		const float scale = rand()/float(RAND_MAX);
		return int(scale*hi);
	}
};
