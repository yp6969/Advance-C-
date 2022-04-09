#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

template<class InIter, class OutIter, class Comparator>
void SortCopy( InIter first, InIter last, OutIter result, Comparator cmp) {
  OutIter felem(result);
  int Nelem = distance(first,last);
  while (first != last)
    *result++ = *first++;
  for (int i=0 ; i< Nelem; i++,felem++) {
    OutIter iter(felem);
    while(distance(iter,result)) {
      if(cmp(*iter,*felem)) swap(*iter,*felem);
      iter++;
    }
  }
}

int main(int argc, char** argv) {
  const int SIZE = 64;
  const int UBound = 101;
  vector<int> V, T(SIZE);
  srand(time(NULL));
  for (int i=0 ; i<SIZE ; i++)
    V.push_back(rand()%UBound);
  ostream_iterator<int> out (cout, " ");
  copy(V.begin(), V.end(), out);
  cout << "\r\n";
  int Nelem = distance(V.begin(),V.end());
  cout << "Sorting 16 first elements out of "<< Nelem <<"\r\n";
  SortCopy(V.begin(),V.begin()+15,T.begin(),less<int>());
  copy(T.begin(), T.end(), out);
  cout << "\r\n";
  return 0;
}

