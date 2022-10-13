#include "search.h"


int Search::get_index_of_min(int arr[], int len) {
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

int Search::get_min(int arr[], int len) {
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
bool Search::is_city_closed(int idx) {
    auto it = std::find(closed.begin(), closed.end(), idx);
    if (it != closed.end()) return true;
    return false;
}

void Search::print_path(std::vector<string> path, string search_alg) {
    cout << "OUT: printing " << search_alg << "'s Path from " << path.front()
        << " to " << path.back() << "\n---";
    for (int i = 0; i < int (path.size()); i++) {
        cout << path[i] << ", ";
    }
    cout << "\n";
}

// empty the queues
bool Search::empty_queues() {
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