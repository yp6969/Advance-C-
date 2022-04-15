//
// Created by ypinhas on 4/5/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_SARSCOV2_H
#define VIRUSMUTATIONSIMULATION_SARSCOV2_H
#include <string>
#include <ostream>
#include <iostream>

using namespace std;


class SarsCov2 {
private:
//    const string target;
    const string gen;
    const char type;
    pair<string, int>* ancestor;

public:
    explicit SarsCov2(pair<string,int>* ancestor, const char type);
    SarsCov2(SarsCov2& o);
    ~SarsCov2();
//    SarsCov2& operator=(const SarsCov2& other);
    bool operator==(const SarsCov2& other) const;

    pair<string, int> *getAncestor() const;

    void setAncestor(pair<string, int> *ancestor);

    const string &getGen() const;

    bool operator!=(const SarsCov2& other) const;
//    bool operator<=(const SarsCov2& other) const;
//    bool operator<(const SarsCov2& other) const;

    double strength(const string& tar) const;
    friend ostream &operator<<(ostream &os, const SarsCov2 &cov2);

    const char &getType() const;
};


#endif //VIRUSMUTATIONSIMULATION_SARSCOV2_H
