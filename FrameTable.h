/*
 *  FrameTable.h
 *  paging
 */
#include <deque>

using namespace std;

class FrameTable{
	int machineSize;
	int pageSize;
	int frames;
	deque<int> frameVector;
public:
	FrameTable (int, int);
	bool request (int);
};
