/*
Oliver Moore
Personal c++ school lib
Version 1.5
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <cmath>
#include <fstream>				//file IO
#include <vector>
#include <Windows.h>
#include <exception>
#include <stdexcept>
#include <cctype>
using namespace std;

int endProgram() {
	cout << "\n\n Press enter to exit.... moore58376@mvctc.com";
	cin.ignore();
	cin.get();
	return 0;
}
int getRandom(int min, int max) {				//inclusive random gen
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}
int validateIntRange(string prompt, int min, int max) {
	int num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail() || num<min || num>max) {
		cout << "Incorrect input\nPlease enter in the correct range: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
int validateInt(string prompt) {
	int num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "ERROR TRY AGAIN: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
float validateFloat(string prompt) {
	float num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "ERROR TRY AGAIN: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
float validateFloatRange(string prompt, int min, int max) {
	float num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail() || num<min || num>max) {
		cout << "Incorrect input\nPlease enter in the correct range: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
double validateDouble(string prompt) {
	double num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail()) {
		cout << "ERROR TRY AGAIN: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
double validateDoubleRange(string prompt, int min, int max) {
	double num = 0;
	cout << endl << prompt;
	while ((!(cin >> num)) || cin.fail() || num<min || num>max) {
		cout << "Incorrect input\nPlease enter in the correct range: ";
		cin.ignore();
		cin.sync();
		cin.clear();
	}
	return num;
}
char runAgain() {
	char again = 'y';
	cout << endl << endl << "Would you like to run again?   ";
	cin >> again;
	again = tolower(again);
	while (again != 'y' && again != 'n') {
		cout << endl << "ERROR: incorrect input please enter (y/n): ";
		cin.ignore();
		cin.sync();
		cin.clear();

	}
	return again;

}
char runAgainB() {
	char again = 'y';
	cout << endl << endl << "Would you like to run again?   ";
	cin >> again;
	again = tolower(again);
	while (again != 'y' && again != 'n') {
		cout << endl << "ERROR: incorrect input please enter (y/n): ";
		cin.ignore();
		cin.sync();
		cin.clear();

	}
	return (again == 'y');
}