/*
 * stack.cpp
 *
 *  Created on: Sep 9, 2021
 *      Author: Ardakuly
 */


#include <ostream>
#include <iostream>
#include "stack.h"



stack::stack():

	head(NULL),
	s_size(0)
{
}

stack::stack(const stack& stk):
		s_size(stk.s_size)
	{
		node* iterator = stk.head;
		node* temp = new node(iterator->value);
		head = temp;
		while(iterator -> link != NULL){
			iterator = iterator ->link;
			node* newNode = new node(iterator->value);
			newNode -> link = NULL;
			temp->link = newNode;
			temp = newNode;
		}
	}

stack& stack::operator = (stack& stk){
		s_size = stk.s_size;
		node* iterator = stk.head;
		node* temp = new node(iterator->value);
		head = temp;
		while(iterator->link != NULL){
			iterator = iterator ->link;
			node* newNode = new node(iterator->value);
			temp->link = newNode;
			temp = newNode;
		}
		return *this;
}

void stack::push(int number){
	if(head == NULL){
		node* newNode = new node(number);
		newNode->link = NULL;
		head = newNode;
		s_size++;
	}else{
		node* newNode = new node(number);
		newNode -> link = head;
		head = newNode;
		s_size++;
	}

}

int stack::peek() const{
	if(head == NULL){
		std::cout<< "Stack is empty"<<std::endl;
		return 0;
	}

	return head->value;
}

void stack::pop(){
	if(head == NULL){
		std::cout<< "Stack is empty"<<std::endl;
	}
	node* temp = head;
	head = head->link;
	delete temp;
	s_size--;
}

int stack::size() const {
	return s_size;
}

bool stack::isEmpty() const{
	if(head == NULL){
		return true;
	}else{
		return true;
	}
}
void stack::print()const{
	if(head == NULL){
		std::cout<< "Stack is empty"<<std::endl;
	}else{
		node* iterator = head;
		while(iterator != NULL){
			std::cout<< iterator->value<< " ";
			iterator = iterator -> link;
		}std::cout<<std::endl;
	}
}

stack::~stack(){
	node* temp = head;
	while(temp != NULL){
		head = temp -> link;
		delete temp;
		temp = head;
	}

}
