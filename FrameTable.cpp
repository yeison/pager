/*
 *  FrameTable.cpp
 *  paging
 */

#include "FrameTable.h"

FrameTable::FrameTable (int m, int p){
	machineSize = m;
	pageSize = p;
	frames = machineSize/pageSize;
	this->frameVector = deque<int>(frames);
}

bool FrameTable::request(int ref){
	for(int i = 0; i < frames; i++)
		if(frameVector[i] == ref)
			return true;
	frameVector.pop_front();
	frameVector.push_back(ref);
	return false;
}

//void FrameTable::cmpFifo(){
//	
//}