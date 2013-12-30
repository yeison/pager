stdlib="-stdlib=libc++"

pager: main.o frameTable.o lineReader.o process.o
	clang++ -Wall -g $(stdlib) -o pager main.o frameTable.o lineReader.o process.o 

main.o: main.cpp main.h
	clang++ -Wall -g $(stdlib)  -c main.cpp

frameTable.o: FrameTable.cpp FrameTable.h
	clang++ -Wall -g  $(stdlib) -c FrameTable.cpp

lineReader.o: LineReader.cpp LineReader.h
	clang++ -Wall -g  $(stdlib) -c LineReader.cpp

process.o: Process.cpp Process.h
	clang++ -Wall -g  $(stdlib) -c Process.cpp

clean:
	rm pager main.o frameTable.o lineReader.o process.o
