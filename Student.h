#pragma once
#include "Person.h"
#include "Course.h"



class Student : public Person
{
	friend class Course;
private:
	int year;
	int ects_count;

	std::vector<Course*> courses;
	std::vector<int> grades;
	
public:
	Student();
	~Student();
	Student(std::string fname, std::string lname);

	void AssingCourse(Secretary* school);

	void Grade(std::string title);
	void PrintCourses();
	void AddYear();
	void PrintAll();
	void ECTS_Update();

};

