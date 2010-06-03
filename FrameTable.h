/*
 *  FrameTable.h
 *  paging
 */
#include <deque>
#include <queue>

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
