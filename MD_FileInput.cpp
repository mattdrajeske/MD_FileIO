// MD_FileInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>

using namespace std;
const int SIZE = 6;


struct Employee {
	int    id;
	string name;
	double hourlyPay;
	int    hoursWorked;
};

int main()
{
	cout << "hi\n";
	ifstream data("input.txt");
	ofstream report("output.txt");
	Employee employee[SIZE];
	double grossPay;
	double totalPay = 0;

	cout << fixed;
	cout << setprecision(2);
	report << fixed;
	report << setprecision(2);

	if (data.is_open() && report.is_open()) {
		cout << "Retrieving input\n";
		for (int i = 0; i < SIZE; i++) {
			//get data from file
			data >> employee[i].id >> employee[i].name >> employee[i].hourlyPay >> employee[i].hoursWorked;
			
			//calculate gross pay
			grossPay = employee[i].hourlyPay*employee[i].hoursWorked;
			totalPay += grossPay;
			cout << employee[i].id << " " << employee[i].name << " " << grossPay << "\n";
		}
		//total pay
		cout << totalPay << "\n";
		
		//write to output file
		cout << "Writing to output file\n";
		for (int i = 0; i < SIZE; i++) {
			report << employee[i].id << " " << employee[i].name << " " << grossPay << "\n";
		}
		report << totalPay;
		
	}


}
	
