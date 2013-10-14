/*
 *  FrameTable.cpp
 *  paging
 */

#include "FrameTable.h"
#include <iostream>

//Constructor: type defines the replacement algorithm type
// type == 0 is LRU, type < 0 is FIFO, type > 0 is Random
FrameTable::FrameTable (int m, int p, char type){
	machineSize = m;
	pageSize = p;
	//This quotient determines the number of frames.
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

/*The member function request is used to request a frame from the FrameTable.  In order to make the request, pass in the page that is to be placed in that frame.  If the page already exists, there is a hit.  If the page is not in the frameTable, a fault occurs.  The page is placed in the next available free frame.  If the frameTable is full, an eviction occurs.*/
int FrameTable::request(Page page, int time){
	if(!frameVector.empty()){
		//Iterator to the start of the frameVector (contains all the frames).
		deque<Page>::iterator iter = frameVector.begin();
		for(int i = 0; i < frameVector.size(); i++, iter++){
			//If the current element is the page.
			if(*iter == page){
				//Inform that there has been a hit.
				printf(":\n hit in frame %i", frames-i-1);
				//If the replacement algo is LRU, send the recently used page (the one that has been found) to the back of the queue/vector; it will be replaced last.
				if(lru){
					Page temp = frameVector.at(i);
					frameVector.erase(iter);
					frameVector.push_back(temp);
				}
				//If the replacement algo is random, pick a random page, and send it to the front of the queue/vector; it will be replaced first.
				else if(ran){
					deque<Page>::iterator newIter = frameVector.begin();
					int j =  randomNumber(frameVector.size());
					Page temp = frameVector.at(j);
					frameVector.erase(newIter + j);
					frameVector.push_front(temp);					
				}
				return 1;
			}
		}
		
		//If the frameVector(frame table) is full, do a page replacement.
		if(frameVector.size() == frames)
			replace(page, time);
		//If the frameVector is not full, push the page into the vector.
		else{
			page.inTime = time;
			frameVector.push_back(page);
			printf(":\n FAULT, using free frame %i", frames - frameVector.size());
			faults[page.process]++;
		}
		
		return (frames - frameVector.size() + 1);

	}
	//If the frameVector is empty, we have a special case to deal with.
	else{
		page.inTime = time;
		frameVector.push_back(page);
		faults[page.process]++; 
		printf(":\n FAULT, using free frame %i", frames - frameVector.size());
		return frames;
	}
}

/*The replacement method that is used for all of the algorithms.  The request method is respondible for organizing the vector of frames in the correct order.  The method below will take that ordered vector, pop a page from one side, and push the new page into the opposite side.  The method also handles calculatiion of residency time.*/
void FrameTable::replace(Page page, int time){
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