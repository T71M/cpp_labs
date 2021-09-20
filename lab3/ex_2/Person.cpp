//
//  Person.cpp
//  ex_2
//
//  Created by 71M on 01.09.2021.
//

#include "Person.hpp"

Person:: Person(string name, string gender, string birthday){
    this->name = name;
    this->gender = gender;
    this-> birthday = birthday;
}
Person:: Person(){
    name = "x";
    gender = "y";
    birthday = "z";
}

void Person :: setName(string name){
    this-> name = name;
}
void Person:: setGender(string gender) {
    this -> gender = gender;
}
void Person:: setBirthday(string birthday) {
    this -> birthday = birthday;
}
string Person:: getName() {
    return name;
}
string Person:: getGender() {
    return gender;
}
string Person:: getBirthday(){
    return birthday;
}
