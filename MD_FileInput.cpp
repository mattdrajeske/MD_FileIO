// MD_FileInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
const int NUM_EMPLOYEES = 6;

struct Employee {
	int    number;
	string name;
	double hourlyPay;
	int    hoursWorked;
};


int main()
{
	int lineCount = 0;
	Employee employeeList[NUM_EMPLOYEES];
	string line;
	ifstream employees("input.txt");

	//to split string into tokens
	char * pch;
	pch = strtok(" ", line);

	if (employees.is_open()) {
		
		while (getline(employees, line)){
			
		}
		
		employees.close();	
	}

    return 0;
}

