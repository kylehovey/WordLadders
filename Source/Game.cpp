// Game:	Allows you to play WordLadder games
//
// 	Author:		Kyle Hovey

#include "Game.h"

// CONSTRUCTOR
Game::Game(const std::string& inFile) : Dictionary(inFile) {
	// Seed random
	srand((int) time(NULL));

	// Reset game state
	this->reset();
}

// DESTRUCTOR
Game::~Game() {
	// If debug was enabled, close debug file
	if (this->debugEnable) {
		this->debugFile.close();
	}
}

// PUBLIC METHODS

const bool Game::play(const int& size) {
	// Play a game with some random words
	return this->play(this->randomWord(size), this->randomWord(size));

	// Debug disabled by default
	this->debugEnable = false;
}

const bool Game::play(const std::string& start) {
	// Reset the game state
	this->reset();

	// Verify that word is in dictionary
	if (this->hasWord(start)) {
		// Find second word
		std::string end = this->randomWord(start.size());

		// Play the game
		return this->play(start, end);
	} else {
		std::cout << "Word not found in dictionary." << std::endl;
		return false;
	}
}

const bool Game::play(const std::string& start, const std::string& end) {
	// Reset the game state
	this->reset();

	// Verify that words are in dictionary and are of the same length
	if (this->hasWord(start) && this->hasWord(end) && start.size() == end.size()) {
		// Notify user that the game has started and give some context
		std::cout << "Attempting to find ladder from " << start << " to " << end << std::endl;

		// DEBUG: Notify user that game has started and give some context
		if (this->debugEnable) {
			this->debugFile << "Attempting to find ladder from " << start << " to " << end;
			this->debugFile << std::endl;
		}

		// Mark the starting word
		this->hasWord(start, true);

		// Create some temporary ladders for each step
		std::vector<std::string> currentLadder, wordsOneAway, copyLadder;

		// Create the first ladder
		currentLadder.push_back(start);

		// Add our first word to the ladder
		this->ladders.add(currentLadder);

		// While dll of ladders is not empty
		while (!this->ladders.isEmpty()) {
			// DEBUG: Show partial solutions
			if (this->debugEnable) {
				this->debugFile << std::endl;
				this->debugFile << "Partial solutions:" << std::endl;
				this->debugFile << this->ladders;
				this->debugFile << std::endl;
			}

			// Remove the next ladder in line
			currentLadder = this->ladders.remove();

			// If last word in ladder is target
			if (currentLadder.back() == end) {
				// Found it!
				std::cout << "Found ladder:" << std::endl;

				// DEBUG: Report the ladder
				if (this->debugEnable) {
					this->debugFile << "Found ladder!" << std::endl;
				}

				// Return the solution
				for (int i = 0; i < (int) currentLadder.size(); i++) {
					// Print out the word
					std::cout << currentLadder[i] << std::endl;

					// DEBUG: Print the word to the debug file
					if (this->debugEnable) {
						this->debugFile << currentLadder[i] << " ";
					}
				}

				// DEBUG: Clear up some space
				if (this->debugEnable) {
					this->debugFile << std::endl;
				}

				// Did find ladder, return true
				return true;
			} else {
				// Find all words one away (excludes ones we have found)
				wordsOneAway = this->oneAway(currentLadder.back());

				// DEBUG: Show words that are one away
				if (this->debugEnable) {
					this->debugFile << "Words one away from " << currentLadder.back() << ":\n";
				}

				// For each word that is one away
				for (int i = 0; i < (int) wordsOneAway.size(); i++) {
					// DEBUG: Show words that are one away
					if (this->debugEnable) {
						this->debugFile << wordsOneAway[i] << " ";
					}

					// Add that word to a copy of the current ladder
					copyLadder = currentLadder;
					copyLadder.push_back(wordsOneAway[i]);

					// Then add it to the queue
					this->ladders.add(copyLadder);
				}
				
				// DEBUG: Clear up some space after printing out words one away
				if (this->debugEnable) {
					this->debugFile << std::endl;
				}
			}
		}

		// If we got here, no ladder was found
		std::cout << "No ladder could be found." << std::endl;

		// DEBUG: Report that no ladder could be found
		if (this->debugEnable) {
			this->debugFile << std::endl;
			this->debugFile << "No ladder could be found.";
			this->debugFile << std::endl;
		}

		// No ladder, return false
		return false;
	} else {
		// If dictionary does not have one or both of the words
		if (!(this->hasWord(start) && this->hasWord(end))) {
			std::cout << "One or both of supplied words not found in dictionary." << std::endl;
		}

		// if words are not the same size
		if (start.size() != end.size()) {
			std::cout << "Words are not of the same length." << std::endl;
		}

		// Could not find ladder
		return false;
	}
}

void Game::debug(const bool debugEnable) {
	// Enable debug
	this->debugEnable = debugEnable;

	// Set up the debug output file
	this->debugFile.open("debug.txt");
}

void Game::reset() {
	// Unmark all words
	this->unMarkAll();

	// Initialize ladders
	this->ladders = LadderList();
}
