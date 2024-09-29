#pragma once
#include "Professor.h"
#include <vector>
#include "Student.h"
#include "Secretary.h"

class Course
{
friend class Secretary;
	friend class Professor;
	friend class Student;
protected:	

	std::string title;
	bool semester;
	int ects;
	bool mandatory;
	std::vector <Professor*> teachers;
	std::vector <Student*> students;
	 
	

public:  
	Course();

	void ChangeSemester(Course* course);
	
	void AssingProffesor(Secretary* school);

	void PrintAll();

	void Grade();

	bool MandatoryCheck(Student* student);


	friend std::ostream& operator<<(std::ostream& print, Course& course);
};

