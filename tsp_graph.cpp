#include "tsp_graph.h"

// creates an num_vertices x num_vertices size matrix, [i][j] = 50000
Graph::Graph(int num_vertices) {
    this->num_vertices = num_vertices;
    adj_matrix = new int*[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = NO_EDGE;
        }
    }
    cout << "LOG: initalized a " << num_vertices << " x " << num_vertices
        << " matrix with each entry to 50000\n";
}

// creates the list of cities
// length has to be same as num_vertices
bool Graph::create_city_list(vector<string> input_cities) {
    if (int(input_cities.size()) != this->num_vertices) {
        cout << "ERROR: city list length not same as number of vertices in graph\n";
        return false;
    }
    cities = input_cities;
    return true;
}

// creates an edge between the 2 input cities
// true if success, false if failed
bool Graph::add_edge(string start_city, string end_city, int cost) {
    int start_idx = get_city_index(start_city);
    int end_idx = get_city_index(end_city);

    if (start_idx == -1|| end_idx == -1) {
        cout << "ERROR: index failure in add_edge\n";
        return false;
    }

    adj_matrix[start_idx][end_idx] = cost; // undirected so fill both locations
    adj_matrix[end_idx][start_idx] = cost;
    return true;
}

// print all the edges from the input city with their costs
void Graph::print_edges(string city) {
    int idx = get_city_index(city);

    cout << "OUT: printing all edges from " << city << "\n";
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[idx][i] != NO_EDGE) {
            cout << "--- " << city << " to " << cities[i] << " is "
                << adj_matrix[idx][i] << "\n";
        }
    }
    
}

// returns the row of the input city, containing the edges
int* Graph::get_edges(string city) {
    int idx = get_city_index(city);
    return adj_matrix[idx];
}    

// returns the index of where the city is in the vector
// failure is -1
int Graph::get_city_index(string city) {
    auto it = std::find(cities.begin(), cities.end(), city);

    if (it != cities.end()) {
        return it - cities.begin();
    }
    cout << "ERROR: failed to find city's index in vector in get_ciy_index\n";
    cout << "---city was " << city << "\n";
    return -1;
}