#pragma once
#include "Person.h"
#include "Course.h"
#include <vector>

class Professor:public Person{
	friend class Course;
	std::vector <Course*> courses;
public:
	Professor();
	Professor(std::string fname, std::string lname);
	void Garde();
	void GetCourse(Course* course);
	void PrintAll();
	int FindProfessor(std::string fname, std::string lname);


};


