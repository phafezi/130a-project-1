# Makefile
CXX_FLAG = --std=c++17 -g

all: testHash PA1



PA1: PA1.o bloomFilter.o auxiliaryhashtable.o
	g++ $(CXX_FLAG) -o PA1 PA1.o bloomFilter.o auxiliaryhashtable.o

PA1.o: PA1.cpp
	g++ -c $(CXX_FLAG) PA1.cpp

bloomFilter.o: bloomFilter.cpp
	g++ -c $(CXX_FLAG) bloomFilter.cpp




testHash: testHash.o auxiliaryhashtable.o
	g++ $(CXX_FLAG) -o testHash testHash.o auxiliaryhashtable.o

testHash.o: testHash.cpp
	g++ -c $(CXX_FLAG) testHash.cpp

auxiliaryhashtable.o: auxiliaryhashtable.cpp
	g++ -c $(CXX_FLAG) auxiliaryhashtable.cpp

clean:
	rm -f PA1 testHash *.o