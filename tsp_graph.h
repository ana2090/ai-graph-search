/*
    The graph implementation for a travelling salesman problem.
    - An undirected, weighted graph
    - adj matrix
*/
#ifndef TSP_GRAPH_H
#define TSP_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::find, std::min_element

using std::cout;
using std::cin;
using std::string;

#define NO_EDGE 50000

class Greedy_Best;
class A_Star;

class Graph {
    public:
        Graph(int num_vertices);
        bool create_city_list(std::vector<string> input_cities);
        bool add_edge(string start_city, string end_city, int cost);
        void print_edges(string city);
        int* get_edges(string city);   

        friend class Greedy_Best;
        friend class A_Star;

    private:
        int** adj_matrix;
        int num_vertices;
        std::vector<string> cities; // index of adj_matrix maps to city name

        int get_city_index(string city);
};

#endif