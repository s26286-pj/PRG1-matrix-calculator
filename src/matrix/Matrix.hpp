#pragma once
#include <vector>
#include <iostream>

typedef struct Matrix {
	std::vector<double> data;
    int columnsCount;
} Matrix;

std::ostream & operator <<( std::ostream & s, const Matrix & a );
Matrix operator +( const Matrix & a, const Matrix & b );
Matrix operator -( const Matrix & a, const Matrix & b );
Matrix operator *( const double & a, const Matrix & b );
Matrix operator *( const Matrix & a, const Matrix & b );
Matrix operator !( const Matrix & a);
