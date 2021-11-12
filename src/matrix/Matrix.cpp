#include "Matrix.hpp"

MatrixCalculator::MatrixCalculator(Matrix matrix) {
  MatrixCalculator::matrix = matrix;
}
Matrix MatrixCalculator::transpose() {
  Matrix returned;
  int size = MatrixCalculator::matrix.data.size();
  returned.columnsCount = size/matrix.columnsCount;

  for (int i = 0; i < MatrixCalculator::matrix.columnsCount; i++){
    for (int j = 0; j < size; j+=MatrixCalculator::matrix.columnsCount ){
      returned.data.push_back(MatrixCalculator::matrix.data[i+j]);
    }
  }
   return returned;
};
