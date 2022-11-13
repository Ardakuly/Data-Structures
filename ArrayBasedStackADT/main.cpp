/*
 * main.cpp
 *
 *  Created on: Aug 20, 2021
 *      Author: Ardakuly
 */

#include "stack.h"
#include <iostream>
int main(){

	stack stack1;
	stack1.push(11);
	stack1.push(22);
	stack1.push(33);
	stack1.push(44);
	stack1.push(55);


	stack1.print();

	stack1.push(66);

	stack1.print();

	stack1.pop();
	stack1.pop();

	stack1.print();

	stack1.~stack();

	return 0;
}



