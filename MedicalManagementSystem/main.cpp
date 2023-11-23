#include <iostream>
#include "Utility.h"
#include "Patient.h"

/*
   Main Menu
    1. Patients
        1.1 List 
        1.2 Change information
        1.3 Delete patient
    2. Create Patient
    3. Type  To Exit
*/

int main()
{
    int input = 0;
    printAscelpius();

    while (input != 99) {
        std::cout << "\t**** Main Menu ****" << "\n";
        std::cout << "\t1. Patients" << "\n";   

        std::cout << "Select > ";
        std::cin >> input;
        
        switch (input) {
        case 1:
            break;
        default:
            break;
        }
    }

    

    return 0;
}



