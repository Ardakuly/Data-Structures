#include "queue.h"
#include <ostream>
#include <iostream>


int main(){

	queue queue1;

	queue1.push(11);
	queue1.push(22);
	queue1.push(33);
	queue1.push(44);
	queue1.push(55);



	queue1.push(11);
	queue1.push(22);
	queue1.push(33);
	queue1.push(44);
	queue1.push(55);

	queue1.push(11);
	queue1.push(22);
	queue1.push(33);
	queue1.push(44);
	queue1.push(55);

	queue1.pop();
	queue1.pop();
	queue1.pop();

	queue1.push(21);
	queue1.push(22);
	queue1.push(23);

	std::cout << queue1.isEmpty()<<std::endl;
	std::cout << queue1.size()<<std::endl;

	//std::cout<<queue1.peek();



	queue1.print();

	return 0;
}




