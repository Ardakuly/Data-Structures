
#include <iostream>
#include "stack.h"
using namespace std;


int main() {



	stack stack1;

	stack1.push(5);
	stack1.push(78);
	stack1.push(14);
	stack1.push(13);
	stack1.push(1);


	stack1.print();


	std::cout<<stack1.size()<<std::endl;

	stack stack2(stack1);

	stack2.print();


	stack stack3;
	stack3 = stack2;

	stack3.push(99);


	stack3.print();
	stack3.pop();
	stack3.print();




	return 0;
}
