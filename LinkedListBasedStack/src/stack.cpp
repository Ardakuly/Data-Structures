/*
 * stack.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: Ardakuly
 */

#include <iostream>
#include <ostream>
#include "stack.h"
using namespace std;

stack::stack():
	head(NULL),
	stack_size(0)
{}

stack::stack(const stack& stk):
		head(NULL),
		stack_size(stk.stack_size)
{
	node* newNode;
	node* nextNode;
	node* iterator = stk.head;
	head = new node(iterator->value);
	newNode = head;
	while(iterator){
		if(newNode != head){
			newNode = new node(iterator->value);
		}
		if(iterator -> next != NULL){
			iterator = iterator->next;
			nextNode = new node(iterator->value);
			newNode->next = nextNode;
			iterator = iterator->next;
		}newNode = NULL;
	}
}



stack& stack :: operator = (const stack& stk){
	node* newNode;
	node* nextNode;
	node* iterator = stk.head;
	head = new node(iterator->value);
	newNode = head;
	while(iterator){
		if(newNode != head){
			newNode = new node(iterator->value);
			stack_size++;
		}
		if(iterator -> next != NULL){
			iterator = iterator->next;
			nextNode = new node(iterator->value);
			stack_size++;
			newNode->next = nextNode;
			iterator = iterator->next;
		}newNode = NULL;
	}

	return *this;
}

void stack::push(int number){
	node *nextTop = new node(number);
	nextTop -> value = number;
	if(head == NULL){
		head  = nextTop;
		head->next = NULL;

	}
	nextTop -> next = head;
	head = nextTop;
	stack_size++;
}

int stack::peek() const{
	return head -> value;
}

void stack::pop() {
	if(head == NULL){
		std::cout<<"Stack is empty"<<std::endl;
	}
	node *old_top = head;
	head = head->next;
	delete old_top;
	stack_size--;
}

int stack::size() const {
	return stack_size;
}

bool stack::isEmpty() const {
	if(head == NULL){
		return true;
	}
	return false;

}

void stack::print()const{
	node* current = head;
	while(current->next == NULL){
		std::cout<<current->value << " ";
		current = current->next;
	}std::cout<<current->value << std::endl;
}

stack::~stack(){
	node* current = head;
	node* next;
	while(current){
		next = current->next;
		delete current;
		current = next;
	}
}










