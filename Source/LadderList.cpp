// LadderList: A DoublyLinkedList of string vectors with print functionality
//
//
// 	Author:		Kyle Hovey

#include "LadderList.h"

std::ostream& operator<<(std::ostream& out, const LadderList& ladders) {
	// For each ladder in the LadderList
	Node<std::vector<std::string> >* ladderNode = NULL;
	for (ladderNode = ladders.head; ladderNode != NULL; ladderNode = ladderNode->next) {
		// Begin ladder structure
		out << "[";

		// For each word in ladder
		for (int i = 0; i < (int) ladderNode->value.size(); i++) {
			// Add the word
			out << ladderNode->value[i];

			// Add a comma if this isn't the last word
			if (i != ladderNode->value.size() - 1) {
				out << ", ";
			}
		}

		// Close the structure
		out << "]\n";
	}
	
	// Return the output stream
	return out;
}
