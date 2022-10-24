#ifndef A_STAR_H
#define A_STAR_H

#include "search.h"

class A_Star: private Search {
    public:
        A_Star() {}
        int a_star_search(Graph grph, string start_city, string goal_city);
    private:
        int straight_line_heuristic(string start_city, string goal_city);
        int get_latitude(string start_city, string goal_city);
        int get_longitude(string start_city, string goal_city);
};

#endif