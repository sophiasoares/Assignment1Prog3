//============================================================================
// Name        : Exercise1.2.cpp
// Author      : Sophia Soares Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

void encryptText(string, string);
void decryptText(string, string);
string getText();
string getPassword(string);

int main() {
	string text, password;
	int num;

	do {
		do {
			// Create a user menu
			cout << "\nHello, would you like to: \n1- Encrypt a text \n2- Decrypt a text \n3- Finish program" << endl;
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

void encryptText(string text, string password) {
	string result;

	for (int j = 0; j < text.size(); ++j) {

		if(text[j] != ' ') {

			// Convert in range 0-25
			char c = (text[j] + password[j]) %26;

			// Convert to letters
			c += 'A';

			// Concatenate the next character
			result.push_back(c);
		} else {
			result += ' ';
		}

	}

	cout << "\nEncrypted text: " << result << endl;
}

void decryptText(string text, string password) {
	string result;

	for (int j = 0 ; j < text.size(); ++j) {

		if(text[j] != ' ') {
			// Convert in range 0-25
			char c = (text[j] - password[j] + 26) %26;

			// Convert to letters
			c += 'A';

			// Concatenate the next character
			result.push_back(c);
		} else {
			result += ' ';
		}

	}
	// Convert the text to lower case
	transform(result.begin(), result.end(), result.begin(), ::tolower);

	cout << "\nDecrypted text: " << result << endl;
}

string getText() {
	string text;

	cout << "Please enter the text: ";
	getline(cin >> ws, text);

	// Convert the text to upper case
	transform(text.begin(), text.end(), text.begin(), ::toupper);

	return text;
}

string getPassword(string text) {
	string password;

	cout << "Please enter the password: ";
	getline(cin >> ws, password);

	// Convert the text to upper case
	transform(password.begin(), password.end(), password.begin(), ::toupper);

	// Generate a password with the same size as the text
	int j = text.size();
	for (int i = 0; ; i++) {

		// Add a space if the text has a space
		if (text[password.size()] == ' ') password += ' ';

		if (j == i) i = 0;
		if (password.size() == text.size()) break;

		// If the character to be repeated is a space, repeat the next character and not the space
		if(password[i] == ' ') {
			password.push_back(password[i + 1]);
			i++;
		} else {
			password.push_back(password[i]);
		}

	}

	return password;
}

