//============================================================================
// Name        : Exercise1.1.cpp
// Author      : Sophia Soares Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int lowerLimit, upperLimit;

	// Get input values from user
	do {
		cout << "Please enter lower limit: ";
		cin >> lowerLimit;
		cout << "Please enter upper limit: ";
		cin >> upperLimit;

		// Check data validity
		if (lowerLimit > upperLimit || lowerLimit < 32 || upperLimit > 255) {
			cout << "Please enter numbers between 32 and 255!" << endl;
		}

	} while (lowerLimit > upperLimit || lowerLimit < 32 || upperLimit > 255);

	char character;
	cout << "Code Character" << endl;

	// For each character between the limits, convert the integer value to its respective ASCII symbol
	for (int i = lowerLimit; i <= upperLimit; i++) {

		// Cast the integer value to a character to get the ASCII symbol
		character = (char) i;
		cout << i << "   " << "'" << character << "'" << endl;
	}

	return 0;
}


/* Exercise 1.2
 * a) x = 0
 * b) When a signed and an unsigned integers are compared, the signed integer will be
 * converted to unsigned. And because unsigned integers cannot store negative numbers,
 * this can result in loss of data. The loop will not run.
 */



