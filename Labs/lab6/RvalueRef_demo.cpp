#include <iostream>

using namespace std;

//void foo(int i) {
//    cout << "foo with call by value " << i << endl;
//    i++;
//    cout << "i is now " << i << endl;
//}

void foo(int& i) {
    cout << "foo with call by reference " << i << endl;
    i++;
    cout << "i is now " << i << endl;
}


//void foo(const int& i) {
//    cout << "foo with call by reference to const " << i << endl;
// //   i++;
//    cout << "i is now " << i << endl;
//}


void foo(int&& i) {
    cout << "foo with call by rvalue reference " << i << endl;
    i++;
    cout << "i is now " << i << endl;
}

int return_an_int() {
    static int i = 10;
    i++;
    return i;
}

int main() {
    int int1 = 6;
    foo(17);
    foo(int1);
    cout << "int1 is now " << int1 << endl;
    foo(static_cast<int&&>(int1));
    cout << "int1 is now " << int1 << endl;
    foo(return_an_int());
	return 0;
}