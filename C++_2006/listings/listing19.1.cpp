#include <iostream.h>
const int DefaultDize = 10;

template <class T>

class Array
{
public:
  Array(int itsSize = DefaultSize);
  Array(const Array &rhs);
  ~Array;

  Array& operator=(const Array&);
  T& operator[](int offSet) {return pType[offSet]; }

  int getSize() { return itsSize; }

private:
  T *pType;
  int itsSize;
};