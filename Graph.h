#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>

class Graph {
public:
    Graph(); // Constructor

    // Add a station
    void addStation(const std::string& stationName);

    // Add a route between two stations
    void addRoute(int stationId1, int stationId2, int distance);

    // Find the shortest path using Dijkstra's algorithm
    int findShortestPath(int startStationId, int endStationId);

private:
    std::unordered_map<int, std::string> stations; // Station ID to name
    std::vector<std::vector<int>> adjMatrix;       // Adjacency matrix
    int stationCount;                              // Number of stations
};

#endif
