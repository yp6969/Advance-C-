
#ifndef PNEVERLAND_NEVERLAND_H
#define PNEVERLAND_NEVERLAND_H
#include "Graph.h"
#include <iostream>
#include <memory>
#include "Configuration.h"

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
    Configuration config;
public:
    Neverland();
    void add_route(std::string from, std::string to, unsigned int time, string type);
    void update_config(string& file_name);
    friend ostream& operator<<(ostream& os, const Neverland& N);
    void print_configuration();
    void get_all_reachable_Stations(string source);
    void BFS(string type , string station  , map< string,bool>& reachables);
};

#endif //PNEVERLAND_NEVERLAND_H
