//============================================================================
// Name        : Exercise1.3.cpp
// Author      : Sophia Soares Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define SQUARESUM(a, b) (((a) * (a)) + ((b) * (b)))
using namespace std;

int main() {

	int i1 = 3;
	int i2 = 2;

	// Check if the macro is working correctly
	cout << SQUARESUM(i1, i2) << endl;     // 13
	cout << SQUARESUM(2 + i1, i2) << endl; // 29
	cout << SQUARESUM(i1, i2 + 1) << endl; // 18
	cout << 3 * SQUARESUM(i1, i2) << endl; // 39

	return 0;
}


