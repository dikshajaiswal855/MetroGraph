
// Heap.cpp
#include "Heap.h"
#include <algorithm>

Heap::Heap(int capacity) {
    heap.reserve(capacity);
}

void Heap::push(int stationId, int distance) {
    heap.push_back({stationId, distance});
    heapifyUp(heap.size() - 1);
}

int Heap::pop() {
    std::swap(heap[0], heap.back());
    int stationId = heap.back().first;
    heap.pop_back();
    heapifyDown(0);
    return stationId;
}

bool Heap::isEmpty() {
    return heap.empty();
}

void Heap::heapifyUp(int idx) {
    while (idx > 0 && heap[idx].second < heap[(idx - 1) / 2].second) {
        std::swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void Heap::heapifyDown(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap.size() && heap[left].second < heap[smallest].second) {
        smallest = left;
    }

    if (right < heap.size() && heap[right].second < heap[smallest].second) {
        smallest = right;
    }

    if (smallest != idx) {
        std::swap(heap[idx], heap[smallest]);
        heapifyDown(smallest);
    }
}
