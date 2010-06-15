pager: main.o frameTable.o lineReader.o process.o
	g++ -o pager main.o frameTable.o lineReader.o process.o 

main.o: main.cpp main.h
	g++ -c main.cpp

frameTable.o: FrameTable.cpp FrameTable.h
	g++ -c FrameTable.cpp

lineReader.o: LineReader.cpp LineReader.h
	g++ -c LineReader.cpp

process.o: Process.cpp Process.h
	g++ -c Process.cpp

clean:
	rm pager main.o frameTable.o lineReader.o process.o