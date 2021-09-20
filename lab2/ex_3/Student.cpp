//
//  Student.cpp
//  lab_2_3
//
//  Created by 71M on 24.08.2021.
//
#include "Student.hpp"
#include <iostream>
#include <fstream>
using namespace std;

 int Student:: count = 0;
Student :: Student(string name, string gender, string birthday, string dateOfEntrance, int numberOfcard, int* marks): name(name), gender(gender), birthday(birthday), dateOfEntrance(dateOfEntrance), numberOfCard(numberOfcard){
    for(int i = 0; i < 4; i++){
        this-> marks[i] = *marks++;
    }
    calculateAverageMark(this -> marks);
    count++;
    rowNumber = count;
}
Student :: Student(){
    count++;
    rowNumber = count;
}

void Student:: setName(string name){
    this-> name = name;
}
void Student:: setGender(string gender){
    this -> gender = gender;
}
void Student:: print(){
    cout << name << " " << birthday << " " << gender << " " << dateOfEntrance << " " << numberOfCard << " " << averageMark << scholarship() << endl;
}
void Student:: setBirthday(string birthday){
    this -> birthday = birthday;
}
void Student:: setDateOfEntrance(string dateOfEntrance){
    this -> dateOfEntrance = dateOfEntrance;
}
void Student:: setnNumberOfCard(int numberOfCard){
    this -> numberOfCard = numberOfCard;
}
string Student:: scholarship(){
    if(averageMark < 4) return "- остался без стипендии";
    else return "- стипендия)";
}
void Student:: setMarks(int* marks){
    int i;
    int sum = 0;
    for(i = 0; i < 4; i++){
        this -> marks[i] = *marks;
        sum += *marks++;
    }
    this -> averageMark = sum / i;
}
int Student:: getAverageMark(){
    return averageMark;
}
void Student:: serialize(){
    ofstream fout;
    if(rowNumber == 1){
        fout.open("output.txt",  fstream::out );
        fout << name << endl << gender << endl << birthday << endl << dateOfEntrance << endl << numberOfCard  << endl << averageMark;
        fout.close();
    }else {
        fout.open("output.txt",  ios_base :: app );
        fout << endl;
        fout << name << endl << gender << endl << birthday << endl << dateOfEntrance << endl << numberOfCard  << endl << averageMark;
        fout.close();
    }
    
}

void Student:: serialize(const string& filename){
    ofstream fout;
    fout.open(filename + ".txt",  fstream:: out );
    fout << name << endl << gender << endl << birthday << endl << dateOfEntrance << endl << numberOfCard  << endl << averageMark;
    fout.close();

}
void Student:: deserialize(){
    ifstream fin;
    fin.open("output.txt", fstream :: in);
    int cnt = 0;
    char name[20];
    char gender[10];
    char birthday[50];
    char dateOfEntrance[50];
    int numberOfCard;
    int averageMark;
    if(rowNumber == 1){
        fin.getline(name,50);
        fin.getline(gender,10);
        fin.getline(birthday,50);
        fin.getline(dateOfEntrance,50);
        fin >> numberOfCard;
        fin >> averageMark;
        
    }else{
        while(cnt < rowNumber){
            fin.getline(name,50);
            fin.getline(gender,10);
            fin.getline(birthday,50);
            fin.getline(dateOfEntrance,50);
            fin >> numberOfCard;
            fin >> averageMark;
            cnt++;
        }
    }
    this-> name = name;
    this-> birthday= birthday;
    this-> gender = gender;
    this->dateOfEntrance = dateOfEntrance;
    this -> numberOfCard = numberOfCard;
    this -> averageMark = averageMark  ;
    
}

void Student:: deserialize(const string& filename){
    ifstream fin;
    fin.open(filename + ".txt", fstream :: in);
    char name[20];
    char gender[10];
    char birthday[50];
    char dateOfEntrance[50];
    int numberOfCard;
    int averageMark;

    fin.getline(name,50);
    fin.getline(gender,10);
    fin.getline(birthday,50);
    fin.getline(dateOfEntrance,50);
    fin >> numberOfCard;
    fin >> averageMark;
        
    this-> name = name;
    this-> birthday= birthday;
    this-> gender = gender;
    this->dateOfEntrance = dateOfEntrance;
    this -> numberOfCard = numberOfCard;
    this -> averageMark = averageMark  ;
    
}


void Student:: calculateAverageMark(int* marks){
    int i;
    int sum = 0;
    for(i = 0; i < 4; i++){
        this -> marks[i] = *marks;
        sum += *marks++;
    }
    this -> averageMark = sum / i;
}


