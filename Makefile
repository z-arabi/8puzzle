CXX = g++
CXXFLAGS = -std=c++17 -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++17 -Ih -pthread
OBJECTS = ./obj/tree.o ./obj/bfs.o ./obj/dfs.o ./obj/midterm.o ./obj/main.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/midterm.o: ./cpp/midterm.cpp
	$(CXX) $(CXXFLAGS) ./cpp/midterm.cpp -o ./obj/midterm.o
./obj/tree.o: ./cpp/tree.cpp
	$(CXX) $(CXXFLAGS) ./cpp/tree.cpp -o ./obj/tree.o
./obj/bfs.o: ./cpp/bfs.cpp
	$(CXX) $(CXXFLAGS) ./cpp/bfs.cpp -o ./obj/bfs.o
./obj/dfs.o: ./cpp/dfs.cpp
	$(CXX) $(CXXFLAGS) ./cpp/dfs.cpp -o ./obj/dfs.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
