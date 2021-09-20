//
//  Fraction.cpp
//  lab_2_1
//
//  Created by 71M on 24.08.2021.
//

#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int Fraction:: counter = 0;

Fraction :: Fraction(int a, int b){
        this -> a = a;
        this -> b = b;
        counter++;
   
}
void Fraction :: operator+(Fraction &fraction){
    if(fraction.b == this-> b){
        this -> a +=  fraction.a;
    } else{
        this -> a = (this->a * fraction.b) + fraction.a * this->b;
        this -> b *= fraction.b;
    }
}
void Fraction:: operator -(Fraction &fraction){
    if(fraction.b == this-> b){
        this -> a -= fraction.a;
    }else {
        this -> a = (this->a * fraction.b) - fraction.a * this->b;
        this -> b *= fraction.b;
    }
}
void Fraction:: operator*(Fraction& fraction){
    this-> a *= fraction.a;
    this -> b *= fraction.b;
}
void Fraction:: operator/(Fraction &fraction){
    this -> a *= fraction.b;
    this -> b *= fraction.a;
}
int Fraction:: gcd(int a, int b){
    while (a != 0 && b != 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
void Fraction:: reduce(){
    int temp = gcd(a,b);
    this -> a /= temp;
    this-> b /= temp;
}

void Fraction:: print(){
    reduce();
    if(b != 1) a == b ? cout << 1 << endl : cout << a << "/" << b << endl;
    else cout << a << endl;
    
    
}
void Fraction:: printAsFraction(double decimal_fraction){
        while(decimal_fraction - (int)decimal_fraction != 0){
            decimal_fraction *= 10;
        }
        int temp = 10;
        while (decimal_fraction / temp > 1){
            temp *= 10;
        }
        cout << decimal_fraction << "/" << temp << endl;
}
void Fraction:: printAsFraction(char* decimal_fraction){
    int cnt = 0;
    char* temp = decimal_fraction;
    
    while(*decimal_fraction){
        decimal_fraction++;
        cnt++;
        if(*decimal_fraction == '.') break;
    }
    
    decimal_fraction++;
    char* a = new char[cnt];
    for(int i = 0; i < cnt; i++){
        a[i] = temp[i];
    }
    
    string s = a;
    int n = stoi(s);
    string ss = decimal_fraction;
    int length = ss.length();
    int m = stoi(ss);
    int drob = pow(10, length);
    cout << m + n * drob << "/" << drob << endl;
}
