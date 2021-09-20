//
//  Student.hpp
//  lab_2_3
//
//  Created by 71M on 24.08.2021.
//

#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Student{
public:
    Student();
    Student(string name, string gender, string birthday, string dateOfEntrance, int numberOfcard, int marks[]);
    
    void print();
    void setName(string name);
    void setGender(string gender);
    void setBirthday(string birthday);
    void setDateOfEntrance(string dateOfEntrance);
    void setnNumberOfCard(int numberOfCard);
    void setMarks(int* marks);
    void calculateAverageMark(int marks[]);
    void serialize();
    void serialize(const string& filename);
    void deserialize();
    void deserialize(const string& filename);
    
    int getAverageMark();
private:
    static int count;
    int rowNumber;
    string scholarship();
    string name;
    string gender;
    string birthday;
    string dateOfEntrance;
    int numberOfCard;
    int marks[4];
    int averageMark;
};
