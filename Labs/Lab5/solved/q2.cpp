#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cstdlib>
using namespace std;

int main(void) {
      const int SIZE = 64;
      const double eps = 1e-2;
      vector<double> V;
      srand(time(NULL));
      for (int i=0 ; i<SIZE ; i++)
        V.push_back(static_cast<double>(rand())/RAND_MAX);
      /*
      TODO : replace_if a vector's coordinate is lower than eps.
      */
      ostream_iterator<double> out (cout, " ");
      copy(V.begin(), V.end(), out);
      cout << "\r\n";
      replace_if( V.begin(), V.end(),
                  [eps](double x){return x<eps ? true : false;}, 0.0 );
      copy(V.begin(), V.end(), out);
      cout << "\r\n";
      return 0;
}
