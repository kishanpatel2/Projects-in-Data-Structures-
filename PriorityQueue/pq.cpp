//---------------------------------------------------------------------
// Name:Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 2
// Program 4.4 - Priority Queue
//
// Description: .cpp file for priority queue 
//
//---------------------------------------------------------------------
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include "pq.h"
using namespace std;

int main() {

	int option, priority; 
	int value, choice;
	priorityQueue pq;
	string input;
	
	//Int's and doubles only works for this
	cout << "1. Int\n";
	cout << "2. Double\n";
	cout << "3. Float\n";
	cout << "4. String\n";
	cout << "5. Bool\n";
	cout << "Enter your option : ";
	cin >> choice;
	
	if (choice == 1){
		int input;
	}
	else if (choice == 2){
		double input;
	}
	else if (choice == 3){
		float input;
	}
	else if (choice == 4){
		string input;
	}
	else if (choice == 5){
		bool input;
	}
	cout << "\nNow accepting commands (quit to exit program) \n";
	do {
		cin >> input;
	if (input == "enqueue") {
		cin >> value >> priority;
		pq.enqueue(value, priority);
	} else if (input == "dequeue") {
		pq.dequeue();
	} else if (input == "display"){
		pq.display();
	} else if (input == "clear"){
		value = 0;
		priority = 0;
	} else if (input == "empty"){
		value = 0;
		priority = 0;
	} else if (input == "first"){
	} else if (input == "quit") {
		cout << "Exiting Program" << endl;
	} else {
		cout << "INVALID COMMAND " << input << endl;
	}} while (input != "quit");
	
	return 0;
} 