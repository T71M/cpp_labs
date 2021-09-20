//
//  main.cpp
//  ex_3
//
//  Created by 71M on 01.09.2021.
//

#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <random>
#include <cmath>
#include <math.h>

char* my_strchr(char* s, int c) {
    char marker = c + '0';
    char* temp = s;
    char* answer;
    while (true) {
        if (*temp == marker) {
            answer = temp;
            break;
        }
        temp++;
    }
    //++answer = "\0";
    return answer;
}


int main() {
    setlocale(LC_ALL, "rus");

    char marker;
    char string[100];
   printf( "ведите строку:");
    fgets(string, 100,stdin);
    
    printf("что нужно найти: ");
    scanf("%c", &marker);
    int c = marker - '0';
    char* solution = my_strchr(string, c);
    printf("%s", solution);






}
