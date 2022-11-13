/*
 * queue.h
 *
 *  Created on: Aug 23, 2021
 *      Author: Ardakuly
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class queue {

	int *value;
	int queue_size;
	int queue_capacity;
	int queue_front;
	int queue_back;

public:
	// Constructor for empty queue
	queue();
	// Copy constructor
	queue(const queue& q);
	// Assignment for queue class
	queue& operator = (queue& q);
	// Insert value to queue
	void push(int number);
	// Return the front value from queue
	int peek() const;
	//Delete value from the front queue
	void pop();
	// Return the size of queue
	int size() const;
	// Return whether queue is empty or not
	bool isEmpty() const;
	//Print queue
	void print()const;
	// Deconstructor
	~queue();

};




#endif /* QUEUE_H_ */
