#include "greedy.h"

int main(int argc, const char* argv[]) {
   Graph romania(20);

   std::vector<string> romania_cities = {"arad", "zerind", "sibiu", "timisosara", 
   "oradea", "fagaras", "rimnicu", "lugoj", "bucharest", "pitesti", "craiova",
    "mehadia", "giurgiu", "dobreta", "urziceni", "hirsova", "eforie", "vasiul",
    "iasi", "neamt"};

   if (!romania.create_city_list(romania_cities)) {
    cout << "LOG: failure in create_city_list\n";
    return 1;
   }
   
   romania.add_edge("arad", "zerind", 75);
   romania.add_edge("arad", "sibiu", 140);
   romania.add_edge("arad", "timisosara", 118);
   romania.add_edge("zerind", "oradea", 71);
   romania.add_edge("sibiu", "fagaras", 99);
   romania.add_edge("sibiu", "rimnicu", 80);
   romania.add_edge("timisosara", "lugoj", 111);
   romania.add_edge("oradea", "sibiu", 151);
   romania.add_edge("fagaras", "bucharest", 211);
   romania.add_edge("rimnicu", "pitesti", 97);
   romania.add_edge("rimnicu", "craiova", 146);
   romania.add_edge("craiova", "pitesti", 138);
   romania.add_edge("lugoj", "mehadia", 70);
   romania.add_edge("mehadia", "dobreta", 75);
   romania.add_edge("craiova", "dobreta", 120);
   romania.add_edge("pitesti", "bucharest", 101);
   romania.add_edge("bucharest", "giurgiu", 90);
   romania.add_edge("bucharest", "urziceni", 85);
   romania.add_edge("urziceni", "hirsova", 98);
   romania.add_edge("hirsova", "eforie", 88);
   romania.add_edge("urziceni", "vasiul", 142);
   romania.add_edge("vasiul", "iasi", 92);
   romania.add_edge("iasi", "neamt", 87);
   
   romania.print_edges("craiova");

   Greedy_Best search;
   //search.greedy_best_first(romania, "arad", "bucharest");
    search.greedy_best_first(romania, "fagaras", "dobreta");
    search.greedy_best_tsp(romania, "bucharest");

    //////////////////////////////////////////////////////////

   std::vector<string> circle_vertices = {"a", "b", "c", "d", "e"};

    Graph circle(circle_vertices.size());
    Greedy_Best search2;

   if (!circle.create_city_list(circle_vertices)) {
    cout << "LOG: failure in create_city_list\n";
    return 1;
   }
   
   circle.add_edge("a", "b", 3);
   circle.add_edge("b", "c", 3);
   circle.add_edge("c", "d", 3);
   circle.add_edge("d", "e", 3);
   circle.add_edge("e", "a", 3);

   search2.greedy_best_tsp(circle, "a");

    return 0;
}