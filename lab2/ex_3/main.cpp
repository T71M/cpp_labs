//
//  main.cpp
//  lab_2_3
//
//  Created by 71M on 24.08.2021.
//


#include <iostream>
using namespace std;
#include "Student.hpp"

void sesion(Student* array){
    int count = 0;
    srand(time(NULL));
    int marks[4];
    while(count < 3){
        for(int i = 0; i < 4; i++){
            marks[i] = rand()%5;
        }
        array[count].setMarks(marks);
        count++;
    }
}
void sortArray(Student* array)
{
    for(int i = 0; i < 3; i++){
        Student temp;
        for (int j = i + 1; j < 3; j++) {
            if(array[i].getAverageMark() < array[j].getAverageMark()) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    Student tim;
    int timMarks[] = {5,5,5,5};
    tim.setName("Timur");
    tim.setGender("M");
    tim.setBirthday("30.01.2003");
    tim.setDateOfEntrance("1.09.2020");
    tim.setnNumberOfCard(11111);
    tim.setMarks(timMarks);
    tim.serialize();
    tim.print();
    string filename;
    cout << "Назовите файл в который необходимо сохранить данные: ";
    cin >> filename;
    tim.serialize(filename);
    
    Student cehya;
    int cehyaMarks[] = {4,3,2,5,4};
    cehya.setName("Cehya");
    cehya.setGender("M");
    cehya.setBirthday("7.02.2004");
    cehya.setDateOfEntrance("1.09.2020");
    cehya.setnNumberOfCard(22222);
    cehya.setMarks(cehyaMarks);
    cehya.serialize();
    cehya.print();
    cout << "Назовите файл в который необходимо сохранить данные: ";
    cin >> filename;
    cehya.serialize(filename);
    
    Student danya;
    int danyaMarks[] = {3,4,2,5,4};
    danya.setName("Danya");
    danya.setGender("M");
    danya.setBirthday("30.11.2002");
    danya.setDateOfEntrance("1.09.2020");
    danya.setnNumberOfCard(3333);
    danya.setMarks(danyaMarks);
    danya.serialize();
    danya.print();
    cout << "Назовите файл в который необходимо сохранить данные: ";
    cin >> filename;
    danya.serialize(filename);
    
    Student* array = new Student[3];
    array[0] = tim;
    array[1] = cehya;
    array[2] = danya;
    
    sesion(array);
    sortArray(array);
    cout << "Студенты после сессии: " << endl;
    for(int i =0; i < 3; i++){
        array[i].print();
    }
    
    string filepath;
    cout << "Назовите файл с которого нужно считать данные: ";
    cin >> filepath;
    tim.deserialize(filepath);
    tim.print();
    
    cout << "Назовите файл с которого нужно считать данные: ";
    cin >> filepath;
    cehya.deserialize(filepath);
    cehya.print();
    
    cout << "Назовите файл с которого нужно считать данные: ";
    cin >> filepath;
    danya.deserialize(filepath);
    danya.print();
   
    delete[] array;
    
    
    
    
    
}
