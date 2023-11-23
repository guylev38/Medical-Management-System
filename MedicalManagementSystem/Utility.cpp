#include <iostream>
#include <string>
#include <fstream>
#include "Utility.h"
#include "Patient.h"

void printAscelpius() {
	std::ifstream file("ascelpius.txt");
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << "\n";
	}
}

void writePatientToFile(Patient patient) {
	/*
	* 1. id
	* 2. full name
	* 3. age
	* 4. hospital
	*/


	// Check if Patient is not created using default constructor
	if (patient.getId() == 0) {
		std::cout << "Can't write empty patient to file, Construct it from the Parameterized class";
	}

	// Check if one of the patient properties is EOP (END OF PATIENT)
	if (patient.getHospital() == "EOP" || patient.getFullName() == "EOP") {
		// Check only the strings
		std::cout << "Patient can't have EOP in his properties";
	}

	// check if already in file
	std::fstream r_dataFile("data.txt", std::ios::in);
	std::string line;
	std::pair<std::string, std::string> field;
	while (std::getline(r_dataFile, line)) {
		auto index = line.find(':');
		field = std::make_pair(
			line.substr(0, index),
			line.substr(index + 1)
		);

		if (field.first == "id" && field.second == std::to_string(patient.getId())) {
			std::cout << "Patient already exists" << "\n";
			return;
		}
	}
	r_dataFile.close();
	
	// Write to file if all is valid
	std::fstream w_dataFile("data.txt", std::ios::app);	

	w_dataFile << "id:" << patient.getId() << "\n";
	w_dataFile << "full name:" << patient.getFullName() << "\n";
	w_dataFile << "age:" << patient.getAge() << "\n";
	w_dataFile << "hospital:" << patient.getHospital() << "\n";
	w_dataFile << "EOP" << "\n";


	w_dataFile.close();
}




Patient readPatientFromFile(std::string s_id) {
	Patient result = Patient();
	std::string fullName;
	std::string hospital;
	int age;
	int id;

	std::fstream data("data.txt", std::ios::in);
	std::string line;
	std::pair<std::string, std::string> field;
	int hasMatched = 0;
	while (std::getline(data, line)) { 
		auto idx = line.find(":");
		field = std::make_pair(
			line.substr(0, idx),
			line.substr(idx + 1)
		);
		if (field.first == "id" && field.second == s_id) 
			hasMatched = 1;
		if (hasMatched == 1) {
			if (field.first == "full name")
				fullName = field.second;
			else if (field.first == "hospital")
				hospital = field.second;
			else if (field.first == "age")
				age = std::stoi(field.second);
			else if (field.first == "id")
				id = std::stoi(field.second);
			else if (field.first == "EOP") {
				hasMatched = 0;
				break;
			}
		}
	}

	result = Patient(fullName, hospital, age, id);

	return result;
}