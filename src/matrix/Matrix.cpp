#include <stdexcept>
#include <sstream>
#include <cmath>
#include "Matrix.hpp"

Matrix minor(Matrix matrix, int i, int j) {
  Matrix returned;
  returned.columnsCount = matrix.columnsCount - 1;
  for (int k = 0; k < matrix.data.size(); ++k){
    bool isRowToRemove = matrix.columnsCount * j <= k  && k < matrix.columnsCount * (j + 1);
    bool isColToRemove = (k % matrix.columnsCount) == i;
    if (!(isRowToRemove || isColToRemove)) {
      returned.data.push_back(matrix.data[k]);
    } 
  }
  return returned;
}

double matrixDeterminant(Matrix matrix){
  int size = matrix.columnsCount;
  if (size == 1 ) {
    return matrix.data[0];
  } else {
    double sum = 0.0;
    int j = 0;
    for (int i = 0; i < size; i++) { 
          double part = (matrix.getElement(i, j) * std::pow(-1, i+1 + j+1) * matrixDeterminant(minor(matrix, i, j)));
        sum = sum + part; 
    }
    return sum;
  }
}

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
