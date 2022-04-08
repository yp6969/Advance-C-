#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>


using namespace std;

void parse_viruses(ifstream& input);
void parse_config(ifstream& input, int& dim, string& target, int& max_generations);
bool is_number(const std::string& s);
void inputError(const string& s);
void parse_gen(const string& s, string& t);
bool is_valid_letter(string& s);

#define MAX_DIM 1000
#define MIN_DIM 3
#define MAX_GENERATIONS 1000000
#define MAX_GEN 200
#define MIN_GEN 2


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


void parse_config(ifstream& input, int& dimension, string& target, int& max_generations){
    /**
     * parsing valid config file to dimension target str and num of iterations
     */
    string tmp;
    if(!input.good()) inputError("invalid file input");
    getline(input,tmp);
    if(!is_number(tmp)) inputError("Expecting integer number for the dimension");
    dimension = stoi(tmp);
    if(dimension > MAX_DIM || dimension < MIN_DIM) inputError("dimension not in the scale");

    if(!input.good()) inputError("invalid file input");
    getline(input,tmp);
    parse_gen(tmp, target);
    if(target.length() != dimension) inputError("target gen dimension error");

    if(!input.good()) inputError("invalid file input");
    getline(input,tmp);
    if(!is_number(tmp)) inputError("Expecting integer number for the generations");
    max_generations = stoi(tmp);
    if(max_generations > MAX_GENERATIONS) inputError("number of generation need to be less then 10^6");
}

void parse_viruses(istream_iterator<char>& input){

}

void parse_gen(const string& s, string& t){
    string tmp;
    stringstream ss(s);
    stringstream target;
    while(std::getline(ss, tmp, ' ')) {
        if(!is_valid_letter(tmp)) inputError("invalid gen letter");
        target << tmp;
    }
    t = target.str();
}

bool is_valid_letter(string& s){
    return s == "A" || s == "T" || s == "G" || s == "C" ;
}

bool is_number(const std::string& s)
{
    return !s.empty() && find_if(s.begin(),s.end(),
                                 [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void inputError(const string& err){
    cerr<<"Error: Invalid input."<<endl;
    cerr << err << std::endl;
    exit(0);
}
