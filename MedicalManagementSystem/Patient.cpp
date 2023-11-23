#include <iostream>
#include "Patient.h"

Patient::Patient(std::string fullName, std::string hospital, int age, int id) {
	this->fullName = fullName;
	this->hospital = hospital;
	this->age = age;
	this->id = id;
}

Patient::Patient() {
	this->fullName = "";
	this->hospital = "";
	this->age = 0;
	this->id = 0;
}

void Patient::setFullName(std::string fullName) {
	this->fullName = fullName;
}

void Patient::setHospital(std::string hospital) {
	this->hospital = hospital;
}

void Patient::setAge(int age) {
	this->age = age;
}
void Patient::setId(int id) {
	this->id = id;
}

void Patient::toString() {
	std::cout << "Full Name: " << this->fullName << "\n";
	std::cout << "Hospital: " << this->hospital << "\n";
	std::cout << "Age: " << this->age << "\n";
	std::cout << "Id: " << this->id << "\n";
}

std::string Patient::getFullName() {
	return this->fullName;
}

std::string Patient::getHospital() {
	return this->hospital;
}

int Patient::getAge() {
	return this->age;
}
int Patient::getId() {
	return this->id;
}