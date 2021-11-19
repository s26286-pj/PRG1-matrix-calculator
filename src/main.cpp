#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <string.h>
#include "File/File.hpp"
#include "Matrix/Matrix.hpp"

bool is1ParametersOperation(std::string command) {
    if (command.compare("transpose") == 0) {
        return true;
    }
    if (command.compare("inverse") == 0) {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]){
    std::string command = argv[1];
    std::string firstMatrixFileName = argv[2];
    Matrix returned;

    bool saveToFile = strcmp(argv[argc-2], "-s") == 0;

    std::cout << saveToFile << std::endl; 

    try {
        if (!is1ParametersOperation(command)) {
            std::string secondMatrixFileName = argv[3];
            Matrix secondMatrix = File(secondMatrixFileName).read();
            if (command.compare("multiplyN") == 0) {
                std::string firstMatrixFileNameOrNumber = argv[2];
                double number = std::atof(firstMatrixFileNameOrNumber.c_str());
                returned = number * secondMatrix;
            } 

            Matrix firstMatrix = File(firstMatrixFileName).read();
            if (command.compare("multiply") == 0) {
                returned = firstMatrix * secondMatrix;
            } else if (command.compare("add") == 0) {
                returned = firstMatrix + secondMatrix;
            } else if (command.compare("subtract") == 0) {
                returned = firstMatrix - secondMatrix;
            }

        } else {
            Matrix firstMatrix = File(firstMatrixFileName).read();
            if (command.compare("transpose") == 0) {
                returned = !firstMatrix;
            } else if (command.compare("inverse") == 0) {
                returned = ~firstMatrix;
            } 
        }
        std::cout << returned << std::endl;
        if (saveToFile) {
            File(returned, argv[argc-1]).save();
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
