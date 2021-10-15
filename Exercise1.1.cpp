//============================================================================
// Name        : Exercise1.1.cpp
// Author      : Sophia Soares Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <tgmath.h>
using namespace std;

double f(double);
double integral(double, double, int);


int main() {
	double lowerBound, upperBound;
	int numIntervals;

	// Get input values from user
	do {
		cout << "Please enter the lower bound: ";
		cin >> lowerBound;
		cout << "Please enter the upper bound: ";
		cin >> upperBound;
		cout << "Please enter the number of intervals: ";
		cin >> numIntervals;

		// Check data validity
		if(lowerBound >= upperBound || numIntervals <= 0) cout << "Please enter valid distances and interval!" << endl;
	} while (lowerBound >= upperBound);

	cout << "The total area is: " << integral(lowerBound, upperBound, numIntervals) << " cm";

	return 0;
}

double f(double x) {

	// Receive an x and calculate the respective y for the exponential function of -x^2
	return exp(- (pow(x, 2)));
}

// Calculate the sum of the areas of all the rectangles under the graph function
double integral(double a, double b, int n) {
	double totalArea = 0.0;
	double height;

	// Width: interval size
	double width = (double) (b - a) / n;

	// n = number of intervals
	for(int i = 1; i <= n; i++) {
		// Calculate the height of each rectangle by calling function f(double x)
		// to then calculate their area and sum them
		height = f((double) (a + (i - 1) * width));
		totalArea += (height * width);
	}

	if(totalArea <= 0) {
		return - totalArea;
	} else {
		return totalArea;
	}

}


