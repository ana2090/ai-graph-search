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
};

#endif