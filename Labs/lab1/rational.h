#include <string>
#include <sstream>
#include <iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<iterator>
#include <math.h>


using namespace std;

class rational {
  int numerator, denominator;
public:

    // Constructors
    rational();          // Zero
    rational(int n);       // Equal to n/1
    rational(int n, int d) throw (logic_error);  // General case (n/d)
    rational(const string& str) throw (logic_error);

    rational& operator=(int n);

    operator string();

    rational& assign(int n, int d);

    // Representation
    int getNum() const;
    int getDenom() const;

    // Arithmetic operators
    rational& operator+= (const rational& r);
    rational& operator-= (const rational& r);
    rational& operator*= (const rational& r);
    rational& operator/= (const rational& r);

    // Comparison operators
    bool operator< (const rational& r) const;
    bool operator== (const rational& r) const;


    struct Index{
      Index(double p) : _p(p) {}
      Index const& operator*() const {return *this;}
      double _p; 
    };

    int const f (int a, int b) const;

    friend rational myPow(const rational& r, const Index& d) {
        return rational(pow(r.numerator, d._p), pow(r.denominator, d._p));
    }
    friend rational operator*(const rational& r, const Index& d){
        return myPow(r, d);
    }
};