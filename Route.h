// Route.h
#ifndef ROUTE_H
#define ROUTE_H

#include "Station.h"

class Route {
public:
    Station* startStation;
    Station* endStation;
    int distance;

    Route(Station* startStation, Station* endStation, int distance);
};

#endif
