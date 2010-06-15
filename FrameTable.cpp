/*
 *  FrameTable.cpp
 *  paging
 */

#include "FrameTable.h"
#include <iostream>

FrameTable::FrameTable (int m, int p, char type){
	machineSize = m;
	pageSize = p;
	frames = machineSize/pageSize;
	frame_ptr = frames - 1;
	if(type == 0){
			lru = true;
			ran = false;
	}
	if(type > 0){
			ran = true;
			lru = false;
	}
	else{
			lru = false;
			ran = false;
	}
}
	//this->frameVector = deque<Page>(frames);

int FrameTable::request(Page page, int time){
	if(!frameVector.empty()){
		deque<Page>::iterator iter = frameVector.begin();
		for(int i = 0; i < frameVector.size(); i++, iter++){
			if(*iter == page){
				printf(":\n hit in frame %i", frames-i-1);
				if(ran){
					deque<Page>::iterator newIter = frameVector.begin();
					int j =  randomNumber(frameVector.size());
					Page temp = frameVector.at(j);
					frameVector.erase(newIter + j);
					frameVector.push_back(temp);					
				}
				else if(lru){
					Page temp = frameVector.at(i);
					frameVector.erase(iter);
					frameVector.push_back(temp);
				}
				
				return 1;
			}
		}
		
		if(frameVector.size() == frames)
			fifoReplace(page, time);
		else{
			page.inTime = time;
			frameVector.push_back(page);
			printf(":\n FAULT, using free frame %i", frames - frameVector.size());
			faults[page.process]++;
		}
		
		return - (frames - frameVector.size() + 1);

	}
	else{
		page.inTime = time;
		frameVector.push_back(page);
		faults[page.process]++; 
		printf(":\n FAULT, using free frame %i", frames - frameVector.size());
		return - frames;
	}
}

void FrameTable::fifoReplace(Page page, int time){
	page.inTime = time;
	frameVector.push_back(page);
	Page evicted = frameVector.front();
	frameVector.pop_front();
	
	faults[page.process]++;
	printf(":\n FAULT, evicting page %i of process %i from frame %i", evicted.number, evicted.process, frame_ptr);
	frame_ptr > 0 ? frame_ptr--:frame_ptr = frames - 1;
	
	//Calculate residency time.
	evicted.outTime = time;
	residency[evicted.process].push_back(evicted.outTime - evicted.inTime);
}