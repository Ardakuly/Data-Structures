/*
 * stack.cpp
 *
 *  Created on: Aug 20, 2021
 *      Author: Ardakuly
 */
#include <stdexcept>
#include <ostream>
#include <iostream>
#include "stack.h"

stack::stack():
	value(new int[5]),
	stack_size(0),
	stack_capacity(5)
{

}

stack::stack(const stack& stk):
	 value(new int [stk.stack_capacity]),
	 stack_size(stk.stack_size),
	 stack_capacity(stk.stack_capacity)


	{
		for(int i = 0; i < stk.stack_size; i++){
			value[i] = stk.value[i];
		}
	}

stack& stack :: operator = (stack& stk){
	if(stack_capacity != stk.stack_capacity){
		stack_capacity = stk.stack_capacity;
		stack_size = stk.stack_size;
		delete[] value;
		value = new int[stk.stack_capacity];
	}

	for(int i = 0; i < stk.stack_size; i++){
		value[i]=stk.value[i];
	}

	return *this;
}

void stack::push(int number){
	if(stack_size == stack_capacity){
		int *newValue = new int [stack_capacity * 2];
		for (int i = 0; i < stack_size; i++){
			newValue[i] = value[i];
		}
		newValue[stack_size] = number;
		stack_size++;
		delete[] value;
		value = newValue;


	}else{
		value [stack_size] = number;
		stack_size++;
	}
}

int stack::peek() const{
	return value[stack_size - 1];
}

void stack::pop() {
	stack_size--;
}

int stack::size() const {
	return stack_size;
}

bool stack::isEmpty() const {
	if(stack_size == 0){
		return true;
	}
	return false;
}

void stack::print()const{
	for(int i = 0; i < stack_size; i++){
		std :: cout << value[i] << " ";
	}
	std :: cout << std::endl;
}

stack::~stack(){
	delete[] value;
}



