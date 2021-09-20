//
//  Matrix.hpp
//  lab_2
//
//  Created by 71M on 23.08.2021.
//

#pragma once

class Matrix {
public:
    Matrix(int n, int m);
    Matrix(double** matrix);
    void print();
    
    double at(int i, int j) const;
    
    void setAt(int i, int j, double val);
    Matrix& operator ++();
    Matrix& operator --();
    Matrix& operator ++(int n);
    Matrix& operator --(int n);
    
    int getLengthX();
    int getLengthY();
    
    ~Matrix();
    
private:
    double** matrix = nullptr;
    int n;
    int m;
};
