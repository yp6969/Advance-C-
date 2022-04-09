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
    stringstream ss(tmp);
    parse_gen(ss, target);
    if(target.length() != dimension) inputError("target gen dimension error");

    if(!input.good()) inputError("invalid file input");
    getline(input,tmp);
    if(!is_number(tmp)) inputError("Expecting integer number for the generations");
    max_generations = stoi(tmp);
    if(max_generations > MAX_GENERATIONS) inputError("number of generation need to be less then 10^6");
}

void parse_viruses(ifstream& input, int dim, int& num_of_viruses, vector<string>& virus_list){
    /**
     * parsing the viruses list
     */
    string tmp;
    if(!input.good()) inputError("invalid first_gen.dat file input");
    getline(input,tmp);
    if(!is_number(tmp)) inputError("Expecting integer number for number of viruses");
    num_of_viruses = stoi(tmp);
    if(num_of_viruses > MAX_LEN || num_of_viruses < MIN_LEN) inputError("number of viruses not in the scale");

    parse_virus_list(input, dim, virus_list);
    if(num_of_viruses != virus_list.size()) inputError("number of strings is not equal to the input number");
}

void parse_virus_list(ifstream& input, int dim, vector<string>& virus_list){
    string tmp;
    string virus;
    string type;
    if(!input.good()) inputError("invalid file input");
    while(input.good()){
        getline(input,tmp);
        stringstream ss(tmp);
        get_valid_virus_type(ss, type);
        parse_gen(ss, virus);
        if(virus.length() != dim) inputError("virus " + virus + "dimension is not valid");
        virus_list.push_back(type+virus);
    }
}

void get_valid_virus_type(stringstream& ss, string& type){
    /**
     * check valise virus type
     */
     getline(ss, type, ' ');
     if(!ss.good()) inputError("invalid virus input");
     if (!(type == "a" || type == "d" || type == "o")) inputError("invalid virus type");
}

void parse_gen(stringstream& ss, string& target){
    /**
     * checking validation and parse gen string to target
     */
    string tmp;
    stringstream t;
    while(getline(ss, tmp, ' ')) {
        if(!is_valid_letter(tmp)) inputError("invalid gen letter");
        t << tmp;
    }
    target = t.str();
}

bool is_valid_letter(string& s){
    /**
     * check if the string is one of the GEN letters
     */
    return s == "A" || s == "T" || s == "G" || s == "C" ;
}

bool is_number(const std::string& s){
    /**
     * return true if the string s is integer number like
     */
    return !s.empty() && find_if(s.begin(),s.end(),
                                 [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void inputError(const string& err){
    /**
     * print error message and exit the program
     */
    cerr<<"Error: Invalid input."<<endl;
    cerr << err << std::endl;
    exit(0);
}
