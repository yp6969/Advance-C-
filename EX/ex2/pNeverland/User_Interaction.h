//
// Created by User on 15/05/2022.
//

#ifndef HW2_USER_INTERACTION_H
#define HW2_USER_INTERACTION_H

#include <sstream>
#include <iostream>
#include "vector"
#include "string"
using namespace std;

void initializing(int size, const char** files);
void get_input();
void split_str( string const &str,vector <string> &out ,  const char delim=' ' );
void print_input(vector <string> &out);


#endif //HW2_USER_INTERACTION_H
