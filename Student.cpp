#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

Student::Student() {
	std::string fname, lname;
	std::cout << "Set Student's first name"<<std::endl;
	std::cin >> fname;
	std::cout << "Set Student's last name" << std::endl;
	std::cin >> lname;
	first_name = fname;
	last_name = lname;
	year = 0;
	ects_count = 0;
}

Student::~Student()
{
	grades.clear();
}

Student::Student(std::string fname, std::string lname) {
	first_name = fname;
	last_name = lname;
	year = 0;
}

void Student::AssingCourse(Secretary* school) {
	int i;
	std::string name;
	std::cout << "Choose Course" <<  std::endl;
	std::cin >> name;
	i = school->FindCourse(name);
	if (i > -1) {
		courses.push_back(school->courses[i]);
		grades.push_back(0);
		school->courses[i]->students.push_back(this);
	}
	else
		std::cout << "Course Not Found" << std::endl;
}

void  Student::Grade(std::string title) {
	int grade;
	for (int i = 0; i < courses.size();i++) {
		if (courses[i]->title == title) {
			std::cout << "Enter Grade for: " << first_name << " " << last_name;
			std::cout << "For the Subject: "<< title << std::endl;
			std::cin >> grade;
			grades[i] = grade;
			return;
		}
	}
}

void Student::PrintCourses() {
	std::cout<<first_name<< " "<< last_name<< " " << "Atents: ";
	for (Course* course: courses ) {
		std::cout << course->title << "" << std::endl;
	}
}

void Student::AddYear() {
	year++;
}

void Student::PrintAll() {
	int count=0;
	std::cout << std::endl << "Student: " << first_name << " " << last_name << std::endl;
	std::cout << "Year=" << year << std::endl;
	std::cout<< "Total of ECTS:"<<ects_count<<std::endl;
	std::cout << "Atents: ";
	for (Course* course : courses) {
		std::cout << course->title << " ";
		std::cout << "Grade:" << grades[count];
		count++;
	}
	std::cout << std::endl;
}

void Student::ECTS_Update() {
	int i =0 ;
	for (Course* course : courses) {
		if (grades[i] >= 5) {
			ects_count += course->ects;
		}
	}
}

