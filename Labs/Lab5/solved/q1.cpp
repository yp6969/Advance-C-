#include <iostream>
#include <vector>
#include <algorithm>
template<class IterIn, class IterOut>
void keep_it_real(IterIn first, IterIn last, IterOut out) {
   std::vector< std::pair<IterIn,int> > s(last-first);
   for(int i=0; i < s.size(); ++i)
      s[i] = std::make_pair(first+i, i );

   std::sort(s.begin(), s.end(), [](const std::pair<IterIn,int>& a, const std::pair<IterIn,int>& b){ return *a.first < *b.first; } );

   for(const auto& x : s)
      *out++ = x.second;
 }

int main(void) {
   int a[10] = { 15,12,13,14,18,11,10,17,16,19 };
   std::vector<int> b(10);

   keep_it_real(a, a+10, b.begin());

   for (const auto& x : b) std::cout << x << ' ';
            
   std::cout << std::endl;
   return 0;
}
