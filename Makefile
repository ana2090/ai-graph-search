OBJS = greedy.o search.o tsp_graph.o main.o
SOURCE = greedy.cpp search.cpp tsp_graph.cpp main.cpp
CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic

tsp:
	$(CC) $(CFLAGS) $(SOURCE) -o tsp
clean:
	\rm *.o tsp