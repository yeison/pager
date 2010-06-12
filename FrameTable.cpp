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
	frame_ptr = frames - 1;
	//this->frameVector = deque<Page>(frames);
}

int FrameTable::request(Page page){
	if(!frameVector.empty()){
		for(int i = 0; i < frameVector.size(); i++)
			if(frameVector[i] == page)
				return frames - i - 1;

		if(frameVector.size() == frames)
			fifoReplace(page);
		else{
			frameVector.push_back(page);
			printf(" FAULT, using free frame %i\n", frames - frameVector.size() + 1);
		}
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
	printf(" FAULT, evicting page %i of process %i from frame %i\n", page.number, page.process, frame_ptr);
	frame_ptr > 0 ? frame_ptr--:frame_ptr = frames - 1;
}

//void FrameTable::cmpFifo(){
//	
//}