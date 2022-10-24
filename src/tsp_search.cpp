#include "tsp_search.h"

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

int Greedy_Best::get_index_of_min(int arr[], int len) {
    int min = NO_EDGE;
    int min_idx = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == NO_EDGE || is_city_closed(i)) continue;
        if (arr[i] < min) {
            min = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int Greedy_Best::get_min(int arr[], int len) {
    int min = NO_EDGE;
    for (int i = 0; i < len; i++) {
        if (arr[i] == NO_EDGE || is_city_closed(i)) continue;
        else if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// true if city is in closed vector, false if not
bool Greedy_Best::is_city_closed(int idx) {
    auto it = std::find(closed.begin(), closed.end(), idx);
    if (it != closed.end()) return true;
    return false;
}

void Greedy_Best::print_path(std::vector<string> path, string search_alg) {
    cout << "OUT: printing " << search_alg << "'s Path from " << path.front()
        << " to " << path.back() << "\n---";
    for (int i = 0; i < int (path.size()); i++) {
        cout << path[i] << ", ";
    }
    cout << "\n";
}

// empty the queues
bool Greedy_Best::empty_queues() {
    closed.clear();
    while (!opened.empty()) {
        opened.pop();
    }
    if (!closed.empty()) {
        cout << "ERROR: closed vector failed to clear content\n";
        return false;
    }
    return true;
}