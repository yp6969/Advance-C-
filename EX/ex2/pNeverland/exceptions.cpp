
#ifndef PNEVERLAND_EXCEPTIONS_CPP
#define PNEVERLAND_EXCEPTIONS_CPP
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

#endif //PNEVERLAND_EXCEPTIONS_CPP
