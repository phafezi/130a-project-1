# Makefile
CXX_FLAG = --std=c++17 -g

all: testHash

testHash: testHash.o auxiliaryhashtable.o
	g++ $(CXX_FLAG) -o testHash testHash.o auxiliaryhashtable.o

testHash.o: testHash.cpp
	g++ -c $(CXX_FLAG) testHash.cpp

auxiliaryhashtable.o: auxiliaryhashtable.cpp
	g++ -c $(CXX_FLAG) auxiliaryhashtable.cpp

clean:
	rm -f testHash *.o