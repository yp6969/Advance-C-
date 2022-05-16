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


class Neverland {

private:
    map<string, unique_ptr<Graph<string , int>>> transport;
public:

    Neverland(){
        transport.insert({"bus", nullptr});
        transport.insert({"rail", nullptr});
        transport.insert({"tram", nullptr});
        transport.insert({"sprinter", nullptr});
    }



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
};


#endif //PNEVERLAND_NEVERLAND_H
