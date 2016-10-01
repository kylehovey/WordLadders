// Game:	Allows you to play WordLadder games
//
// 	Author:		Kyle Hovey
//	A Number: 	A02188949

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include "Dictionary.h"
#include "LadderList.h"

class Game : public Dictionary{
	public:
		// CONSTRUCTORS
		// Default
		Game(const std::string& inFile);

		// DESTRUCTOR
		~Game();

		// METHODS
		// Play a game with two randomly chosen words of the given size
		const bool play(const int& size);

		// Play a game with a randomly chosen second word
		const bool play(const std::string& start);

		// Play a game between two chosen words
		const bool play(const std::string& start, const std::string& end);

		// Enable debugging
		void debug(const bool debugEnable = true);

		// Reset game state
		void reset();
	private:

		// List of ladders
		LadderList ladders;

		// Debug mode
		bool debugEnable;
		std::ofstream debugFile;
};

#endif
