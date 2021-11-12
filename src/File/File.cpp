#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "File.hpp"
#include "../matrix/Matrix.hpp"

File::File(std::string filename) {
    File::filename = filename;
    File::read();
}

Matrix File::getData() {
    return File::matrix;
}

bool File::read(){
    int row = 0;
    int firstLineNumbersCount = 0;
    bool firstLine = true;
    Matrix matrix;
    std::ifstream file;
    file.open( File::filename );

    if(file.good()) {
        std::string line;
        for( std::string line; getline( file, line ); ){
            std::stringstream lineString;
            lineString << line;
            while( !lineString.eof() ) {
                double number;
                if (firstLine) {
                    firstLineNumbersCount++;
                }
                lineString >> number;
                File::matrix.data.push_back(number);
            }
            firstLine = false;
            File::matrix.columnsCount = firstLineNumbersCount;
        }
    }
}

int File::getColumnsCount() {
    return File::columnsCount;
}
