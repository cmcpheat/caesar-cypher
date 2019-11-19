// CAESAR CYPHER
#include <iostream>
#include <string>
#include <locale>

using namespace std;

/*
 * Generates a random key
 * Between 1-100
 * Key is passed to encode / decode funcs
*/

int keygen()
{
	int key;
	srand(time(NULL)); // resets rand key to 0
	key = rand() % 25 + 1;
	cout << "KEY: " << key << "\n" << endl; // for testing
	return key;
}

/*
 * Asks the user to input a message
 * Takes entire string (incl. spaces)
 * and stores in the input variable
*/

string getinput()
{
	string input;
	cout << "ENTER A MESSAGE: " << endl;
	getline(cin, input); // stores the user input as 'input'
	return input;
}

/*
 * Encodes the plaintext
 * Loops through each character and checks if alphanumeric
 * If alpha, the char is shifted (+ the key)
 * If a special char, it doesn't change
 * Upper / lower case is retained
*/

string encrypt(string pt, int key)
{
	int ch;
	int len = pt.length();
	string cypher;

	// Loop through each character in the plaintext
	for (ch = 0; ch < len; ch++)
	{
		// Checks character is in alphabet    
		if (isalpha(pt[ch]))
		{
			for (int i = 0; i < key; i++)
			{
				if (pt[ch] == 'z') // if end of alphabet, reset to a
					pt[ch] = 'a';
				else if (pt[ch] == 'Z') // if end of alphabet, reset to a
					pt[ch] = 'A';
				else
					pt[ch]++;
			}
		}
	}
	cypher = pt;
	cout << "ENCRYPTED: \n" << cypher << endl;
	return cypher;
}

/*
 * Decodes the cyphertext
 * Loops through each character and checks if alphanumeric
 * If alpha, the char is shifted (- the key)
 * If a special char, it doesn't change
 * Upper / lower case is retained
*/

string decrypt(string ct, int key)
{
	int ch;
	int len = ct.length();
	string plain;

	// Loop through each character in the cyphertext
	for (ch = 0; ch < len; ch++)
	{
		// Checks character is in alphabet    
		if (isalpha(ct[ch]))
		{
			for (int i = 0; i < key; i++)
			{
				if (ct[ch] == 'a') // if start of alphabet, reset to z
					ct[ch] = 'z';
				else if (ct[ch] == 'A') // if start of alphabet, reset to z
					ct[ch] = 'Z';
				else
					ct[ch]--;
			}
		}
	}
	plain = ct;
	cout << "DECRYPTED: \n" << plain << endl;
	return plain;
}

// Main function
int main()
{
	int key = keygen();
	string input = getinput();
	string ct = encrypt(input, key);
	string pt = decrypt(ct, key);
}

