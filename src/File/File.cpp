#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "File.hpp"
#include "../Matrix/Matrix.hpp"

File::File(std::string filename) {
    File::filename = filename;
    File::read();
}
File::File(Matrix matrix) {
    File::filename = "out.txt";
    File::matrix = matrix;
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
        return true;
    }
    return false;
}

bool File::save() {
    std::ofstream outfile (File::filename);
    outfile << File::matrix << std::endl;
    outfile.close();
}

int File::getColumnsCount() {
    return File::columnsCount;
}
