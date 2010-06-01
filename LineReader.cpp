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
	if(inStream.is_open()){
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

int LineReader::nextRef(){
	int ref = atoi(this->nextLine().c_str());
	return ref;
}