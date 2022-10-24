#include "greedy.h"

int Greedy_Best::greedy_best_first(Graph grph, string start_city, string goal_city) {
    cout << "\nLOG: " << start_city << " to " << goal_city << "\n";
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
        min = this->Search::get_min(curr_edges, grph.num_vertices);
        min_idx = this->Search::get_index_of_min(curr_edges, grph.num_vertices);

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

int Greedy_Best::greedy_best_tsp(Graph grph, string city) {
    cout << "\nLOG: " << city << " to " << city << "\n";
    if (!opened.empty() || !closed.empty()) {
        if (!empty_queues()) exit(1);
    }

    int total_cost = 0;
    string current_city = city;
    int* curr_edges;
    int min, min_idx;
    std::vector<string> path;
    std::vector<int> stuck; // vertices that lead to a path where you get stuck

    path.push_back(city);      
    opened.push(grph.get_city_index(city));

    do {
        if (check_tsp_done(city, current_city, path, grph)) {
            total_cost += grph.get_edge(city, current_city);
            break;
        }

        curr_edges = grph.get_edges(current_city);

        closed.push_back(opened.front());
        opened.pop();

        // get min of the current edges from this city & check if city is closed
        min = get_min(curr_edges, grph.num_vertices, stuck);
        min_idx = get_index_of_min(curr_edges, grph.num_vertices, stuck);

        if (min_idx == -1 || min == NO_EDGE) { // not at goal, but no edge found
            cout << "LOG: no edge found from " << current_city << "\n";
            cout << "---adding " << current_city << " to stuck vector\n";

            stuck.push_back(grph.get_city_index(current_city));

            // remove current vertex from closed
            closed.pop_back();

            // push parent vertex back to opened then remove from closed
            opened.push(closed.back());
            closed.pop_back();

            // remove cost of parent vertex to vertex from total_cost
            total_cost -= grph.adj_matrix[stuck.back()][opened.front()];

            // set current_city to parent vertex, remove from path
            current_city = path[path.size() - 2];
            path.pop_back();

            if (int(stuck.size()) >= grph.num_vertices - 1) {
                cout << "LOG: no path can be found from " << city << " to " <<
                    city << " without repeating vertices\n";
                return -1;
            }

            continue;
        }

        // add to the total cost
        total_cost += min;

        // set that as the current city
        current_city = grph.cities[min_idx];
        path.push_back(current_city);
        opened.push(min_idx);
        
    } while (current_city != city || int(path.size()) < grph.num_vertices);

    // print path vector
    print_path(path, alg_name);
    cout << "---total cost is " << total_cost << "\n";
    return total_cost;
}

int Greedy_Best::get_index_of_min(int arr[], int len, std::vector<int> stuck) {
    int min = NO_EDGE;
    int min_idx = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == NO_EDGE || is_city_closed(i) || is_city_stuck(i, stuck)) continue;
        if (arr[i] < min) {
            min = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int Greedy_Best::get_min(int arr[], int len, std::vector<int> stuck) {
    int min = NO_EDGE;
    for (int i = 0; i < len; i++) {
        if (arr[i] == NO_EDGE || is_city_closed(i) || is_city_stuck(i, stuck)) continue;
        else if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// true if city is in stuck vector, false if not
bool Greedy_Best::is_city_stuck(int idx, std::vector<int> stuck) {
    auto it = std::find(stuck.begin(), stuck.end(), idx);
    if (it != stuck.end()) return true;
    return false;
}

/*
    Checks if all the vertices have been travelled to and if there is an edge between
        the goal and the current vertex. If both things are true, it appends the
        goal to the path and returns true. Otherwise false.
*/
bool Greedy_Best::check_tsp_done(string city, string curr_city, std::vector<string> path, Graph grph) {
    if (int(path.size()) != grph.num_vertices) return false;

    if (grph.get_edge(city, curr_city) != NO_EDGE) {
        path.push_back(city);
        return true;
    }
    return false;
}