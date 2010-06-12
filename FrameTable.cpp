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

int FrameTable::request(Page page, int time){
	if(!frameVector.empty()){
		for(int i = 0; i < frameVector.size(); i++)
			if(frameVector[i] == page)
				return frames - i - 1;

		if(frameVector.size() == frames)
			fifoReplace(page, time);
		else{
			page.inTime = time;
			frameVector.push_back(page);
			printf(" FAULT, using free frame %i\n", frames - frameVector.size() + 1);
			faults[page.process]++;
		}
		return - (frames - frameVector.size() + 1);

	}
	else{
		cout << " Size: " << frameVector.size() << endl;
		page.inTime = time;
		frameVector.push_back(page);
		faults[page.process]++; 
		return - frames;
	}
}

void FrameTable::fifoReplace(Page page, int time){
	page.inTime = time;
	frameVector.push_back(page);
	Page evicted = frameVector.front();
	frameVector.pop_front();
	
	printf(" FAULT, evicting page %i of process %i from frame %i\n", page.number, page.process, frame_ptr);
	frame_ptr > 0 ? frame_ptr--:frame_ptr = frames - 1;
	
	//Calculate residency time.
	evicted.outTime = time;
	if(residency[page.process] == 0)
		residency[page.process] = evicted.outTime - evicted.inTime;
	else
		residency[page.process] = ((residency[page.process]) + (evicted.outTime - evicted.inTime))/2; 
	faults[page.process]++;
}