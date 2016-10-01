// DoublyLinkedList: A list of nodes that have
// 			next and previous nodes
//
// 	Author:		Kyle Hovey
//	A Number: 	A02188949

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>
#include "Node.h"

// Class definition
template <class T>
class DoublyLinkedList {
	public:
		// CONSTRUCTORS
		// Default
		DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

		// METHODS
		// Add a value to the head of the list
		const bool add(T val);

		// Remove an item from the head of the list
		T remove();

		// Clear all items from the list
		void clear();

		// Return true if list is empty
		const bool isEmpty() const;

		// Return true if list contains val
		const bool contains(const T& val) const;

		// Allow string printing of list
		// std::string toString();

		// Head and tail of list
		Node<T>* head;
		Node<T>* tail;

		// Size of list
		int size;
};

// Function definition
template <class T>
const bool DoublyLinkedList<T>::add(T val) {
	// Construct a new node with our value
	Node<T>* temp = new Node<T>(val, this->tail);

	// Check if list is empty
	if ( this->head == NULL ) {
		// If the list is empty, add first element
		this->head = temp;
		this->tail = temp;

		// Adjust size of list
		this->size++;

		// Return true
		return true;
	} else {
		// Otherwise, check if list contains val
		if ( !this->contains(val) ) {
			// If it doesn't, add it
			this->tail->next = temp;
			this->tail = temp;

			// Adjust size of list
			this->size++;

			// Return true
			return true;
		}
	}

	// If we got here, element was not added
	return false;
}

template <class T>
T DoublyLinkedList<T>::remove() {
	// Check to see that list is non-empty
	if ( this->head != NULL ) {
		// Get the return value
		T retVal = this->head->value;

		// Remove the first element (head)
		Node<T>* temp = this->head;	// Store the address of the head
		this->head = this->head->next;	// New head is second element
		delete temp;			// Delete old head
		temp = NULL;			// Old head is now gone, set to NULL

		// Update the head's references
		if (this->head != NULL) {
			this->head->prev = NULL;
		}
		
		// Adjust the size of the list
		this->size--;

		// Return the value
		return retVal;
	} else {
		// Fail
		T retVal = T();
		return retVal;
	}
}

template <class T>
void DoublyLinkedList<T>::clear() {
	// Check to see if list is empty
	if ( !this->isEmpty() ) {
		// Temporary pointer to store next element
		Node<T>* nextOne;

		// Delete all nodes in the list
		for ( Node<T>* temp = this->head; temp != NULL; temp = nextOne->next ) {
			// Store the next pointer
			nextOne = this->head->next;

			// Delete node
			delete temp;
		}

		// Set the head and tail to NULL
		this->head = NULL;
		this->tail = NULL;

		// Set size to zero
		this->size = 0;
	}
}

template <class T>
const bool DoublyLinkedList<T>::isEmpty() const {
	// Return true if size is zero
	return (this->size == 0);
}

template <class T>
const bool DoublyLinkedList<T>::contains(const T& val) const {
	// See if list is empty
	if ( !this->isEmpty() ) {
		// Iterate through list until we find val
		for ( Node<T>* temp = this->head; temp != NULL; temp = temp->next ) {
			// See if we have found the element
			if ( temp->value == val ) {
				return true;
			}
		}
	} else {
		// List is empty, does not contain val
		return false;
	}

	// Could not find element, return false
	return false;
}

#endif
