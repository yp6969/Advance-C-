#include<ostream>
#include<fstream>
#include<algorithm>
#include<array>
#include<cstdlib>
using namespace std;

const int NSIZE = 16;
class RandVar {
public:
	RandVar() : _val(rand()) { }
	void save(ostream& os) const { os << _val << endl; }
private:
	int _val;
};

int main(void) {
    ofstream out_file("output.txt"); 
    array<RandVar,NSIZE> rands;

	/*
	TODO: apply std::for_each on rands to save all its elements
	*/
	for_each(rands.begin(), rands.end(),[&out_file](const RandVar& rv){rv.save(out_file);} );
    return 0;
}