//============================================================================
// Name        : QueueADTLL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.h"
using namespace std;

int main() {

	queue queue1;
	queue1.push(5);
	queue1.push(4);
	queue1.push(3);
	queue1.push(2);
	queue1.push(1);

	cout<<queue1.peek()<<endl;
	cout<<queue1.peek()<<endl;

	queue1.pop();
	queue1.print();

	queue queue2;



	queue2 = queue1;

	queue2.print();

	queue queue3(queue2);

	queue3.push(7);
	queue3.print();





	return 0;
}
