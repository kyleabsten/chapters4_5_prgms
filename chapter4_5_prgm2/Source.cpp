/*
Programmer Name: Kyle Absten
Date: 03/01/2020
Description:  This is the First program for the Chapter 4-5 Assignments for cs216.

This program will ask for user input to get the name of a movie and the amount of adult and children tickets sold.
It will then calculate various values and output a report to the console.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ifstream inputFile;
	string input;

	inputFile.open("employeeSalary.txt");
	
	cout << "Reading data from the file. \n";

	if (inputFile.fail())
		cout << "Open failed";


	inputFile >> input;
	cout << input;
	inputFile >> input;

	return 0;
}