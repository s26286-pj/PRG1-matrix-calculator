#pragma once
#include <vector>
#include <iostream>

typedef struct Matrix {
	std::vector<double> data;
    int columnsCount;
    void print(){
    	for (int i = 0; i < this->data.size(); i++){
    		std::cout << this->data[i] << "\t";
    		if (!((i+1) % this->columnsCount)) {
    			std::cout << std::endl;
    		}
    	}
    }
} Matrix;

class MatrixCalculator {
public:
	MatrixCalculator(struct Matrix matrix);
	Matrix transpose();

private:
	Matrix matrix;
};
