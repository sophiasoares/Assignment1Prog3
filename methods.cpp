/**
 * Contains all methods necessary to run the project
 * @author Sophia Soares Silva
 * @version 1.0
 * @date 17.10.2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "methods.h"
using namespace std;


/**
 * Method to encrypt the text given by the user with the help of the password
 * @param text
 * @param password
 * @author Sophia Soares Silva
 */
void encryptText(string text, string password) {
	string result;
	int k = (int) text.size();

	for (int j = 0; j < k; ++j) {

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


/**
 * Method to decrypt the text given by the user with the help of the password
 * @param text
 * @param password
 * @author Sophia Soares Silva
 */
void decryptText(string text, string password) {
	string result;
	int k = (int) text.size();

	for (int j = 0 ; j < k; ++j) {

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


/**
 * Method to get the input text from the user and convert
 * all characters to upper case
 * @return text
 * @author Sophia Soares Silva
 */
string getText() {
	string text;

	cout << "Please enter the text: ";
	fflush(stdin);
	getline(cin, text);

	// Convert the text to upper case
	transform(text.begin(), text.end(), text.begin(), ::toupper);

	return text;
}


/**
 * Method to get the input password from the user, convert all characters to upper case
 * and create a password with the same size as the text passed as a parameter
 * @param text
 * @return password
 * @author Sophia Soares Silva
 */
string getPassword(string text) {
	string password;

	cout << "Please enter the password: ";
	fflush(stdin);
	getline(cin, password);

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

