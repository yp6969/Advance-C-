

#ifndef PNEVERLAND_CONFIGURATION_H
#define PNEVERLAND_CONFIGURATION_H
#include <string>
#include <map>
#include <iostream>

using namespace std;
struct Configuration {
    map<string , int> c ={{"bus" , 0},{"tram", 2}, {"sprinter" ,  3},
                          { "rail", 5 }, { "intercity", 15 },
                          { "central", 10 },{ "stad", 5 }};

    const int& operator[] (const string& key) const {
        return c.at(key);
    }
    int& operator[] ( const string& key ){
        return c[key] ;
    }
};


#endif //PNEVERLAND_CONFIGURATION_H
