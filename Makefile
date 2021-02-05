CC = g++
CCFLAGS = -g -std=c++11

sets:	main.cpp 
	$(CC) $(CCFLAGS)  -o sets main.cpp