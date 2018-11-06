// MD_FileInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace std;
const int NUM_EMPLOYEES = 6;
const int NUM_SPACES = 10;
int lineCount = 0;

struct Employee {
	int    number;
	string name;
	double hourlyPay;
	int    hoursWorked;
};

int main()
{
	//int lineCount = 0;
	string line;
	string employeeStringArray[NUM_EMPLOYEES];
	ifstream table("input.txt");

	if (table.is_open()) {
		while (getline(table, line)) {
			employeeStringArray[lineCount] = line;
			lineCount++;
		}
	}


	string delimiter = " ";
	ofstream print("output.txt");
	Employee employeeStructArray[NUM_EMPLOYEES];
	double grossPay;
	double totalPay = 0;
	if (print.is_open()) {
		for (int i = 0; i < lineCount; i++) {			
			employeeStructArray[i].number = stoi(employeeStringArray[i].substr(0, employeeStringArray[i].find(delimiter)));
			employeeStringArray[i].erase(0, employeeStringArray[i].find(delimiter)-1 );

			employeeStructArray[i].name = employeeStringArray[i].substr(0, employeeStringArray[i].find(delimiter));
			employeeStringArray[i].erase(0, employeeStringArray[i].find(delimiter) -1 );

			employeeStructArray[i].hourlyPay = stod(employeeStringArray[i].substr(0, employeeStringArray[i].find(delimiter)));
			employeeStringArray[i].erase(0, employeeStringArray[i].find(delimiter) -1 );

			employeeStructArray[i].hoursWorked = stoi(employeeStringArray[i].substr(0, employeeStringArray[i].find(delimiter)));
			employeeStringArray[i].erase(0, employeeStringArray[i].find(delimiter)-1);

			grossPay = employeeStructArray[i].hourlyPay * employeeStructArray[i].hoursWorked;
			totalPay += grossPay;

			print << employeeStructArray[i].number << ",\t" << employeeStructArray[i].name << ",\t" << grossPay << "\n";
			
		}
		print << totalPay;
		print.close();
	}
}
	
