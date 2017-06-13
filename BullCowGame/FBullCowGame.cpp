#include "FBullCowGame.h"
using FString = std::string;
using int32 = int;

//Constructor
FBullCowGame::FBullCowGame() { Reset(); }

//Getters (they just return a value)
int FBullCowGame::GetMaxTries() const { return MyMaxTry; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString guess)
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRY = 8;
	MyMaxTry = MAX_TRY;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

//Receives a valid guess, increments the tunr number and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
    //increment the turn number
	MyCurrentTry++;

	//setup a return variable
	BullCowCount bullCowCount;

	//loop through all letters in the guess
		//compare letter against the hidden word

	return bullCowCount;
}

