/* This is the console executable that makes use of the BullCow class 
   This acts as the View in an MVC pattern and is responsible for all
   user interactions. For Game Logic see the FBullCowGame class.
*/
#include <iostream>
#include <string> //used for cin into a string (getline)
#include<conio.h>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Functions Prototypes
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
bool bPlayAgain;
FText GetGuess();

FBullCowGame BCGame; //creating an instance of my class (creates it on the stack and gets deleted as it goes out of scope {outsde these brackets} if you want it on the heap you need to declare it as FBullCowGame* BCGame = new FBullCowGame )

//Entry point for our application
int main()
{
	bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();	
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	_getch();
	return 0;
}


void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENGTH = 6;
	std::cout << "Welcome to Bulls and Cows, a fun word game. " << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letters isogram I'm thinking of? " << std::endl;
	std::cout << std::endl;
}

void PlayGame()
{

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	//Loop for the number of turns asking for guesses
	//TODO change to while loops once we have validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); //TODO make loop guess valid Check it
		
	    //Submit valid guess to the game
		// print number of bulls and cows

		std::cout << "Your Guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO add a game summary
}

FText GetGuess()
{	
	int32 CurrentTry = BCGame.GetCurrentTry();

	//Get a guess from the player
	FText Guess = "";
	std::cout <<"Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess); //Makes it possible to read multiple words
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	//Check the first character of Response string
	return (Response[0] == 'y' || Response[0] == 'Y');  //checks if it's true and prints 1. If it's no it prints 0
}