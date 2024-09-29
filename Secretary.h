#pragma once
#include <vector>
#include "Person.h"
#include "Course.h"
#include "Professor.h"
#include "Student.h"



class Secretary
{
	friend class Professor;
	friend class Student;
	friend class Course;
public:
	
	std::vector<Professor*> teachers;
	std::vector<Student*> students;
	std::vector<Course*> courses;


	Secretary();
	~Secretary();


	int FindProfessor();
	int FindProfessor(std::string fname, std::string lname);
	
	int FindStudent();
	int FindStudent(std::string fname, std::string lname);
	
	int FindCourse();
	int FindCourse(std::string);


	void operator+=(Person* person);
	void operator+=(Professor* professor);
	void operator+=(Student* student);
	void operator+=(Course* course);

	

	friend std::ostream& operator<<(std::ostream& print, Secretary& secratary);
	friend std::istream& operator>>(std::istream& data, Secretary& secretary);
};


