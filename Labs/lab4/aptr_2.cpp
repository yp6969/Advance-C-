#include <iostream>
#include <memory>
using namespace std;

class S {
        string first;
public:
        S(const string& r) : first(r) { }
        virtual ~S(){cout << "father" << endl; }
        virtual string operator*() { return first; }
};

class CS: public S {
        string second;
public:
   CS(const string& x, const string& y) : S(x), second(y) { }
   virtual ~CS() { cout << "Computer Scientist\n"; } 
   virtual string operator*() { return second; }
};


int main(void) {
   shared_ptr<CS> a (new CS("Donald", "Knuth"));
   shared_ptr<S> b (new S(*a));
   cout << **a << ", " << **b << endl;
   return 0;
}
