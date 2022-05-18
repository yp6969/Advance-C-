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
    map<string, shared_ptr<Graph<string , int>>> transport;
public:
    Neverland();
    void add_route(std::string from, std::string to, unsigned int time, string type);
    friend ostream& operator<<(ostream& os, const Neverland& N);
};

#endif //PNEVERLAND_NEVERLAND_H
