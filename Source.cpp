#include <iostream>
#include <string>
#include <fstream>

#include "Person.h"
#include "Secretary.h"


#define MIN_ECTS 10
Secretary school;


using namespace std;

int Person::count = 0;


int main() {
	Secretary school;
	int choice, second_choice;
	int i;
	string name, fname, lname;

	bool semester = 0;

	do {
		cout << "1. Manage Professors" << endl;
		cout << "2. Manage Students" << endl;
		cout << "3. Manage Courses" << endl;
		cout << "4. Assign Proffesors to Course" << endl;
		cout << "5. Assign Course to Student" << endl;
		cout << "6. Teachers Set Grades" << endl;
		cout << "7. Print School,Studetnts,Professors" << endl;
		cout << "8. Check Students for Graduation" << endl;
		cout << "9. End of semester" << endl;
		cout << "10. Exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "1. Add Professor"<<endl<< "2. Remove Professor"<< endl <<"3. Edit Professor"<<endl;
			cin >> second_choice;
			switch (second_choice)
			{
			case 1:
				school += new Professor();
				cout << "NEW PROFESOOR ADDED SUCCESSFULLY" << endl;;
				break;
			case 2:
				i=school.FindProfessor();
				if (i>-1) {
					school.teachers.erase(school.teachers.begin() + i);
					cout << "PROFESOOR DELETED SUCCESSFULLY" << endl;
					break;
				}
			case 3:
				i = school.FindProfessor();
				break;
			default:
				cout << "Error Only 3 optins avialable" << endl;
			}
			
			break;
		}
		case 2: {
			cout << "1. Add Student" << endl << "2. Remove Student" << endl << "3. Edit Student" << endl;
			cin >> second_choice;
			switch (second_choice)
			{
			case 1:
				school += new Student();
				cout << "NEW STUDENT ADDED SUCCESSFULLY" << endl;;
				break;
			case 2:
				i = school.FindStudent();

				if (i > -1) {
					school.students.erase(school.students.begin() + i);
					cout << "STUDENT DELETED SUCCESSFULLY" << endl;
					break;
				}
				else
					cout << "There is no Student with that name in the School";
				break;
			case 3:
				i = school.FindStudent();
				school.students[i]->ChangePerson();
				break;
			default:
				cout << "Error Only 3 optins avialable" << endl;
				break;
			}
			break; 
		}
		case 3: {
			cout << "1. Add Course" << endl << "2. Remove Course" << endl << "3. Edit Course" << endl;
			cin >> second_choice;
			switch (second_choice)
			{
			case 1:
				school += new Course();
				cout << "NEW COURSE ADDED SUCCESSFULLY" << endl;;
				break;
			case 2:
				i = school.FindCourse();
				if (i> -1) {
					school.courses.erase(school.courses.begin() + i);
					cout << "COURSE DELETED SUCCESSFULLY" << endl;
				}
				break;
			case 3:
				i = school.FindStudent();
				school.students[i]->ChangePerson();
				break;
			default:
				cout << "Error Only 3 optins avialable" << endl;
				break;
			}

			break;
		}
		case 4: {
			cout << "Choose Course" << endl;
			cin >> name;
			i = school.FindCourse(name);
			if (i > -1) {
				school.courses[i]->AssingProffesor(&school);
				
			}
			break; 
		}
		case 5: {
			cout << "Choose Student" << endl;
			i = school.FindStudent();
			if (i > -1) {
				school.students[i]->AssingCourse(&school);
			}
			break;
		}
		case 6: {
			for (Professor* teacher : school.teachers) {
				teacher->Garde();
			}
			break;
		}
		case 7: {
			for (Professor* proffessor : school.teachers) {
				proffessor->PrintAll();
			}

			for (Student* student : school.students) {
				student->PrintAll();
			}

			for (Course* course : school.courses) {
				course->PrintAll();
			}
			break;
		}
		case 8: {

			for (Student* student : school.students) {
				bool check;
				for (Course* course : school.courses) {
					check = course->MandatoryCheck(student);
					if (check != 1) {
						break;
					}
				}
				student->PrintName();
				cout << "Ready for Graduation";
			}
			break;
		}
		case 9: {
			if (semester == 0) {
				semester = 1;
			}
			else {
				semester = 0;
				for (Student* student : school.students) {
					student->AddYear();
				}
			}
			for (Student* student : school.students) {
				student->ECTS_Update();
			}
			break;
		}
		case 10: {
			// end of program
			break;
		}
		default: {
			cout << "Invalid choice" << endl;
			break;
		}
		}

	} while(choice != 10);

}


