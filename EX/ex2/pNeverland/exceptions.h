//
// Created by ypinhas on 5/16/2022.
//

#ifndef PNEVERLAND_EXCEPTIONS_H
#define PNEVERLAND_EXCEPTIONS_H
#include <exception>
#include <string>
class NeverlandException: public std::exception{

private:
    std::string e;

public:
    NeverlandException(std::string e): e(e){}

    std::string what(){
        return e;
    }
};

#endif //PNEVERLAND_EXCEPTIONS_H
