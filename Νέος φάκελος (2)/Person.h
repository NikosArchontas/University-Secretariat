#pragma once
#include <string>


class Person {
protected:
	friend class Secretary;
	std::string first_name;
	std::string last_name;
	bool type;

public:
	static int count;
	

	Person();
	~Person();
	Person(std::string fname, std::string lname);

	void PrintCount();
	void PrintName();
	void ChangePerson();
	friend std::ostream& operator<<(std::ostream& print, Person& person);
	friend std::istream& operator>>(std::istream& get, Person& person);
};