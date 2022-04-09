#include <iostream>
#include <vector>
#include <algorithm>
/*
template<class T, class U>
struct ACDC {
   bool operator()(const std::pair<T,U>& a, const std::pair<T,U>& b) const {
      return *a.first < *b.first; }
 };
*/
template<class IterIn, class IterOut>
void rock_n_roll(IterIn first, IterIn last, IterOut out) {
   std::vector< std::pair<IterIn,int> > s(last-first);
   for(int i=0; i < s.size(); ++i)
      s[i] = std::make_pair(first+i, i);

   std::sort(s.begin(), s.end(), [](const std::pair<IterIn,int>& a, const std::pair<IterIn,int>& b){ return *a.first < *b.first; } );

   for(int i=0; i < s.size(); ++i, ++out)
      *out = s[i].second;
 }

int main(void) {
   int a[10] = { 15,12,13,14,18,11,10,17,16,19 };
   std::vector<int> b(10);

   rock_n_roll(a, a+10, b.begin());

//   for(int i=0; i<10; ++i) std::cout << b[i] << ' ';
   for (const auto& x : b) std::cout << x << ' ';
            
   std::cout << std::endl;
   return 0;
}
