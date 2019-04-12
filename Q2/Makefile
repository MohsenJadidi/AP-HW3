CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = main.o vector.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
vector.o: vector.cpp vector.h
	$(CXX) $(CXXFLAGS) vector.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
