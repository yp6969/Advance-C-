//
// Created by ypinhas on 5/14/2022.
//

#ifndef PNEVERLAND_NEVERLAND_H
#define PNEVERLAND_NEVERLAND_H
#include "Graph.h"

/**
 * ENUM to represent the station type
 */
enum StationType{
    INTERCITY,
    CENTRAL,
    STAD
};

/**
 * route of one vehicle (from, to, time)
 */
struct route{
    std::pair<void*, void*> stat;
    unsigned int time;
};

struct station{
    StationType type;
    std::string name;
    // TODO - add pointer to the row in the matrix

};

class Neverland {

private:
    Graph<station, route> map;
public:
    void add_route(){
        // TODO - add station if not exist
        // TODO - add edge according to the information (from, to, time)
        // TODO -
    }

};


#endif //PNEVERLAND_NEVERLAND_H
