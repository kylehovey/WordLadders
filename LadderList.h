// LadderList: A DoublyLinkedList of string vectors with print functionality
//
//
// 	Author:		Kyle Hovey
//	A Number: 	A02188949

#ifndef LADDERLIST_H
#define LADDERLIST_H

#include <vector>
#include <iostream>
#include "DoublyLinkedList.h"

class LadderList : public DoublyLinkedList<std::vector<std::string> > {
	public:
		// CONSTRUCTORS
		// Default
		LadderList(){};

		// METHODS
		// Enable printing
		friend std::ostream& operator<<(std::ostream& out, const LadderList& ladders);
};

#endif
