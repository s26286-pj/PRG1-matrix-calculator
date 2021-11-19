#include <stdexcept>
#include <sstream>
#include <cmath>
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

Matrix operator *( const Matrix & a, const Matrix & b ){
  Matrix returned;

  if (a.columnsCount != b.data.size()/b.columnsCount) {
    throw std::invalid_argument("Matrixes cannot be multiplied"); 
  }
  
  int rows = a.data.size()/a.columnsCount;
  int cols = b.columnsCount;

  int length = cols * rows;
  returned.columnsCount = cols;
  for (int i = 0; i < length; ++i)
  {
    returned.data.push_back(0);
  }
  int rMax = a.columnsCount;

  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      double sum = 0.0;
      for (int r = 0; r < rMax; r++) {
        double x = getElement(r, j, a);
        double y = getElement(i, r, b);
        sum = sum + (x * y);
      }
      returned.setElement(i, j, sum);
    }
  }
  return returned;
}

Matrix operator ~( const Matrix & a){
  // https://en.wikipedia.org/wiki/Invertible_matrix#Analytic_solution
  int size = a.data.size();
  if (a.columnsCount == 2 && size == 4) {
    double determinant = matrixDeterminant(a);
    if (determinant) {
      Matrix partial;
      partial.columnsCount = 2;
      partial.data.push_back(a.data[3]);
      partial.data.push_back(- a.data[1]);
      partial.data.push_back(- a.data[2]);
      partial.data.push_back(a.data[0]);

      return 1/determinant * partial;
    } else {
      throw std::invalid_argument("Matrix cannot be inversed - determinant equals 0"); 
    }
  } else if (a.columnsCount == 3 && size == 9) {
    double determinant = matrixDeterminant(a);
    if (determinant) {
      Matrix partial;
      partial.columnsCount = 3;
      partial.data.push_back(a.data[4] * a.data[8] - a.data[5] * a.data[7]);
      partial.data.push_back(-(a.data[3] * a.data[8] - a.data[5] * a.data[6]));
      partial.data.push_back(a.data[3] * a.data[7] - a.data[4] * a.data[6]);
      partial.data.push_back(-(a.data[1] * a.data[8] - a.data[2] * a.data[7]));
      partial.data.push_back(a.data[0] * a.data[8] - a.data[2] * a.data[6]);
      partial.data.push_back(-(a.data[0] * a.data[7] - a.data[1] * a.data[6]));
      partial.data.push_back(a.data[1] * a.data[5] - a.data[2] * a.data[4]);
      partial.data.push_back(-(a.data[0] * a.data[5] - a.data[2] * a.data[3]));
      partial.data.push_back(a.data[0] * a.data[4] - a.data[1] * a.data[3]);
      return (1/determinant) * (!partial);
    } else {
      throw std::invalid_argument("Matrix cannot be inversed - determinant equals 0"); 
    }
  } else {
    throw std::invalid_argument("Matrix cannot be inversed - only 2x2 and 3x3 matrixes are supported"); 
  }
}

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
          double part = (getElement(i, j, matrix) * std::pow(-1, i+1 + j+1) * matrixDeterminant(minor(matrix, i, j)));
        sum = sum + part; 
    }
    return sum;
  }
}

double getElement(int i, int j, Matrix matrix){
  int index = ((j * matrix.columnsCount) + i);
  return matrix.data[index];
};

Matrix doubleToMatrix(double number) {
  Matrix returned;
  returned.columnsCount = 1;
  returned.data[0] = number;
  return returned;
}
