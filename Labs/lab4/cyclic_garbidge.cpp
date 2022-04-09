#include <iostream>
#include <memory>
using namespace std;

class Thing {
    weak_ptr<Thing> ptr;
    int i;
    static int count;
public:
    Thing() : i(++count) {}
    ~Thing () {cout << "Thing " << i << " destruction" << endl;}
    int get_i() const {return i;}
    void set_ptr(shared_ptr<Thing> p)
    { ptr = p; }
    void print_pointing_to() const	{
        if (ptr.expired())
            cout << "Thing " << i << " is pointing at nothing" << endl;
        else {
            shared_ptr<Thing> p = ptr.lock();
            cout <<  "Thing " << i << " is pointing to Thing " << p->get_i() << endl;
        }
    }
};

int Thing::count = 0;

int main(void) {

    shared_ptr<Thing> p1(new Thing);
    shared_ptr<Thing> p2(new Thing);

    p1->print_pointing_to();
    p2->print_pointing_to();

    p1->set_ptr(p2);
    p2->set_ptr(p1);

    p1->print_pointing_to();
    p2->print_pointing_to();


    p1.reset();
    p2->print_pointing_to();


    /*	A. YOUR IMPLEMENTATION GOES HERE; ACHIEVE THE FOLLOWING OUTPUT:
	-----
	Thing 1 is pointing at nothing
	Thing 2 is pointing at nothing
	Thing 1 is pointing to Thing 2
	Thing 2 is pointing to Thing 1
	Exiting main function
	Thing 2 destruction
	Thing 1 destruction
	-----
*/

    cout << "Exiting main function" << endl;
    return 0;
}



/* B. CAN YOU ACHIEVE THE FOLLOWING OUTPUT?
--------
Thing 1 is pointing at nothing
Thing 2 is pointing at nothing
Thing 1 is pointing to Thing 2
Thing 2 is pointing to Thing 1
Thing 1 destruction
Thing 2 is pointing at nothing
Exiting main function
Thing 2 destruction
*/