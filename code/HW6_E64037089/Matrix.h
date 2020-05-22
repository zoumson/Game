// Using Xcode compiler
//  Matrix.h
//  Matrix
//
//  Created by ZOUMA Adama on 4/4/18.
//  Copyright © 2018 ZOUMA Adama. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h
#include <iostream>
#include <iomanip>
using namespace std;


class Matrix {
private:
    
    /* private data*/
    
    double ** data;
    int row;
    int col;
    void setUp(int, int);
   
public:
    
    /* member functions*/
    
    
    Matrix();// default constructor
    Matrix(int, int);//constructor with input r row and c column
    Matrix(int, int, double [], int);//populate matrix with a one dimensional array
    Matrix(const Matrix &);//copy constructor
    ~Matrix();// destructor
    void setData(int, int, double);//set matrix cell(r,c) to a double  data value
    int getRow() const;//get matrix row
    int getCol() const;//get matrix column
    double getData(int, int) const;//get matrix cell (r,c) data value
    Matrix add(const Matrix &);//add an incoming matrix with actual class matrix
    Matrix multiply(const Matrix &);//multiply an incoming matrix with actual class matrix
    Matrix transpose();//return current class matrix transpose
    static int getCount();// get the number of objects now
    void displayData() {
        for (int i = 0;i<row; i++) {
            for (int j = 0;j<col; j++) {
                cout<<data[i][j]<<"\t";
            }
            cout<<""<<endl;
        }
    }
    
    
    /*static dtata*/
     static int count;// store number of matrix objects
    
    
    /* operator overloading */
    
    
    friend ostream& operator<< (ostream &stream, const Matrix &matrix);// Matrix output
    friend istream& operator>> (istream &stream,const Matrix &matrix);// Matrix input
    Matrix operator=(const Matrix &m);// assignment operator
    Matrix operator+(const Matrix &m);// Matrix + Matrix
    Matrix operator+(const double m);// Matrix + double, all values plus the double value
    Matrix operator+=(const Matrix &m);// m1 = m1 + m2
    Matrix operator++(const int m);//m5++, all values plus 1.0
    Matrix operator*(const Matrix &m );// Matrix * Matrix
    Matrix operator()();// implement the transpose function, return the transpose of itself
    bool operator==(const Matrix & m);// test if two matrices contain the same values
};










#endif /* Matrix_h */

