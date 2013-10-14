pager: main.o frameTable.o lineReader.o process.o
	clang++ -std=c++11 -stdlib=libc++ -o pager main.o frameTable.o lineReader.o process.o 

main.o: main.cpp main.h
	clang++ -std=c++11 -stdlib=libc++ -c main.cpp

frameTable.o: FrameTable.cpp FrameTable.h
	clang++ -std=c++11 -stdlib=libc++ -c FrameTable.cpp

lineReader.o: LineReader.cpp LineReader.h
	 clang++ -std=c++11 -stdlib=libc++ -c LineReader.cpp

process.o: Process.cpp Process.h
	clang++ -std=c++11 -stdlib=libc++ -c Process.cpp

clean:
	rm pager main.o frameTable.o lineReader.o process.o
