#include <iostream>
#include "Person.h"

Person::Person(std::string first, std::string last, int num){
	this->first = first;
	this->last = last;
	this->idnum = num;
}

std::string Person::get_name(){
	return last+", "+first;
}

int Person::get_id(){
	return idnum;

}


std::ostream& operator<<(std::ostream& os, Person& person) {
    os << "Name: " << person.get_name() << ", ID: " << person.get_id();
    return os;
}



