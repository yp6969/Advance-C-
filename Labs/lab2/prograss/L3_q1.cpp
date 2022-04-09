#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;
struct Moore {
  bool operator() (int x, int y) { return ((x%4) > (y%4)) ; }
} Roger;
 
int main(void) {
  const int SIZE = 10;
  int array [ SIZE ] = { 2, 6, 4, 8, 12, 10, 16, 14, 20, 18 } ;
  list<int> L (array, array+SIZE);
  L.sort( Roger );
  ostream_iterator<int> out (cout, " ");
  copy(L.begin(), L.end(), out);
  return 0;
}
