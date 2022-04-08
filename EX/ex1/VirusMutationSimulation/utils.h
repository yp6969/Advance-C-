//
// Created by Pinhas on 08/04/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_UTILS_H
#define VIRUSMUTATIONSIMULATION_UTILS_H

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>


#define MAX_DIM 1000
#define MIN_DIM 3
#define MAX_GENERATIONS 1000000
#define MAX_LEN 200
#define MIN_LEN 2

using namespace std;


void parse_viruses(ifstream& input);
void parse_config(ifstream& input, int& dim, string& target, int& max_generations);
bool is_number(const std::string& s);
void inputError(const string& s);
void parse_gen(const string& s, string& t);
bool is_valid_letter(string& s);

#endif //VIRUSMUTATIONSIMULATION_UTILS_H
