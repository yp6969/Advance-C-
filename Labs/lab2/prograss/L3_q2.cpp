#include<vector>
#include<list>
#include<iterator>
#include<iostream>
using namespace std;
template<typename S, typename T, typename P>
T boo(S i, S f, T t, P p) {
  while(i != f) {
    if (p(*i))
      *t++ = *i;
    i++;
  }
  return t;
}

class Boogie {
public: bool operator() (int x) { return !(x == 0) && !(x & (x - 1)); }
};

const int Nmax=10;
int main(void) {
  vector<int> v;
  for (int i=0; i<Nmax; i++) v.push_back(i);
  list<int> l(Nmax);
  boo( v.begin(), v.end(), l.begin(), Boogie() );
  for (list<int>::iterator i=l.begin(); i!=l.end(); i++)
    cout << *i << ' ';
  cout << endl;
  return 0;
}