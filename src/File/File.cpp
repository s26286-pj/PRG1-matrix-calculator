#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "File.hpp"

File::File(std::string filename) {
    int row = 0;
    int firstLineNumbersCount = 0;
    bool firstLine = true;
    std::ifstream file;
    file.open( filename );

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
                File::data.push_back(number);
            }
            firstLine = false;
            File::columnsCount = firstLineNumbersCount;
        }
    }
}

std::vector<double> File::getData() {
    return File::data;
}

int File::getColumnsCount() {
    return File::columnsCount;
}
