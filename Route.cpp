
// Route.cpp
#include "Route.h"

Route::Route(Station* startStation, Station* endStation, int distance) {
    this->startStation = startStation;
    this->endStation = endStation;
    this->distance = distance;
}
