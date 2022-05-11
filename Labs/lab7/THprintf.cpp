#include<iostream>
#include<stdexcept>
//#include<type_traits>
using namespace std;
struct Point { int x,y; };
ostream& operator<<(ostream& o, const Point& p) { return o<<'('<<p.x<<','<<p.y<<") "; }

void THprintf(const char* s) {
     if (s==nullptr) return;
     while (*s) {
          if (*s=='%' && *++s!='%') // make sure no more arguments are expected
                                    // %% represents plain % in a format string
                throw runtime_error("invalid format: missing arguments");
          std::cout << *s++;
     }
}
/* -- BASIC VERSION -- */
template<typename T, typename... Args>      // variadic template argument list: one or more arguments
void THprintf(const char* s, T value, Args... args)    // function argument list: two or more arguments
{
     while (s && *s) {
          if (*s=='%' && *++s!='%') {           // a format specifier (ignore which one it is)
                std::cout << value;            // use first non-format argument
                return THprintf(++s, args...);   // do a recursive call with the tail of the argument list
          }
          std::cout << *s++;
     }
     throw std::runtime_error("extra arguments provided to printf");
}
/* -- VERSION WITH ERROR-CHECKING; requires the implementation of Is_string 
template<typename T, typename... Args>       // variadic template argument list: one or more arguments
void THprintf(const char* s, T value, Args... args)  // function argument list: two or more arguments
{
     while (s && *s) {
          if (*s=='%') {  // a format specifier or %%
                switch (*++s) {
                case '%':     // not format specifier
                      break;
                case 's':
                      if (!Is_string<T>())
                             throw runtime_error("Bad printf() format");
                      break;
                case 'd':
                      if (!is_integral<T>()) throw runtime_error("Bad printf() format");
                      break;
                case 'g':
                      if (!is_floating_point<T>()) throw runtime_error("Bad printf() format");
                      break;
                }
                std::cout << value;              // use first non-format argument
                return THprintf(++s, args...);     // do a recursive call with the tail of the argument list
          }
          std::cout <<*s++;
     }
     throw std::runtime_error("extra arguments provided to printf");
}*/

int main(void) {
  THprintf("The value of %s is %g\n","x",3.14); //should work as in C
  string name = "the target point";
  THprintf("The value of %s %d is %P\n",name,3.14,Point{34,200}); //should work if Point has operator<<
  THprintf("The value of %s is %g\n",7); //wrong number of arguments
  return 0;
}
