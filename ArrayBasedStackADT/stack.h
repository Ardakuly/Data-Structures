/*
 * stack
 *
 *  Created on: Aug 19, 2021
 *      Author: Ardakuly
 */

#ifndef STACK_H_
#define STACK_H_

class stack {

	int *value;
	int stack_size;
	int stack_capacity;

public:
	// Constructor for empty stack
	stack();
	// Copy constructor
	stack(const stack& stk);
	// Assignment for stack class
	stack& operator = (stack& stk);
	// Insert value to stack
	void push(int number);
	// Return the topmost value from stack
	int peek() const;
	//Delete value from stack
	void pop();
	// Return the size of stack
	int size() const;
	// Return whether stack is empty or not
	bool isEmpty() const;
	//Print Stack
	void print()const;
	// Deconstructor
	~stack();

};



#endif /* STACK_H_ */
