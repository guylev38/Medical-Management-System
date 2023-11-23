#pragma once
#include <iostream>

class Patient {
	std::string fullName, hospital;
	int age, id;
	
public:
	Patient(std::string fullName, std::string hospital, int age, int id);
	Patient();
	void setFullName(std::string fullName);
	void setHospital(std::string hospital);
	void setAge(int age);
	void setId(int id);
	void toString();

	std::string getFullName();
	std::string getHospital();
	int getAge();
	int getId();
};