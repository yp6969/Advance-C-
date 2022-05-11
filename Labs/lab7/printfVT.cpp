//
// Created by ypinhas on 5/11/2022.
//
#include <iostream>
using namespace std;

/**
 * print
 */
void eprint(){
}
template <typename T>
void eprint(T var){
    cout << var << endl;
}
template <typename T, typename V, typename... Types>
void eprint(T var1, V var2, Types... var3){
    cout << var1 << " " << var2 << endl;
    eprint(var3...);
}


/**
 * printf
 *
 * printf("llll  %s  rrrrr  %d aaaa")
 */
void my_printf(const char* curr){
    if(curr == nullptr) return;
    while(*curr){
        if(*curr == '%' && *++curr != '%'){
            throw runtime_error("invalid vars, missing variable");
        }
        cout << *curr;
        curr++;
    }
}


template <typename T, typename... Types>
void my_printf(const char* curr, T var1, Types... var2){
    while (curr && *curr){
        if(*curr == '%' && *++curr != '%'){
            cout << var1;
            return my_printf(++curr, var2...);
        }
        cout << *curr;
        curr++;
    }
    throw std::runtime_error("extra arguments provided to printf");
}



/**
 *
 * Adding numbers
 */

template <typename T>
T add(T current){
    return current;
}

template <typename T, typename... Types>
T add(T current, Types... params){
    return current + add(params...);
}

int main(){
    eprint(1, "a", "sdf");

    cout << add(5,6,7,8) << endl;
    cout << add(string("asd"), string("ert"), string("345")) << endl;

    my_printf("sdfsdfsdf %s  dqwd %d sdf", "asd", 14);
}