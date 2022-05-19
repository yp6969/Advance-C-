//
// Created by ypinhas on 5/16/2022.
//

#ifndef PNEVERLAND_EXCEPTIONS_H
#define PNEVERLAND_EXCEPTIONS_H
#include <exception>
#include <string>
using namespace std;

class NeverlandException: public std::exception{

private:
    std::string e;

public:
    explicit NeverlandException(const string& e): e(e){}

    std::string what(){
        return e;
    }
};

#endif //PNEVERLAND_EXCEPTIONS_H
