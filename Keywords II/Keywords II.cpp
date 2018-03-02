// Keywords II.cpp : Defines the entry point for the console application.
// Words we will be using:
// Spy
// Espionage
// Agent
// Asset
// Burned
// Encrypted
// Ghoul
// Sanitize
// Sleeper
// Tradecraft

#include <stdafx.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	char playAgain;
	int simNum = 0;
	const int MAX_WRONG = 10;

	// Display Title of program to user
	cout << "Keywords II\n";
	// Ask the recruit to login using thier name
	cout << "Please log in using your name: \n";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string loginName;
	cin >> loginName;
	// Display an overview of what Keywords II is to the recruit 
	cout << "You will need to determine the keyword by guessing letters until the word is complete.\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "You will enter letters when propted one at a time until you have generated the entire keyword.\n";
	cout << "You will only get 10 attempts, so choose your letters wisely.\n";

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;
	words.push_back("SPY");
	words.push_back("ESPIONAGE");
	words.push_back("AGENT");
	words.push_back("ASSET");
	words.push_back("BURNED");
	words.push_back("ENCRYPTED");
	words.push_back("GHOUL");
	words.push_back("SANITIZE");
	words.push_back("SLEEPER");
	words.push_back("TRADECRAFT");

	do
	{
		//     Increment the number of simiulations ran counter (This will set our previous 0 to 1)
		simNum++;
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		// The list was already shuffled with the vector function random_shuffle, so we just choose the first 3 words from that list instead of creating a list to hold the 3 words randomly selected.
		for (int i = 0; i < 3; ++i)
		{
			const string THE_WORD = words[i];
			int wrong = 0;
			string soFar(THE_WORD.size(), '-');
			string used = "";

			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				// Display the simulation # is staring to the recruit. 
				cout << "This is simulation #" << simNum << endl << endl;
				//     Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nYou have " << (MAX_WRONG - wrong) << " tries remaining.\n";
				//     Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;
				//     Get recruit's next guess

				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess);

				//     While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//          Get recruit ’s guess
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}
				//     Add the new guess to the group of used letters
				used += guess;
				//     If the guess is in the secret word
				if (THE_WORD.find(guess) != string::npos)
				{
					//          Tell the recruit the guess is correct
					cout << "That's right! " << guess << " is in the word.\n";

					//          Update the word guessed so far with the new letter
					for (unsigned int i = 0; i < THE_WORD.length(); ++i)
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				//     Otherwise
				else
				{
					//          Tell the recruit the guess is incorrect
					cout << "Sorry, " << guess << " isn't in the word.\n";
					//          Increment the number of incorrect guesses the recruit has made
					++wrong;
				}
			}

			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
				//     Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nYou've failed the simulation!";
			// Otherwise
			else
				//     Congratulate the recruit on guessing the secret words
				cout << "\nCongratulations you have guessed the secret word!";

			cout << "\nThe word was " << THE_WORD << endl;
		}
		// Ask the recruit if they would like to run the simulation again
		cout << "Would you like to run the simulation again? Y/N";
		cin >> playAgain;
		playAgain = toupper(playAgain);
		// If the recruit wants to run the simulation again
		//     Move program execution back up to // Display the simulation # is staring to the recruit. 
		// Otherwise 
		//     Display End of Simulations to the recruit
		// The above 4 comments are all taken care of with this one Do While loop.
	} while (playAgain == 'Y');
	system("pause");
	return 0;
}