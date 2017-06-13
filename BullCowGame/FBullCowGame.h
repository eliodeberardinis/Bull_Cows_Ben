#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialized to zero
struct BullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:

	FBullCowGame(); //Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool isGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString guess);
	BullCowCount SubmitGuess(FString);

private:
	//See Constructor for Initialization
	int32 MyCurrentTry;
	int32 MyMaxTry;
	FString MyHiddenWord;

};
