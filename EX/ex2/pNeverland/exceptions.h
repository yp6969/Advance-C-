//
// Created by ypinhas on 5/16/2022.
//

#ifndef PNEVERLAND_EXCEPTIONS_H
#define PNEVERLAND_EXCEPTIONS_H
#include <exception>
#include <string>
#include <utility>
using namespace std;

class NeverlandException: public std::exception{

protected:
    std::string e;

public:
    explicit NeverlandException(string  e): e(std::move(e)){}

    virtual std::string what(){
        return e;
    }
};

class NodeNotExistException: public NeverlandException{

public:
    explicit NodeNotExistException(const string& e): NeverlandException(e){}

    std::string what() override{
        return e + " does not exist in the current network.";
    }
};


class DeadEndNodeException: public exception{};
#endif //PNEVERLAND_EXCEPTIONS_H
