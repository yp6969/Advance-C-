//
#ifndef PNEVERLAND_USER_INTERACTION_H
#define PNEVERLAND_USER_INTERACTION_H


#include "Validation.h"
#include <sstream>
#include <iostream>
#include "vector"
#include "string"
//#include "exceptions.h"

void initializing(int size, const char** files);
void get_input();
void split_str( string const &str,vector <string> &out ,  const char delim=' ' );
void print_input(vector <string> &out);
void set_pNeverland(string file_name);
void print_data_container();

#endif
