
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
    map<string, Graph<string , int>> o_transport;
    Configuration config;
    string outputfile_name;
public:
    Neverland();
    void add_route(const string& from, const string& to, unsigned int time, const string& type);
    void update_config(string& file_name);
    friend ostream& operator<<(ostream& os, const Neverland& N);
    void print_configuration();
    void BFS(const string& type ,const string& station  , map< string,bool>& reachables );
    void inbound_outbound(const string& station ,const string& func);
    void set_outputfile(string filename);
};

#endif //PNEVERLAND_NEVERLAND_H
