# Makefile
CXX_FLAG = --std=c++17 -g

all: testHash main



main: main.o bloomFilter.o auxiliaryhashtable.o
	g++ $(CXX_FLAG) -o main main.o bloomFilter.o auxiliaryhashtable.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

bloomFilter.o: bloomFilter.cpp
	g++ -c $(CXX_FLAG) bloomFilter.cpp




testHash: testHash.o auxiliaryhashtable.o
	g++ $(CXX_FLAG) -o testHash testHash.o auxiliaryhashtable.o

testHash.o: testHash.cpp
	g++ -c $(CXX_FLAG) testHash.cpp

auxiliaryhashtable.o: auxiliaryhashtable.cpp
	g++ -c $(CXX_FLAG) auxiliaryhashtable.cpp

clean:
	rm -f testHash *.o