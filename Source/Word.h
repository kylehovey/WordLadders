// 	A word extends from string to include a boolean marker so that
// 		it can be marked in a dictionary instead of deleting it
//
// 	Author:		Kyle Hovey

#ifndef WORD_H
#define WORD_H

#include <string>

class Word : public std::string {
	public:
		// Constructors
		Word(const std::string& word = "") : std::string(word), marked(false) {}

		// METHODS
		// Is this word marked
		const bool isMarked() const;

		// Mark a word
		void mark();

		// Unmark a word
		void unMark();
	private:
		// Is this word marked?
		bool marked;
};

#endif
