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
using namespace std;


class Matrix {
private:
    double ** data;
    int row;
    int col;
    void setUp(int, int);
    
public:
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
    
    void displayData() {
        for (int i = 0;i<row; i++) {
            for (int j = 0;j<col; j++) {
                cout<<data[i][j]<<"\t";
            }
            cout<<""<<endl;
        }
    }
    
};


#endif /* Matrix_h */
