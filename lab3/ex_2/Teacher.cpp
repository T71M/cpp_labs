//
//  Teacher.cpp
//  ex_2
//
//  Created by 71M on 01.09.2021.
//

#include "Teacher.hpp"


Teacher:: Teacher(){}

Teacher:: Teacher(string name, string gender, string birthday, double workExperience, string dateWorkBegin, string post, string academicDegree,string academicTitle) : Person(name, gender, birthday), workExperience(workExperience), dateWorkBegin(dateWorkBegin), post(post), academicDegree(academicDegree), academicTitle(academicTitle){}

void Teacher:: setWorkExperience(double workExperience){
    this-> workExperience = workExperience;
}
void Teacher:: setDateWorkBegin(string dateWorkBegin){
    this-> dateWorkBegin = dateWorkBegin;
}
void Teacher:: setPost(string post){
    this-> post = post;
}
void Teacher:: setAcademicDegree(string academicDegree){
    this-> academicDegree = academicDegree;
}
void Teacher:: setAcademicTitle(string academicTitle){
    this-> academicTitle = academicTitle;
}

double Teacher:: calculate() const {
    
    double sum = 5000;
    if (academicDegree == "CandidateSciences")  sum += 700;
    else if(academicDegree == "DoctorScience")  sum += 1200;
    if((int)workExperience % 5 == 0) sum += (workExperience / 5) * 700;
    if (academicTitle == "Professor") sum += 3500;
    else if (academicTitle == "Docent") sum += 2200;
    
    return sum;
}
void Teacher:: print() const {
    
    cout << "Teacher: " << Person:: name << endl << "gender: "  << Person:: gender << endl << "birtday: " << Person:: birthday << endl << "work Experience: " << workExperience << endl << "date Work Begin: " << dateWorkBegin << endl << "Post: " << post << endl << "academic Degree:" << academicDegree << endl << "academic Title: " << academicTitle << endl << "Зарплата: " << calculate() << endl << endl;
}
