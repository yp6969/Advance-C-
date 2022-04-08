#include "utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    if(argc < 3){
        inputError("args are not inserted, please provide 2 files config.dat, first_generation.dat");
    }

    ifstream config(argv[1]);
    ifstream first_gen(argv[2]);
    if(!config || !first_gen){
        inputError("one of the following files are invalid or empty");
    }

    int dimension;
    string target;
    int generations;
    parse_config(config, dimension, target, generations);

    cout << dimension << " " << target << " " << generations << " " << endl;
//    istream_iterator<char> config_iter(config);
//    istream_iterator<char> first_gen_iter(first_gen);


    return 0;
}