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
    vector<string> virus_list;
    int num_of_viruses;

    parse_config(config, dimension, target, generations);
    parse_viruses(first_gen, dimension, num_of_viruses, virus_list);



    cout << dimension << " " << target << " " << generations << " " << endl;
    cout << num_of_viruses << endl;
    for(string& s: virus_list){
        cout << s << endl;
    }

    return 0;
}