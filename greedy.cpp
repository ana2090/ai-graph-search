#include "greedy.h"

int Greedy_Best::greedy_best_first(Graph grph, string start_city, string goal_city) {
    if (!opened.empty() || !closed.empty()) {
        if (!empty_queues()) exit(1);
    }

    int* curr_edges = grph.get_edges(start_city);
    string current_city = start_city;
    int total_cost = 0;
    int min, min_idx;
    std::vector<string> path;
    path.push_back(start_city);

    opened.push(grph.get_city_index(start_city));

    while (current_city != goal_city) {

        // remove current city from queue and put in closed queue
        closed.push_back(opened.front());
        opened.pop();
            
        // get min of the current edges from this city & check if city is closed
        min = get_min(curr_edges, grph.num_vertices);
        min_idx = get_index_of_min(curr_edges, grph.num_vertices);

        if (min_idx == -1 || min == NO_EDGE) { // not at goal, but no edge found
            cout << "LOG: no edge found from " << current_city << "\n";
            print_path(path, alg_name);
            return total_cost;
        }

        // add to the total cost
        total_cost += min;

        // set that as the current city
        current_city = grph.cities[min_idx];
        path.push_back(current_city);
        opened.push(min_idx);

        // change row to the new current city
        curr_edges = grph.get_edges(current_city);
        // or use adj_matrix[min_idx]
    }

    // print path vector
    print_path(path, alg_name);
    cout << "---total cost is " << total_cost << "\n";
    return total_cost;
}