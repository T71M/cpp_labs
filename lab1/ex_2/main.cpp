//
//  main.cpp
//  ex_2
//
//  Created by 71M on 01.09.2021.
//

#include <iostream>
#include <iomanip>
using namespace std;
#define _USE_MATH_DEFINES
#include <random>
#include <cmath>
#include <math.h>

double* initialization() {
    double* array = new double[25];
    int count = 1;

    while (count < 25) {
        array[count - 1] = count * sin((count * M_PI) / 25);
        count++;
    }

    return array;
}

void printSourceArray(double* array) {
    cout << "source array: " << endl;
    for (int i = 0; i < 25; i++) cout << array[i] << " ";
    cout << endl;
}

double** transformation(double* array);

void printAnswerArray(double** answer){
    cout << "answer array: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(20) << answer[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteArrays(double* array, double** answer) {
    delete[] array;
    for (int i = 0; i < 5; i++) {
        delete[] answer[i];
    }
    delete[] answer;
}

int main() {
    cout.precision(10);

    double* array = initialization();
    printSourceArray(array);

    double** answer = transformation(array);
    printAnswerArray(answer);

    deleteArrays(array, answer);
    return 0;
}

double** transformation(double* array) {
    int count = 0;

    double** answer = new double*[5];
    for (int i = 0; i < 5; i++) answer[i] = new double[5];
    double sum = 0;


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) answer[i][j] = 0;
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j != 0) {
                answer[i][j] = array[count++];
                sum += answer[i][j];
            }
            answer[i][0] = sum;
        }
        sum = 0;
    }
    return answer;
}
