#include <stdexcept>
#include <sstream>
#include "Matrix.hpp"

std::ostream & operator <<( std::ostream & s, const Matrix & a ){
    std::string returned;
    for (int i = 0; i < a.data.size(); i++){
        returned += (std::to_string(a.data[i]) + "\t");
        if (!((i+1) % a.columnsCount)) {
          returned += "\n";
        }
      }

    return s << returned;
}

Matrix operator !( const Matrix & a){
  Matrix returned;
  int size = a.data.size();
  returned.columnsCount = size/a.columnsCount;

  for (int i = 0; i < a.columnsCount; i++){
    for (int j = 0; j < size; j+=a.columnsCount ){
      returned.data.push_back(a.data[i+j]);
    }
  }
   return returned;
}

Matrix operator +( const Matrix & a, const Matrix & b ){
  if ((a.data.size() != b.data.size()) || (a.columnsCount != b.columnsCount)){
    throw std::invalid_argument("Matrixes cannot be added"); 
  }
  Matrix returned;
  returned.columnsCount = a.columnsCount;
  for (int i = 0; i < a.data.size(); ++i) {
    returned.data.push_back(a.data[i] + b.data[i]);
  }

    return returned;
}

Matrix operator -( const Matrix & a, const Matrix & b ){
  if ((a.data.size() != b.data.size()) || (a.columnsCount != b.columnsCount)){
    throw std::invalid_argument("Matrixes cannot be subtracted"); 
  }
  Matrix returned;
  returned.columnsCount = a.columnsCount;
  for (int i = 0; i < a.data.size(); ++i) {
    returned.data.push_back(a.data[i] - b.data[i]);
  }

    return returned;
}

Matrix operator *( const double & a, const Matrix & b ){
  Matrix returned;
  returned.columnsCount = b.columnsCount;
  for (int i = 0; i < b.data.size(); ++i) {
    returned.data.push_back(a * b.data[i]);
  }

    return returned;
}
