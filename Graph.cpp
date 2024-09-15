#include "Graph.h"
#include <limits>
#include <queue>
#include <vector>
#include <iostream>

Graph::Graph() : stationCount(0) {
    // Initialize with no stations
}

void Graph::addStation(const std::string& stationName) {
    stations[stationCount] = stationName;
    stationCount++;
    adjMatrix.resize(stationCount);

    // Resize the adjacency matrix to accommodate the new station
    for (int i = 0; i < stationCount; ++i) {
        adjMatrix[i].resize(stationCount, std::numeric_limits<int>::max());
        adjMatrix[i][i] = 0; // Distance to itself is 0
    }
}

void Graph::addRoute(int stationId1, int stationId2, int distance) {
    if (stationId1 < stationCount && stationId2 < stationCount) {
        adjMatrix[stationId1][stationId2] = distance;
        adjMatrix[stationId2][stationId1] = distance; // Undirected graph
    }
}

int Graph::findShortestPath(int startStationId, int endStationId) {
    if (startStationId >= stationCount || endStationId >= stationCount) {
        return -1; // Invalid station IDs
    }

    std::vector<int> distances(stationCount, std::numeric_limits<int>::max());
    distances[startStationId] = 0;

    // Min-heap for priority queue (distance, station)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, startStationId});

    while (!pq.empty()) {
        int currDistance = pq.top().first;
        int currStation = pq.top().second;
        pq.pop();

        if (currDistance > distances[currStation]) {
            continue;
        }

        for (int neighbor = 0; neighbor < stationCount; ++neighbor) {
            if (adjMatrix[currStation][neighbor] != std::numeric_limits<int>::max()) {
                int newDist = currDistance + adjMatrix[currStation][neighbor];
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }

    return (distances[endStationId] == std::numeric_limits<int>::max()) ? -1 : distances[endStationId];
}
