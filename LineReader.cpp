/*
 *  LineReader.cpp
 *  paging
 * The LineReader program reads the list of random numbers provided.  This program
 * contains a method to easily access the next random number in the list.
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