//  Using Xcode compiler 
//  Matrix.cpp
//  Matrix
//
//  Created by ZOUMA Adama on 3/31/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "Matrix.h"
#include <iostream>
using namespace std;


void Matrix::setUp(int r, int c){
    row = r;
    col = c;
    data = new double*[row];
    for(int i = 0; i < row; ++i)
        data[i] = new double [col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = 0;
}

Matrix:: Matrix(){//default constructor
    
    setUp(2,2);

}

Matrix::Matrix(int r, int c){//constructor with input r row and c column
    
    setUp(r,c);
    
}

Matrix::Matrix(int r, int c, double a[], int size){//populate matrix with a one dimensional array

    setUp(r, c);
    int k = 0;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = a[k++];
}

Matrix::Matrix(const Matrix &m)//copy constructor
{
    setUp(m.row, m.col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = m.data[i][j];
    
}

Matrix::~Matrix()// destructor
{
    for(int i = 0; i < row; i++)
        delete[] data[i];
    delete[] data;
}
void Matrix::setData(int r , int c, double val) //set matrix cell(r,c) to a double  data value
{
    data[r][c] = val;
}

int Matrix::getRow() const//get matrix row
{
    return row;
}

int Matrix::getCol() const//get matrix column
{
    return col;
}

double Matrix::getData(int r , int c) const//get matrix cell (r,c) data value
{
    return data[r][c];
}

Matrix Matrix::add(const Matrix &m)//add an incoming matrix with actual class matrix
{
    Matrix result(row, col);
    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
            result.data[i][j] = data[i][j] + m.data[i][j];
    return result;
}

Matrix Matrix::multiply(const Matrix &m)//multiply an incoming matrix with actual class matrix
{
    Matrix result(row, m.col);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < m.col; j++)
        {
            for(int k = 0; k < col; k++)
                result.data[i][j] += data[i][k] * m.data[k][j];
        }
    }
    
    return result;
}

Matrix Matrix::transpose(){//return current class matrix transpose
    Matrix result(col, row);
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result.data[j][i] = data[i][j];
    return result;
}





