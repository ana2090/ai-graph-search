#ifndef TSP_SEARCH_H
#define TSP_SEARCH_H

#include <queue>
#include "tsp_graph.h"

class Greedy_Best {
    public:
        Greedy_Best() {}
        int greedy_best_first(Graph grph, string start_city, string goal_city);

    private:
        std::queue<int> opened;
        std::vector<int> closed;
        string alg_name = "Greedy Best-First";
        int get_index_of_min(int arr[], int len);
        int get_min(int arr[], int len);
        bool is_city_closed(int idx);
        void print_path(std::vector<string> path, string search_alg);
        bool empty_queues();
};

class A_Star {
    public:
        A_Star() {}
        int a_star_search(Graph grph, string start_city, string goal_city);

    private:
        std::queue<int> opened;
        std::vector<int> closed;
        string alg_name = "A*";
        friend int Greedy_Best::get_index_of_min(int arr[], int len);
        friend int Greedy_Best::get_min(int arr[], int len);
        friend void Greedy_Best::print_path(std::vector<string> path, string search_alg);
}

#endif