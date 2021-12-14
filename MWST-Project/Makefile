CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = mwst.o

MWST: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ mwst.o

mwst.o: mwst.cpp
	$(CXX) -g $(CXXFLAGS) -c mwst.cpp

clean:
	rm *.o
	rm MWST
