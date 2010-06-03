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

bool FrameTable::request(Page page){
	for(int i = 0; i < frames; i++)
		if(frameVector[i] == page)
			return true;
	frameVector.pop_front();
	frameVector.push_back(page);
	return false;
}

//void FrameTable::cmpFifo(){
//	
//}