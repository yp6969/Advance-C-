#include<algorithm>
#include<fstream>
#include<iostream>
#include<vector>
#include<iterator>
using std::string;
const int MAX_LENGTH = 1024;
void error(char const *name, char const *msg) {
        std::cerr << name << msg << '\n';
        std::exit(1);
}

int main (int argc, char** argv) {
        if (argc != 2)
                error (argv[0], ": Unexpected number of arguments.\n");
        std::ifstream instream(argv[1]);
        std::vector<string> v(MAX_LENGTH);
        if (!instream )
                error (argv[1], ": cannot open file.\n");

        std::istream_iterator<string> in(instream), in_end;
        std::ostream_iterator<string> out(std::cout, " ");
        std::vector<string>::iterator temp = v.begin();

        temp = std::unique_copy(in, in_end, temp);
        std::vector<string>::reverse_iterator r(temp);

        std::copy(r,v.rend(),out);
        std::cout << '\n';
        return 0;
}
