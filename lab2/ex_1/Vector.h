#pragma once

class Vector{
public:
    Vector(int n);
    
    void print();
    Vector& operator ++();
    Vector& operator --();
    Vector& operator ++(int n);
    Vector& operator --(int n);
    double operator [](int n);
    double** transform();
    int getLength();
    
    ~Vector();
    
private:
    double* vector = nullptr;
    int length;
};
