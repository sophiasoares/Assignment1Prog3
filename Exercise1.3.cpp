//============================================================================
// Name        : Exercise1.3.cpp
// Author      : Sophia Soares Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

double toRadians(double);
double calculateHeight (double, double, double);
double calculateDistance (double, double, double);
double calculateTime (double, double, double);

int main() {

	double speed, angle, height, distance, time;
	constexpr double gravity = 9.81;

	cout << "Inclined Throw" << endl << "==============" << endl;

	// Get input value from user
	do {
		cout << "Throwing speed in m/s? ";
		cin >> speed;

		// Check data validity
		if (speed <= 0) cout << "Please enter a value greater than zero!" << endl;
	} while (speed <= 0);

	// Get input value from user
	do {
		cout << "Throwing angle in degrees? ";
		cin >> angle;

		// Check data validity
		if (angle < 0 || angle > 360) cout << "Please enter a value between 0 and 360!" << endl;
	} while (angle < 0 || angle > 360);

	cout << "Result:" << endl;

	// Convert the angle received in degree to radians
	angle = toRadians(angle);

	// Show results
	distance = calculateDistance(speed, gravity, angle);
	cout << "Throwing distance: " << distance << " m" << endl;

	height = calculateHeight(speed, gravity, angle);
	cout << "Throwing height: " << height << " m" << endl;

	time = calculateTime(speed, gravity, angle);
	cout << "Time: " << time << " s" << endl;

	return 0;
}

// Convert a value given in degree to a radian value
double toRadians(double degrees) {
	return (double) (degrees * (3.141592 / 180));
}

// Calculate the height of the tennis ball with the given formula
double calculateHeight (double speed, double gravity, double degrees) {
	return ((speed * speed) * pow(sin(degrees), 2)) / (2 * gravity);
}

// Calculate the distance of the tennis ball with the given formula
double calculateDistance (double speed, double gravity, double degrees) {
	return (speed * speed * sin(2 * degrees)) / (gravity);
}

// Calculate the time of the tennis ball with the given formula
double calculateTime (double speed, double gravity, double degrees) {
	return (2 * speed * sin(degrees)) / (gravity);
}

