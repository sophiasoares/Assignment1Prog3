#include <iostream>
#include <algorithm>
#include <string>
//#include<bits/stdc++.h>
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
			cout << "\n--- You have finished this program ---";
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
        // Convert in range 0-25
        char c = (text[j] + password[j]) %26;
 
        // Convert into letters
        c += 'A';
 
        result.push_back(c);
    }
	
	cout << "\nEncrypted text: " << result << endl;
}

void decryptText(string text, string password) {
	string result;

	for (int j = 0 ; j < text.size(); ++j) {
        // Convert in range 0-25
        char c = (text[j] - password[j] + 26) %26;
 
        // Convert into letters
        c += 'A';
        result.push_back(c);
    }
	
	cout << "\nDecrypted text: " << result << endl;
}

string getText() {
	string text;
	
	cout << "Please enter the text: ";
	getline(cin >> ws, text);
	
	// Cut out all of the white spaces
	text.erase(remove(text.begin(), text.end(), ' '), text.end());
	
	// Convert the text to uppercase
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	
	return text;
}

string getPassword(string text) {
	string password;
	
	cout << "Please enter the password: ";
	getline(cin >> ws, password);
	
	// Cut out all of the white spaces
	password.erase(remove(password.begin(), password.end(), ' '), password.end());
	
	// Convert the text to uppercase
	transform(password.begin(), password.end(), password.begin(), ::toupper);
	
	// Generate a password with the same size as the text 
	int j = text.size();
    for (int i = 0; ; i++) {
        if (j == i)
            i = 0;
        if (password.size() == text.size())
            break;
        password.push_back(password[i]);
    }
	return password;
} 


