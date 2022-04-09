#include <iostream>
#include <iterator>
#include <memory>
#include <fstream>
#include <deque>
using namespace std;

void goo (const char* iname, const char* oname) {
   shared_ptr<fstream> file(new fstream(iname , std::ios::in));
   deque<char> dc;
   istream_iterator<char> r_it(*file);
   while (r_it != istream_iterator<char>() ) {
       dc.push_front(*r_it++);
   }
   file.reset(new fstream(oname , std::ios::out));
   ostream_iterator<char> w_it(*file);
   copy(dc.begin(),dc.end(),w_it);
}

int main(int argc, char** argv) {
  if (argc < 3) {
     cerr << "REQUIRED: ifile name followed by ofile name.\n";
    return -1;
  }
  goo(argv[1],argv[2]); 
  return 0;
}
