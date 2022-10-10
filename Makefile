OBJS = tsp_search.o tsp_graph.o main.o
CC = g++
CFLAGS = -Wall -Werror -std=c++11 -pedantic

all: tsp

tsp: $(OBJS)
	$(CC) $(OBJS) -o tsp
tsp_search.o: tsp_search.cpp tsp_search.h
	$(CC) $(CFLAGS) tsp_search.cpp
tsp_graph.o: tsp_graph.cpp tsp_graph.h
	$(CC) $(CFLAGS) tsp_graph.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	\rm *.o tsp