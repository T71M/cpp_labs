//
//  Fraction.hpp
//  lab_2_1
//
//  Created by 71M on 24.08.2021.
//

#pragma ones
#include <stdio.h>



class Fraction {
public:
    Fraction(int a, int b);
    void print();
    void operator +(Fraction& fraction);
    void operator -(Fraction& fraction);
    void operator *(Fraction& fraction);
    void operator /(Fraction& fraction);
   
    void reduce();
   
public:
    static int counter;
    static void printAsFraction(double decimal_fraction);
    static void printAsFraction(char* decimal_fraction);
    static int gcd(int a, int b);
    
private:
    int a;
    int b;
    

};

