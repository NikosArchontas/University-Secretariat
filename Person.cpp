//Person.cpp file

#include "Person.h"
#include <iostream>
#include <string>

Person::Person(){
	count++;
}

Person::~Person() {
	
	count--;
}

Person::Person(std::string fname,std::string lname) {
	first_name = fname;
	last_name = lname;
	count++;
}

void Person::PrintCount() {
	std::cout << "The Current Number of Persons Is:" << count << std::endl;
}

void Person::PrintName() {													// Ektypwsh steixeiwn
	std::cout << first_name << " " << last_name << std::endl;
}

void Person::ChangePerson() {
	std::string fname, lname;
	std::cout << "enter new first name name" << std::endl;
	std::cin >> fname;
	first_name = fname;
	std::cout << "enter new last name name" << std::endl;
	std::cin >> lname;
	last_name = lname;
}

std::ostream& operator<<(std::ostream& print, Person& person) {
	print << person.first_name << "  " <<person.last_name << std::endl;
	
	return print;
}

std::istream& operator>>(std::istream& get, Person& person) {
	std::cout << "For Professor press 0" << std::endl;
	std::cout << "For Student press 1" << std::endl;
	get >> person.type;

	std::cout << "Set Persons First Name :" << std::endl;
	get >> person.first_name;
	std::cout << "Set Persons Last Name :" << std::endl;
	get >> person.last_name;


	return get;
}
