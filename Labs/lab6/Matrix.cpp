/*
The C++ Programming Language (B.S. 4th Ed.)
*/
#include <array>

using namespace std;
template<class T>
class Matrix {
     std::array<int,2> dim;
     T* elem; // pointer to size() elements of type T

public:
     Matrix(int d1, int d2) :dim{d1,d2}, elem{new T[d1*d2]} {}
     int size() const { return dim[0]*dim[1]; }

     Matrix(const Matrix& m): dim(m.dim), elem(m.elem){}             // copy constructor
     Matrix(Matrix&& m): dim(move(m.dim)), elem(m.elem){
         m.elem = nullptr;
     }                  // move constructor

     Matrix& operator=(const Matrix& m){
         dim = m.dim;
         elem = m.elem;
     }  // copy assignment
     Matrix& operator=(Matrix&& m){
         dim = m.dim;
         elem = m.elem;
         m.elem = nullptr;
     }       // move assignment

     ~Matrix(){
         while(elem){
             delete *elem;
             elem++;
         }
     } // destructor

	 // ...

};
