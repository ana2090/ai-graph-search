#ifndef GREEDY_H
#define GREEDY_H

#include "search.h"

class Greedy_Best: private Search { 
    // public members of Search are private members of Greedy_Best
    public:
        Greedy_Best() {}
        int greedy_best_first(Graph grph, string start_city, string goal_city);
        int greedy_best_tsp(Graph grph, string city);
    private:
        string alg_name = "Greedy Best-First";
        // overloaded; from search.cpp but now have stuck parameter
        int get_index_of_min(int arr[], int len, std::vector<int> stuck);
        int get_min(int arr[], int len, std::vector<int> stuck);
        
        bool check_tsp_done(string city, string curr_city, std::vector<string> path, Graph grph);
        bool is_city_stuck(int idx, std::vector<int> stuck);
};

#endif