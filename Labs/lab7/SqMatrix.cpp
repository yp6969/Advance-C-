#include <utility>
#include <iostream>
#include <memory>
#include "Application.h"

class Application;
template <typename T, unsigned int N>
class SqMatrix {
  T _arr[N][N];
  std::unique_ptr<Application> _appPtr;
public:
  /* copy c'tor: 	could be eliminated using =delete, or alternatively, the contained pointer could be taken using std::move when the copied argument is no longer const; those answers were accepted only upon giving an explanation.  */
  SqMatrix(const SqMatrix& m) : //assuming copy c'tor for Application
  _appPtr{std::make_unique<Application>(*((m._appPtr).get()))} {  
    for (int i = 0; i< N; i++)
      for (int j = 0; j< N; j++)
        _arr[i][j] = m._arr[i][j]; //assuming copy assignment for T
  }
  SqMatrix(SqMatrix&& a) : _arr{a._arr}, _appPtr{std::move(a._appPtr)} {
    a._arr = nullptr;
  }
  /*  Similar statements as for the copy c'tor.  */
  SqMatrix& operator=(const SqMatrix& m) {
    _appPtr.reset(std::make_unique<Application>(*((m._appPtr).get())));
    for (int i = 0; i< N; i++)
      for (int j = 0; j< N; j++)
        _arr[i][j] = m._arr[i][j]; //assuming copy assignment for T
  }        
  SqMatrix& operator=(SqMatrix&& a) {
    std::swap(_arr, a._arr);
    _appPtr.reset(a._appPtr);
  }
  ~SqMatrix() { }
  
  SqMatrix(Application*);
  //...
};