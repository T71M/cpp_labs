//
//  Matrix.cpp
//  lab_2
//
//  Created by 71M on 23.08.2021.
//

#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix:: Matrix(int n, int m){
    matrix = new double* [n];
    for (int i = 0;  i < n; i++) {
        matrix[i] = new double[m];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = 0;
        }
    }
    this -> n = n;
    this -> m = m;
}
Matrix:: Matrix(double** matrix) {
    n = 5;
    m = 5;
   this -> matrix = new double*[5];
    for(int i = 0 ; i < 5; i++){
      this ->  matrix[i] = new double[5];
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            this -> matrix[i][j] = matrix[i][j];
        }
    }
}
void Matrix:: print(){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}
void Matrix:: setAt(int i, int j, double val){
    matrix[i][j] = val;
}

double Matrix:: at(int i, int j) const{
    return matrix[i][j];
}
int Matrix::getLengthX(){
    return n;
}
int Matrix:: getLengthY(){
    return m;
}
Matrix& Matrix:: operator++(){
// Matrix temp = *this;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j]++;
        }
    }
    return *this;
}
Matrix& Matrix:: operator--(){
//    Matrix temp = *this;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j]--;
        }
    }
    return *this;
}
Matrix& Matrix:: operator++(int n){
//    Matrix temp = *this;
    for (int i = 0; i < this -> n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j]++;
        }
    }
    return *this;
}
Matrix& Matrix:: operator--(int n){
//    Matrix temp = *this;
    for (int i = 0; i < this-> n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j]--;
        }
    }
    return *this;
}

Matrix:: ~Matrix(){
    for(int i = 0; i < n; i++){
        delete []matrix[i];
    }
    delete[] matrix;
}
