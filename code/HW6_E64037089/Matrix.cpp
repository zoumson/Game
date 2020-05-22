//  Using Xcode compiler
//  Matrix.cpp
//  Matrix
//
//  Created by ZOUMA Adama on 3/31/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Matrix::count = 0;// here we haven't create any matrix object yet

void Matrix::setUp(int r, int c){
    
    
    row = r;
    col = c;
    data = new double*[row];
    for(int i = 0; i < row; ++i)
        data[i] = new double [col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = 0;
    count++;// add one for each creation  of oject
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
    count--;// substract one for each replacement or new assignment of object
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

 ostream& operator<< (ostream &stream, const Matrix &matrix)// matrix output
{
    
    
    for (int r = 0; r < matrix.row; r++)
    {
        
        for (int c = 0; c < matrix.col; c++)
        {
            stream << setw(5)<< matrix.data[r][c];
        }
        stream << endl;
    }
    return stream;
}
istream& operator>> (istream &stream, const Matrix &matrix )// matrix input

{
    
    
    for (int i = 0; i < matrix.row; i++)
        
    {
        
        for (int j = 0; j < matrix.col; j++)
            
        {
            stream >> matrix.data[i][j];
        
            }
    }
    return stream;
}

bool Matrix::operator==(const Matrix & m)// test if two matrices are equal
{
    
    bool a = true;
    
    for(int i = 0; i < m.row ; i++){
        for(int j = 0; j < m.col ; j++){
            if (this->data[i][j] != m.data[i][j]) {a = false; break;}
        }
        
    }
    
    return this->row == m.row && this->col == m.col && a;
   
    
}


Matrix Matrix::operator+(const Matrix &m)// matrix + matrix
{
    
    Matrix result(row, col);
    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
            result.data[i][j] = this->data[i][j] + m.data[i][j];
    return result;
}
Matrix Matrix::operator+(const double m)// matrix + double
{
    
    Matrix result(row, col);
    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
            result.data[i][j] = this->data[i][j] + m;
    return result;;
    
}

Matrix Matrix::operator=(const Matrix &m)// assignment operator
{
    row = m.row;
    col = m.col;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
            this->data[i][j]= m.data[i][j];
    }
    
    return *this;
}

Matrix Matrix::operator+=(const Matrix &m)// += operator
{
    

    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
            this->data[i][j] += m.data[i][j];
    return*this ;
}

Matrix Matrix::operator++(const int m )//increementation ++ operator
{
    for(int i = 0; i< row; i++)
        for(int j = 0; j < col; j++)
            this->data[i][j] ++ ;
    return*this ;
}

Matrix Matrix::operator*(const Matrix &m)// multiplication operator
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




int Matrix::getCount(){// get number of matrix object

    return count;

}

Matrix Matrix:: operator()()//matrix transpose operator
{
    
    Matrix result(col, row);
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            result.data[j][i] = data[i][j];
    return result;
}










