#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Thing {
public:
	Thing() : i (++count) {cout << "Thing " << i << " creation" << endl;}
	~Thing () {cout << "Thing " << i << " destruction" << endl;}
	int get_i() const {return i;}
private:
	int i;
	static int count;
};

int Thing::count = 0;

// create a Thing, but return a unique_ptr to it - ownership is transferred!
unique_ptr<Thing> create_Thing() {

    unique_ptr<Thing> p (new Thing());
	cout << "in create_Thing: p points to Thing " << p->get_i() << endl;
    
	return p;
}

void refer_to_it(unique_ptr<Thing>& p)
{
	cout << "in refer_to_it: p points to Thing " << p->get_i() << endl;
    cout << "leaving refer_to_it" << endl;
}
    
void take_it(unique_ptr<Thing> p)
{
	cout << "in take_it: p points to Thing " << p->get_i() << endl;
    cout << "leaving take_it" << endl;
}
    

int main(void) {
    //Scope 1: in a scope, let's create a Thing owned by a unique ptr, then leave the scope.
    {
        cout << "\nEntering main scope 1" << endl;
        unique_ptr<Thing> p = create_Thing();
	
        cout << "in main scope 1: p points to Thing " << p->get_i() << endl;
        unique_ptr<Thing> p2;

        cout << "Leaving main scope 1" << endl;
    }
    
    // Scope 2: create another Thing, give it to function that refers to it.
    {
        cout << "\nEntering main scope 2" << endl;
        unique_ptr<Thing> p = create_Thing();
        cout << "in main scope 2: p points to Thing " << p->get_i() << endl;
    
        refer_to_it(p);

        if(p){
            cout << "p is owns" << endl;
        }
        
        cout << "Leaving main scope 2" << endl;
    }
    
    // Scope 3: create another Thing, call to take_it Function
    {
        cout << "\nEntering main scope 3" << endl;
        unique_ptr<Thing> p = create_Thing();
        cout << "in main scope 3: p points to Thing " << p->get_i() << endl;
    
        /*
		TODO3:
		call take_it function and transfer ownership to it
		check whether p still owns anything?
		*/
        take_it(move(p));

        if(p){
            cout << "p is owns" << endl;
        }

        cout << "Leaving main scope 3" << endl;
   }
    
    // Scope 4: create some Things, pointed to with unique_ptr, and store them in a vector
    {
        cout << "\nEntering main scope 4" << endl;
        vector<unique_ptr<Thing>> v;
	
		/*
		TODO4: push_back new Thing objects, owned by unique_ptr, to v
		*/
//        unique_ptr<Thing> p = create_Thing();
        v.push_back(create_Thing());
  
        cout << "in main scope 4: v[1] points to Thing " << v[1]->get_i() << endl;
        

        cout << "in main scope 4: contents of v" << endl;
        for(auto it = v.begin(); it != v.end(); ++it) {
            if(*it)
                cout << "Thing " << (*it)->get_i() << endl;
            else
                cout << "nothing" << endl;
           }
        
        // if we want to get the unique_ptr, we have a problem
        cout << "in main scope 4: contents of v" << endl;
        /* 
		TODO5: Solve the following compilation error in order to have proper p
		*/
		for(auto it = v.begin(); it != v.end(); ++it) {
         unique_ptr<Thing> p = *it; // COMPILATION ERROR:
           
		}
        
         cout << "Leaving main scope 4" << endl;
    }
      
	cout << "Done" << endl;
	return 0;
}
