/*
 *  LineReader.cpp
 *  paging
*/
#include "LineReader.h"

LineReader::LineReader(const char *fileName){
	inStream.open(fileName);
}

string LineReader::nextLine(){
	string line;
	if(inStream){
		if(!inStream.eof()){
			getline(inStream, line);
			return line;
		}
		else{
			cerr << "End of File";
			return NULL;
		}
	}
	else{
		cerr << "Error opening file";
		return NULL;
	}
}

int LineReader::nextRan(){
	return atoi(this->nextLine().c_str());
}