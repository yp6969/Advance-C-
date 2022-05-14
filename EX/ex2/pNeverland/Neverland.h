//
// Created by ypinhas on 5/14/2022.
//

#ifndef PNEVERLAND_NEVERLAND_H
#define PNEVERLAND_NEVERLAND_H
#include "Graph.h"
#include <iostream>
#include <memory>
/**
 * ENUM to represent the station type
 */
enum StationType{
    INTERCITY,
    CENTRAL,
    STAD
};

/**
 * TODO - intercity = "IC"
 * TODO - centeral = "CS"
 */

/**
 * route of one vehicle (from, to, time)
 */

struct station{
    StationType type;
    std::string name;
    // TODO - add pointer to the row in the matrix

};


struct route{
    std::pair<std::shared_ptr<station>, std::shared_ptr<station>> stat;
    unsigned int time;
};


class Neverland {

private:
    Graph<station, route> map;
public:
    void add_route(std::string from, std::string to, unsigned int time){
        /*TODO -
         * searching the names of the stations:
         * if not exist, create new station and add it to the vertices
         * which station that is exist hold its reference
         * searching the edge in the matrix:
         * if not exist create new edge and add it to the matrix
         */



        // TODO - add station if not exist
        // TODO - add edge according to the information (from, to, time)
        // TODO - create the edge here and send the reference
    }

    station& get_station_by_name(std::string name){
        for(auto& v: map.vertices) {
            if (v.name == name) {
                return v;
            }
        }
    }

    route& get_edge(){
        for(auto& v: map.edges)
            for(auto& e: v){
                if(e == nullptr)
            }
    }

};


#endif //PNEVERLAND_NEVERLAND_H
