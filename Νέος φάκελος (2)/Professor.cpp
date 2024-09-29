#include "Professor.h"
#include <string>
#include<iostream>

Professor::Professor() {
	std::string fname, lname;
	std::cout << "Set Professor's first name" << std::endl;
	std::cin >> fname;
	std::cout << "Set Professor's last name" << std::endl;
	std::cin >> lname;
	first_name = fname;
	last_name = lname;
	type = 0;
}

Professor::Professor(std::string fname, std::string lname) {
	std::cout << "Set Professor's first name" << std::endl;
	std::cin >> fname;
	std::cout << "Set Professor's last name" << std::endl;
	std::cin >> lname;
	first_name = fname;
	last_name = lname;
	type = 0;
}

void  Professor::Garde() {
	
	for (Course* course : courses) {
		course->Grade();
	}                           
}

void Professor::GetCourse(Course* course) {
	courses.push_back(course);
}

void Professor::PrintAll() {
	std::cout << std::endl << "Proffessor: " << first_name << " " << last_name << std::endl;
	std::cout << "Classes: ";
	for (Course* course : courses) {
		std::cout << course->title << " " ;
	}
	std::cout << std::endl;
}