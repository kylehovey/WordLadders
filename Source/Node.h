// Node:	One link in a doubly-linked list
//
// 	Author:		Kyle Hovey

#ifndef NODE_H
#define NODE_H

// Class definition
template <class T>
class Node {
	public:
		// CONSTRUCTORS
		// Default
		Node(const T  & val, Node<T>* prev = NULL, Node<T>* next = NULL) :	
			value(val), prev(prev), next(next) {};

		// PUBLIC VALUES
		// Value stored in node
		T value;

		// Next node in list
		Node<T>* next;

		// Previous node in list
		Node<T>* prev;
};

#endif
