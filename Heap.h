// Heap.h
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <utility>

class Heap {
    std::vector<std::pair<int, int>> heap; // (stationId, distance)

    void heapifyUp(int idx);
    void heapifyDown(int idx);

public:
    Heap(int capacity);
    void push(int stationId, int distance);
    int pop();
    bool isEmpty();
};

#endif
