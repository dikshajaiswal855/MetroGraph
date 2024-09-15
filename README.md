# The Metro App - C++ Implementation

This project simulates a metro system using a graph-based structure for representing metro stations and routes. It also uses a heap (priority queue) to find the shortest route between stations using Dijkstra's algorithm.

## Features
- **Graph Representation**: Stations and routes are represented as a graph with an adjacency list.
- **Shortest Path Calculation**: Dijkstra’s algorithm is used to calculate the shortest path between stations.
- **Heap (Priority Queue)**: A heap is used to optimize the shortest path algorithm.

## Files

1. **Main.cpp**: The entry point of the program where user interaction happens.
2. **Station.cpp**: Defines the `Station` class, representing each metro station.
3. **Route.cpp**: Defines the `Route` class, managing the routes between stations.
4. **Graph.cpp**: Implements a graph structure to store stations and routes, and provides the shortest path calculation.
5. **Heap.cpp**: Implements a heap (priority queue) used in Dijkstra’s algorithm to process stations efficiently.

## Getting Started

### Prerequisites
You need a C++ compiler installed on your machine. You can use `g++`, which is available in the GCC compiler collection.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/[your-username]/metro-app-cpp.git
