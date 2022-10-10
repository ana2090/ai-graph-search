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
        vector<int> closed;
        int get_index_of_min(int arr[], int len);
        int get_min(int arr[], int len);
        bool is_city_closed(int idx);
        void print_path(vector<string> path);
        bool empty_queues();
};

#endif