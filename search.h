#ifndef SEARCH_H
#define SEARCH_H

#include <queue>
#include "tsp_graph.h"

class Search { // search base class
    private:
        std::queue<int> opened;
        std::vector<int> closed;

        int get_index_of_min(int arr[], int len);
        int get_min(int arr[], int len);
        bool is_city_closed(int idx);
        void print_path(std::vector<string> path, string search_alg);
        bool empty_queues();
}


#endif