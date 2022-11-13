/*
 * queue.cpp
 *
 *  Created on: Sep 10, 2021
 *      Author: Ardakuly
 */

#include <ostream>
#include <iostream>
#include "queue.h"

queue::queue():
	 q_size(0),
	 q_front(NULL),
	 q_back(NULL)
	{

	}
queue::queue(const queue& q):
		q_size(q.q_size)
	{
		node* iterator = q.q_front;
		node* temp = new node();
		temp -> value = iterator -> value;
		q_front = temp;
		while(iterator -> link != NULL){
			iterator = iterator ->link;
			node* newNode = new node();
			newNode -> value = iterator->value;
			newNode -> link = NULL;
			temp->link = newNode;
			temp = newNode;
			if(temp->link == NULL){
				q_back = temp;
			}
		}
	}
queue& queue::operator = (queue& q) {
	q_size=q.q_size;
	node* iterator = q.q_front;
	node* temp = new node();
	temp -> value = iterator -> value;
	q_front = temp;
	while(iterator -> link != NULL){
		iterator = iterator ->link;
		node* newNode = new node();
		newNode -> value = iterator->value;
		newNode -> link = NULL;
		temp->link = newNode;
		temp = newNode;
		if(temp->link == NULL){
			q_back = temp;
		}
	}
	return *this;
}

void queue :: push(int number){
	if(q_front == NULL){
		node* newNode = new node();
		newNode -> value = number;
		newNode -> link = NULL;
		q_front = newNode;
		q_back = newNode;
		q_size++;
	}else{
		node* newNode = new node();
		newNode -> value = number;
		newNode -> link = NULL;
		q_back -> link = newNode;
		q_back = newNode;
		q_size++;
	}

}

int queue :: peek() const{
	if(q_front == NULL){
		std::cout<<"Queue is empty"<<std::endl;
	}
	return q_front->value;
}

void queue :: pop(){
	if(q_front == NULL){
		std::cout<<"Queue is empty"<<std::endl;
	}

	node* temp;
	temp = q_front;
	q_front = q_front->link;
	delete temp;
}

int queue :: size() const {
	return q_size;
}

bool queue :: isEmpty() const{
	if(q_size == 0){
		return true;
	}else{
		return false;
	}
}

void queue :: print()const{
	if(q_front == NULL){
		std::cout<< "Stack is empty"<<std::endl;
	}else{
		node* iterator = q_front;
		while(iterator != NULL){
			std::cout<< iterator->value<< " ";
			iterator = iterator -> link;
		}std::cout<<std::endl;
	}
}


queue::~queue(){
	node* temp;
	while(q_front == NULL){
		temp = q_front;
		q_front = q_front->link;
		delete temp;
	}
}
