#include "a_star.h"

int A_Star::a_star_search(Graph grph, string start_city, string goal_city) {
    if (!opened.empty() || !closed.empty()) {
        if (!empty_queues()) exit(1);
    }


}

int A_Star::straight_line_heuristic(string start_city, string goal_city) {
    int lat, lon;
    lat = get_latitude(start_city, goal_city);
    lon = get_longitude(start_city, goal_city);


}

int A_Star::get_latitude(string start_city, string goal_city) {

}

int A_Star::get_longitude(string start_city, string goal_city) {

}