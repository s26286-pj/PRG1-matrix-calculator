#include <iostream>
#include <cmath>
#include <string>
#include "File/File.hpp"
#include "Matrix/Matrix.hpp"

int main(int argc, char* argv[]){ 
    std::string firstMatrixFileName = argv[1];
    std::string secondMatrixFileName = argv[2];
    File *firstFile = new File(firstMatrixFileName);
    Matrix firstMatrix = firstFile->getData();
    firstMatrix.print();

    MatrixCalculator *firstMatrixCalc = new MatrixCalculator(firstMatrix);
    Matrix transposedMatrix = firstMatrixCalc->transpose();
    
    transposedMatrix.print();

    return 0;
}
