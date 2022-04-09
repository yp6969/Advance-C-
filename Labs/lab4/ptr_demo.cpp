#include <iostream>
#include <memory>
using namespace std;

class Thing {
public:
    Thing() : i (++count) {cout << "Thing " << i << " creation" << endl;}
    ~Thing () {cout << "Thing " << i << " destruction" << endl;}
    int get() const {return i;}
private:
    int i;
    static int count;
};

int Thing::count = 0;

weak_ptr<Thing> return_weak()
{
    shared_ptr<Thing> p (new Thing);

    cout << "in return_weak: Thing " << p->get() << endl;

    weak_ptr<Thing> wp = p;
    return wp;
}

shared_ptr<Thing> return_shared()
{
    shared_ptr<Thing> p (new Thing);

    cout << "in return_shared: Thing " << p->get() << endl;

    return p;
}

void is_it_there(weak_ptr<Thing> wp)
{
    if (wp.expired())
        cout << "it is expired" << endl;
    else
        cout << "it is not expired" << endl;

    shared_ptr<Thing> p = wp.lock();
    if(!p)
        cout << "it is gone!" << endl;
    else
        cout <<  "it is Thing " << p->get() << endl;
}

int main(void)
{
    shared_ptr<Thing> p (new Thing);

    cout << "in main(): Thing " << p->get() << endl;

    weak_ptr<Thing> wp1 = return_weak();
    is_it_there(wp1);

    p = return_shared();
    weak_ptr<Thing> wp2 = p ;
    is_it_there(wp2);


    return 0;
}