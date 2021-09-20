//
//  main.cpp
//  lab_2_2
//
//  Created by 71M on 24.08.2021.
//


#include <iostream>
#include "Fraction.hpp"
using namespace std;
int main() {
    
    Fraction f1(4,5);
    Fraction f2(20,40);
    Fraction f3(10,2);
    
    cout << "f1: ";
    f1.print();
    
    cout << "f2: ";
    f2.print();
    
    cout << "f3: ";
    f3.print();
    
    cout << "f1 + f2: " << endl;
    f1 + f2;
    f1.print();
    
    cout << "f2 + f3: " << endl;
    f2 + f3;
    f2.print();
    
    cout << "f3 + f1: " << endl;
    f3 + f1;
    f3.print();
    
    cout << "f1 * f2: " << endl;
    f1 * f2;
    f1.print();
    
    cout << "f2 * f3: " << endl;
    f2 * f3;
    f1.print();
    
    cout << "f3 * f1: " << endl;
    f3 * f1;
    f3.print();
    
    double df;
    cout << "введите десятичную дробь, чтобы преобразовать ее в обычную: ";
    cin >> df;
    Fraction :: printAsFraction(df);
    
    cout << "прграмма примет десятичную дробь как строку, и преобразует ее в обычную: ";
    char* decimal_fraction = new char[20];
    cin >> decimal_fraction;
    
    Fraction :: printAsFraction(decimal_fraction);
   
}
