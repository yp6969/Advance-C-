#include <iostream>
#include <map>
#include <iterator>
using namespace std;
template <typename T> class HBO {
public: bool operator()(const T& a, const T& b) const {
      return a > b;
   }
};
typedef std::multimap< double, string, HBO<double> > mmh;

int main(void) {
   mmh tvs;
   tvs.insert( mmh::value_type(8.5,string("Olive Kitteridge")) );
   tvs.insert( mmh::value_type(9.4,string("The Sopranos")) );
   tvs.insert( mmh::value_type(9.4,string("The Wire")) );
   tvs.insert( mmh::value_type(9.1,string("Game of Thrones")) );
   tvs.insert( mmh::value_type(8.7,string("Boardwalk Empire")) );
   tvs.insert( mmh::value_type(9.4,string("True Detective")) );
   mmh::const_iterator iter = tvs.begin();
   unsigned short list = 4;
   while (list--) {
      cout << iter->first << '\t'<< iter->second << '\n';
      iter++;
   }
   return 0;
}
