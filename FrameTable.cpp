/*
 *  FrameTable.cpp
 *  paging
 */

#include "FrameTable.h"
#include <iostream>

FrameTable::FrameTable (int m, int p){
	machineSize = m;
	pageSize = p;
	frames = machineSize/pageSize;
	//this->frameVector = deque<Page>(frames);
}

int FrameTable::request(Page page){
	if(!frameVector.empty()){
		for(int i = 0; i < frameVector.size(); i++)
			if(frameVector[i] == page)
				return i;
		if(frameVector.size() == frames)
			fifoReplace(page);
		else
			frameVector.push_back(page);
		return - (frames - frameVector.size() + 1);

	}
	else{
		cout << " Size: " << frameVector.size() << endl;
		frameVector.push_back(page);
		return -frames;
	}
}

void FrameTable::fifoReplace(Page page){
	frameVector.push_back(page);
	frameVector.pop_front();
}

//void FrameTable::cmpFifo(){
//	
//}