// Dictionary class: Acts as an English word lookup
//
// 	Author:		Kyle Hovey

#include "Dictionary.h"

Dictionary::Dictionary(const std::string& inFile) {
	// Create the file object
	std::ifstream in("dictionary.txt");

	// If file opened succesfully
	if (in.is_open()) {
		// Read in all of the entries
		Word buffer;
		while (in >> buffer) {
			this->dict.push_back(buffer);
		}
	}
	else {
		// File could not open, construction failed
		std::cout << "Could not open dictionary input file for reading." << std::endl;
		exit(1);
	}

	// Close the file object
	in.close();
}

const bool Dictionary::hasWord(const std::string& word, const bool& mark) {
	// Binary search variables
	int start = 0, end = this->dict.size() - 1, mid;

	// Search for word
	while (start <= end) {
		// Find the middle
		mid = (start + end)/2;

		// If word at index mid is target
		if (this->dict[mid] == word && !this->dict[mid].isMarked()) {
			// Found word, mark it if we have to
			if (mark) {
				// Mark the word
				this->dict[mid].mark();
			}

			// Return true if word is not already marked
			return true;
		} else if (this->dict[mid] > word) {
			// Word would be at index < mid
			end = mid - 1;
		} else {
			// Word would be at index > mid
			start = mid + 1;
		}
	}
	
	// If we got here, the word was not found
	return false;
}

std::vector<std::string> Dictionary::oneAway(const std::string& word) {
	// Generate output vector
	std::vector<std::string> out;

	// Generate mutable string to find words one away
	std::string changeWord = word;

	// For each letter in input word
	for (int i = 0; i < (int) word.size(); i++) {
		// Cycle through each possible character replacement
		for (int j = 0; j < 26; j++) {
			// Replace character
			changeWord[i] = 'a' + j;

			// See if it is an actual word (marking set to true)
			if (this->hasWord(changeWord, true)) {
				// Add it to the ladder if it is
				out.push_back(changeWord);
			}
		}

		// Reset changeWord back to original word
		changeWord[i] = word[i];
	}

	// Return value (temp)
	return out;
}

const std::string Dictionary::randomWord(const int& size) const {
	// Get a random index
	int index = rand() % (int)(this->dict.size() + 1);

	// Keep track of how many times we have searched
	int searches = 0;
	
	// Cycle through dictionary until we find a word with correct size
	for (; this->dict[index].size() != size; index++) {
		// Make sure index is within bounds
		index -= (index >= (int) this->dict.size()) ? this->dict.size() : 0;

		// One more search
		searches++;

		// Exit if we have exauhsted all items
		if (searches == this->dict.size()) {
			return "";
		}
	}
	
	// Return the found word
	return this->dict[index];
}

const int Dictionary::totalMarked() {
	// Init output
	int out = 0;

	// Find how many are marked
	for (int i = 0; i < (int) this->dict.size(); i++) {
		out += (this->dict[i].isMarked()) ? 1 : 0;
	}

	// Return the amount marked
	return out;
}

void Dictionary::unMarkAll() {
	// Unmark all words in the dictionary
	for (int i = 0; i < (int) this->dict.size(); i++) {
		this->dict[i].unMark();
	}
}

void Dictionary::listWords() const {
	// List the first 10 words
	for (int i = 0; i < 10; i++) {
		std::cout << this->dict[i] << std::endl;
	}
}

// PRIVATE METHODS
const bool Dictionary::isOneAway(const std::string& A, const std::string& B) const {
		// Verify length
		if (A.size() != B.size()) {
			// No way they can be off by one
			return false;
		}

		// Check each character (if we got here size of A is size of B)
		unsigned short int misMatched = 0;
		for (int i = 0; i < (int) A.size(); i++) {
			// See if there is a mismatch
			misMatched += (A[i] == B[i]) ? 0 : 1;

			// If more than one error
			if (misMatched > 1) {
				// Word was not one away
				return false;
			}
		}

		// If we got here, words are one away
		return true;
}
