//
//  main.cpp
//  ex_2
//
//  Created by 71M on 01.09.2021.

//
//Вид выражения CustomExpression: result = x1 + x2/2 + x3/3 + x4/4 + ...
//Порядок создания и инициализации объектов подклассов: CustomExpressionEvaluator: 6 операндов, присвоить группой 5, 16, -3, 10, 12, 2. Subtractor: 4 операнда, присвоить группой 5.6,-2.1, 3.2, 1.5.
//Multiplier: 3 операнда, присвоить поэлементно 1.5, -8, 2.5.
//Метод shuffle() – поменять местами первый и последний операнды и изменить их знак. Метод shuffle(size_t i, size_t j) – поменять местами i-ый и j-ый операнды и изменить их знак.

#include <iostream>
#include "Student.hpp"
#include "Teacher.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    int timMarks[] = {5,5,5,4};
    int danyaMarks[] = {4,3,5,4};
    Person* ptrs[4];
    ptrs[0] = new Student("Timur", "M", "30.01.2003", "01.09.2020", 1111, timMarks);
    ptrs[1] = new Student("Danya", "M", "01.01.01", "01.09.2020", 22222, danyaMarks);
    ptrs[2] = new Teacher("Tim", "M", "30.01.2003", 5, "1.09.2020", "teacher", "DoctorScience", "Professor");
    ptrs[3] = new Teacher("Mihail", "M", "01.01.01", 10, "1.09.2020","teacher","CandidateSciences", "Docent");
    
//    academicTitle academicTitle = Proffesor;
//    academicDegree academicDegree = DoctorScience;

    
    for(int i = 0; i < 4; i++){
        Teacher* teacher = dynamic_cast<Teacher*>(ptrs[i]);
        if(teacher) teacher -> print();
        else {
            Student* student = dynamic_cast<Student*>(ptrs[i]);
            if (student) student -> print();
        }
    }
}
