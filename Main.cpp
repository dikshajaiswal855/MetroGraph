#include "Station.h"
#include "Route.h"
#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    // Create a graph for the metro system
    Graph metroGraph;

    // Add metro stations
    metroGraph.addStation("Station A");
    metroGraph.addStation("Station B");
    metroGraph.addStation("Station C");
    metroGraph.addStation("Station D");

    // Add routes (edges) between the stations
    metroGraph.addRoute(0, 1, 5);  // From Station A to Station B with distance 5
    metroGraph.addRoute(1, 2, 10); // From Station B to Station C with distance 10
    metroGraph.addRoute(2, 3, 3);  // From Station C to Station D with distance 3
    metroGraph.addRoute(0, 3, 5); // From Station A to Station D with distance 15

    // Set source and destination stations (IDs)
    int source = 0;       // Starting at Station A (ID 0)
    int destination = 3;  // Going to Station D (ID 3)

    // Calculate the shortest path using Dijkstra's algorithm
    int distance = metroGraph.findShortestPath(source, destination);

    // Display the result
    if (distance != -1) {
        cout << "Shortest distance from Station " << source << " to Station " << destination << " is: " << distance << endl;
    } else {
        cout << "No valid path from Station " << source << " to Station " << destination << endl;
    }

    return 0;
}
