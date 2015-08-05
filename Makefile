CXX=clang++
CPPFLAGS=-Wall --std=c++11
LDFLAGS=-g

c2:
	$(CXX) $(CPPFLAGS) $(LDFLAGS) tcpl.chapter.2.cpp -o main

test.evector:
	$(CXX) $(CPPFLAGS) $(LDFLAGS) test.evector.cpp -o main

test.elist:
	$(CXX) $(CPPFLAGS) $(LDFLAGS) test.elist.cpp -o main

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
