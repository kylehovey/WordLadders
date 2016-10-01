//	Main driving code for WordLadder Game class
//
//	Basic class structure
//	Node [═ DoublyLinkedList <═ LadderList [═ Game
//	Word [═ Dictionary <═══════════════════════╝
//	KEY: 
//		A ═> B : A inherits B
//		A ═] B : A composes B
//
// 	Author:		Kyle Hovey

#include "Game.h"

int main()
{  
	// Create the game
	Game game("dictionary.txt");

	// List the first 10 words of the dictionary
	std::cout << "First 10 words of dictionary: \n";
	game.listWords();

	// Play a game
	std::cout << "\nStandard game: \n";
	game.play("tree", "rain");  

	// Play a game with a random second word
	std::cout << "\nHalf-random game: \n";
	game.play("flute");  

	// DEBUG REQUIREMENTS
	// 1.) Determine how many words were read from dictionary
	std::cout << "\nTotal words indexed during last game: \n";
	std::cout << game.totalMarked() << std::endl << std::endl;

	// 2.) Display all words one away from another word
	game.reset();
	std::cout << "Words that are one away from towel: \n";
	std::vector<std::string> myWords = game.oneAway("towel");
	for (int i = 0; i < (int) myWords.size(); i++) {
		std::cout << myWords[i] << " ";
	}
	std::cout << std::endl << std::endl;

	// 3.) Be able to display contents of partial solutions
	// 			(check debug.txt after running)
	game.debug(true);				// Enable debug
	game.play("towel", "tower");	// Play a game
}
