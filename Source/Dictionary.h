// Dictionary class: Acts as an English word lookup
//
//	Author:		Kyle Hovey
//	A Number:	A02188949

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Word.h"

class Dictionary {
	public:
		// CONSTRUCTORS
		// Default
		Dictionary(const std::string& inFile);

		// METHODS
		// See if dict contains word, and mark it if needed
		const bool hasWord(const std::string& word, const bool& mark = false);

		// Return list of valid words one away from target word
		std::vector<std::string> oneAway(const std::string& word);

		// Find random word of a certain size
		const std::string randomWord(const int& size) const;

		// Return how many words were looked up
		const int totalMarked();

		// Unmark all words
		void unMarkAll();

		// List the first 10 words
		void listWords() const;
	private:
		// The internal dictionary
		std::vector<Word> dict;

		// Find if two strings differ by one character
		const bool isOneAway(const std::string& A, const std::string& B) const;
};

#endif
