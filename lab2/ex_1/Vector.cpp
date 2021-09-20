//
//  main.cpp
//  lab_2
//
//  Created by 71M on 23.08.2021.
//
#include "Vector.h"
#include <iostream>
#include <cmath>

// для функции sin
#define PI 3.14159265
using namespace std;



Vector :: Vector(int n){
    vector = new double[n];
    for (int i = 0; i < n; i++) {
         vector[i] = i * ((PI * i)/ 25);
    }
    length = n;
}
void Vector:: print(){
    for (int i = 0; i < length; i++) {
        cout << this -> vector[i] << " ";
    }
}

Vector& Vector:: operator++(){
    Vector temp = *this;
    for(int i = 0; i < length; i++){
        this -> vector[i]++;
    }
    return temp;
}
Vector& Vector:: operator--(){
    Vector temp = *this;
    for(int i = 0; i < length; i++){
        this -> vector[i]--;
    }
    return temp;
}
Vector& Vector:: operator++(int n){
    
    Vector temp = *this;
    for(int i = 0; i < length; i++){
        this -> vector[i]++;
    }
    return temp;
}
Vector& Vector:: operator--(int n){
    Vector temp = *this;
    for(int i = 0; i < length; i++){
        this -> vector[i]--;
    }
    return temp;
}

double Vector:: operator [](int n){
    return vector[n];  
}

int Vector:: getLength(){
    return length;
}

Vector :: ~Vector(){
    if(vector == nullptr) return;
    delete[] vector;
    length = 0;
}
double** Vector:: transform() {
    int count = 0;
    double sum = 0;
    double** matrix = new double*[5];
    for(int i = 0; i < 5; i++){
        matrix[i] = new double[5];
    }
    
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            matrix[i][j] = vector[count];
                sum += vector[count];
                count++;
                matrix[i][0] =  sum;
        }
        sum = 0;
    }
    return matrix;
}
