#pragma once
#include <vector>
#include <iostream>

typedef struct Matrix {
	std::vector<double> data;
    int columnsCount;
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
//transposition
Matrix operator !( const Matrix & a);
//inversion
Matrix operator ~( const Matrix & a);


Matrix minor(Matrix matrix, int i, int j);
double matrixDeterminant(Matrix matrix);
double getElement(int i, int j, Matrix matrix);
