
#ifndef PNEVERLAND_VALIDATION_H
#define PNEVERLAND_VALIDATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

#include "exceptions.h"
using namespace std;


int check_file_name(string file_name);
void  check_input_file(string file_name , vector<vector<string>>& data);



#endif
