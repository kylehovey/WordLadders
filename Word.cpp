// 	A word extends from string to include a boolean marker so that
// 		it can be marked in a dictionary instead of deleting it
//
// 	Author:		Kyle Hovey
//	A Number: 	A02188949

#include "Word.h"

const bool Word::isMarked() const {
		return this->marked;
}

void Word::mark() {
		this->marked = true;
}

void Word::unMark() {
		this->marked = false;
}
