#include <iostream>
#include <cmath>
#include <string>
#include "File/File.hpp"
#include "Matrix/Matrix.hpp"

int main(int argc, char* argv[]){ 
    std::string firstMatrixFileName = argv[1];
    std::string secondMatrixFileName = argv[2];
    File *firstFile = new File(firstMatrixFileName);
    File *secondFile = new File(secondMatrixFileName);
    Matrix firstMatrix = firstFile->getData();
    Matrix secondMatrix = secondFile->getData();

    // std::cout << firstMatrix.getElement(0, 1) << std::endl;
    std::cout << matrixDeterminant(firstMatrix) << std::endl;
    // std::cout << firstMatrix + secondMatrix;
    // std::cout << firstMatrix - secondMatrix;
    // std::cout << 2 * firstMatrix;
    // std::cout << !firstMatrix;

    return 0;
}
