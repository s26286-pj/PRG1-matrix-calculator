#include <iostream>
#include <cmath>
#include <string>
#include "File/File.hpp"

int main(int argc, char* argv[])
{ 
    for (int i = 0; i < argc; i++)
    {
         std::cout << argv[i] << std::endl;
    }
    std::string firstMatrixFileName = argv[1];
    std::string secondMatrixFileName = argv[2];
    File *firstFile = new File(firstMatrixFileName);
    std::vector<double> data = firstFile->getData();
    for (double i: data){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Liczba kolumn: " << firstFile->getColumnsCount() << std::endl;
    std::cout << "Liczba wierszy: " << data.size() / firstFile->getColumnsCount() << std::endl;

    return 0;
}
