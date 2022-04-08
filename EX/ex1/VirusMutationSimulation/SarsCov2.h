//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SARSCOV2_H
#define VIRUSMUTATIONSIMULATION_SARSCOV2_H
#include <string>
using namespace std;

class SarsCov2 {
private:
    string gen;

public:
    SarsCov2();
    SarsCov2(string g);
    SarsCov2(SarsCov2& o);
    ~SarsCov2();
    SarsCov2& operator=(const SarsCov2& other);

};


#endif //VIRUSMUTATIONSIMULATION_SARSCOV2_H
