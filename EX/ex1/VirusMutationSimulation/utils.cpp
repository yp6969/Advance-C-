//
// Created by Pinhas on 08/04/2022.
//

#include "utils.h"


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

void parse_viruses(ifstream& input, int& num_of_viruses, vector<string>& virus_list){
    /**
     * parsing the viruses list
     */
    string tmp;
    if(!input.good()) inputError("invalid first_gen.dat file input");
    getline(input,tmp);
    if(!is_number(tmp)) inputError("Expecting integer number for number of viruses");
    num_of_viruses = stoi(tmp);
    if(num_of_viruses > MAX_LEN || num_of_viruses < MIN_LEN) inputError("number of viruses not in the scale");


    parse_virus_list(input, virus_list);
}

void parse_virus_list(ifstream& input, vector<string>& virus_list){

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
