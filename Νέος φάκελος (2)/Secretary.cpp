#include "Secretary.h"
#include <iostream>
//#include <vector>
//#include <string>

Secretary::Secretary() {
	std::cout << "Shcool Created" << std::endl;
}
Secretary::~Secretary() {													//A2) 1-> Destractor
	for (int i = 0; i < teachers.size(); i++) {
		delete teachers[i];
	}
	teachers.clear();
	for (int i = 0; i < students.size(); i++) {
		delete students[i];
	}
	students.clear();
	
	for (int i = 0; i < courses.size(); i++) {
		delete courses[i];
	}
	courses.clear();
	
}

int Secretary::FindProfessor() {												//A2) 4-> Anazhthsh atomou. Epistrefei tou atomou thesi sto vector
	std::string fname, lname;
	std::cout << "Looking For" << std::endl;
	std::cout << "First name:" << std::endl;
	std::cin >> fname;
	std::cout << "Last name:" << std::endl;
	std::cin >> lname;

	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i]->first_name == fname && teachers[i]->last_name == lname) {
			std::cout << "There is a Professor in th School with that name" << std::endl;
			return i;														//An Yparxei
		}
	}
	std::cout << "The is no "<< fname<<" "<<lname<< " in the school !" << std::endl;																// An den Yparxei
	return - 1;
}
int Secretary::FindProfessor(std::string fname, std::string lname) {												//A2) 4-> Anazhthsh atomou. Epistrefei tou atomou thesi sto vector
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i]->first_name == fname && teachers[i]->last_name == lname) {
			return i;														//An Yparxei
		}
	}
	std::cout << "The is no " << fname << " " << lname << " in the school !" << std::endl;																// An den Yparxei
	return -1;
}

int Secretary::FindStudent(){
	std::string fname, lname;
	std::cout << "Looking For" << std::endl;
	std::cout << "First name:" << std::endl;
	std::cin >> fname;
	std::cout << "Last name:" << std::endl;
	std::cin >> lname;

	for (int i = 0; i<students.size(); i++) {
		if (students[i]->first_name == fname && students[i]->last_name == lname) {
			return i;														//An Yparxei
		}
	}
	std::cout << "The is no " << fname << " " << lname << " in the school !" << std::endl;
	return -1;
}
int Secretary::FindStudent(std::string fname,std::string lname) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->first_name == fname && students[i]->last_name == lname) {
			return i;														//An Yparxei
		}
	}
	std::cout << "The is no " << fname << " " << lname << " in the school !" << std::endl;
	return -1;
}

int Secretary::FindCourse() {
	std::string name;
	std::cout << "Looking For" << std::endl;
	std::cout << "Course's name:" << std::endl;
	std::cin >> name;
	for (int i = 0; i < courses.size(); i++) {
		if (courses[i]->title == name) {
			return i;														//An Yparxei
		}
	}
	std::cout << "The Course " << name << " doesn't exist in the school!" << std::endl;
	return -1;
}
int Secretary::FindCourse(std::string name) {
	for (int i = 0; i < courses.size(); i++) {
		if (courses[i]->title == name) {
			return i;														//An Yparxei
		}
	}
	std::cout << "The Course " << name << " doesn't exist in the school!" << std::endl;
	return -1;
}

void Secretary::operator+=(Person* person) {
	std::cout << "Invalid choice" << std::endl;
	if(person->type==1)
		students.push_back((Student*)person);
	else
		teachers.push_back((Professor*)person);
}
void Secretary::operator+=(Professor* professor) {
		teachers.push_back(professor);
}
void Secretary::operator+=(Student* student) {
	students.push_back(student);
}
void Secretary::operator+=(Course* course){
	courses.push_back(course);
}



std::ostream& operator<<(std::ostream& print, Secretary& secratary) {					//A2) 3-> yperfortosi telesti eksodou gia na perilmvanei typo Secretary
	print<< std::endl << "PROFESSORS LIST:"<<std::endl;
	for (Professor* teacher : secratary.teachers) {
		print << *teacher ;													//Ektypwsh olwn ton onomatwn
	}
	print << std::endl << "STUDENTS LIST:" << std::endl;
	for (Student* student : secratary.students) {
		print << *student ;													//Ektypwsh olwn ton onomatwn
	}
	print << std::endl << "COURSES LIST:" << std::endl;
	for (Course* course : secratary.courses) {
		print << *course;
	}
	print << std::endl;
	return print;
}
std::istream& operator>>(std::istream& data, Secretary& secretary)
{
	Person* person;
	person = new (Person);
	data >> *person;													
	secretary += person;
	return data;
}

