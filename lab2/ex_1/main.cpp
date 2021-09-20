//
//  main.cpp
//  lab_2
//
//  Created by 71M on 23.08.2021.
//



#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;





int main() {
    cout.precision(10);
    

    Vector* vector = new Vector(25);
    cout << endl;
   
    cout << "2d array: " << endl;
    
    Matrix matrix(vector -> transform());
    matrix.print();
    ++matrix;
    cout << endl;
   
    matrix.print();
    return 0;
}
