#pragma once
#include <vector>
#include <iostream>

typedef struct Matrix {
	std::vector<double> data;
    int columnsCount;
    double getElement(int i, int j){
    	int index = ((j * columnsCount) + i);
    	return data[index];
    };
    void setElement(int i, int j, double value){
    	int index = ((j * columnsCount) + i);
    	data[index] = value;
    };
} Matrix;

std::ostream & operator <<( std::ostream & s, const Matrix & a );
Matrix operator +( const Matrix & a, const Matrix & b );
Matrix operator -( const Matrix & a, const Matrix & b );
Matrix operator *( const double & a, const Matrix & b );
Matrix operator *( const Matrix & a, const Matrix & b );
Matrix operator !( const Matrix & a);

double matrixDeterminant(Matrix matrix);
Matrix minor(Matrix matrix, int i, int j);
