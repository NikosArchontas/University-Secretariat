#include "Course.h"
#include <string>
#include <iostream>

Course::Course() {
	std::cout << "Set Course's name"<<std::endl;
	std::cin >> title;
	std::cout << "Press 1 if the course is mandatory" << std::endl;
	std::cin >> mandatory;
	std::cout << "Set Course's ECTS" << std::endl;
	std::cin >> ects;
	std::cout << "Press 0 for winter semester 1 for spring seme ster" << std::endl;
	std::cin >> semester;
}

void Course::ChangeSemester(Course* course) {
	if (course->semester == 0)
		course->semester = 0;
	else
		course->semester = 1;
}

void Course::AssingProffesor(Secretary* school){
	int i;
	std::string fname, lname;
	std::cout << "Assining Professor to " << title << std::endl;
	std::cout << "Set Professor First Name"<< std::endl;
	std::cin >> fname;
	std::cout << "Set Professor Last Name" << std::endl;
	std::cin >> lname;
	i = school->FindProfessor(fname, lname);
	if (i > -1) {
		teachers.push_back(school->teachers[i]);
		school->teachers[i]->courses.push_back(this);
	}
	else
		std::cout <<"Teacher Not Found" << std::endl;
}

void Course::PrintAll() {
	std::cout << std::endl << title << std::endl;
	std::cout << "ECTS:" << ects << std::endl;
	std::cout << "Semester: " << semester << std::endl;
	std::cout << "Mandatory: " << mandatory << std::endl;
	std::cout << "Teachers:";
	for (Professor* teacher : teachers) {
		std::cout << teacher->first_name << " " << teacher->last_name << '\t';
	}
	std::cout << "Students: ";
	for (Student* student : students) {
		std::cout << student->first_name << " " << student->last_name << '\t';
	}
	std::cout << std::endl ;
}

void Course::Grade() {
	
	for (Student* student : students) {
		student->Grade(title);
		break;
	}
}

bool Course::MandatoryCheck(Student* student) {
	if (mandatory == 1) {
		int count = 0;
		for (Course* course : student->courses) {
			if (course->title == title) {
				if (student->grades[count]>=5) {
					return 1;
				}
			}
		}
	}
	return 0;
}

std::ostream& operator<<(std::ostream& print, Course& course) {
	print << course.title << '\t' << "Professor(s):" << std::endl;
	for (Professor* teachers : course.teachers) {
		print << '\t' << *teachers;													//Ektypwsh olwn ton onomatwn
	}
	return print;
}

