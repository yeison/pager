/*
 *  FrameTable.cpp
 *  paging
 */

#include "FrameTable.h"

FrameTable::FrameTable (int m, int p){
	machineSize = m;
	pageSize = p;
	frames = machineSize/pageSize;
	this->frameVector = deque<Page>(frames);
}

int FrameTable::request(Page page){
	for(int i = (frames - 1); i >= 0; i--)
		if(frameVector[i] == page)
			return i;
	frameVector.pop_front();
	frameVector.push_back(page);
	return -1;
}

//void FrameTable::cmpFifo(){
//	
//}