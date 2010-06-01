/*
 *  LineReader.h
 *  paging
 */

#include <fstream>
#include <iostream>

using namespace std;

class LineReader{
	ifstream inStream;
public:
	LineReader(const char *);
	string nextLine();
	int nextRef();
};

