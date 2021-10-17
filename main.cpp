/**
 * Contains the main method to run the project and a menu for user interaction
 * @author Sophia Soares Silva
 * @version 1.0
 * @date 17.10.2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "methods.h"
using namespace std;

int main() {
	string text, password;
	int num;

	do {
		do {
			// Create a user menu
			cout << "\nHello, would you like to: \n1- Encrypt a text \n2- Decrypt a text \n3- Finish program" << endl;
			fflush(stdin);
			cin >> num;

			// Check data validity
			if(num != 1 && num != 2 && num != 3) cerr << "\n -- Please enter a valid number! --\n" << endl;
		} while (num != 1 && num != 2 && num != 3);

		// Finish program
		if(num == 3) {
			cout << "\n--- You have finished this program ---\n";
			break;
		}

		if(num == 1) {
			text = getText();
			password = getPassword(text);
			encryptText(text, password);
		} else {
			text = getText();
			password = getPassword(text);
			decryptText(text, password);
		}

	} while (num != 3);

	return 0;
}

