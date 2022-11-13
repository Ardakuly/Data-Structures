#include <iostream>
#include "queue.h"
using namespace std;


queue::queue():
	value(new int[5]),
	queue_size(0),
	queue_capacity(5),
	queue_front(0),
	queue_back(0)
	{

	}

queue::queue(const queue& q):
	value(new int [q.queue_capacity]),
	queue_size(q.queue_size),
	queue_capacity(q.queue_capacity),
	queue_front(0),
	queue_back(q.queue_size-1)

	{
		for(int i = 0, j = q.queue_front; i < q.queue_size; i++, j = (j+1) % q.queue_capacity){
			value[i] = q.value[j];
		}
	}

queue& queue :: operator = (queue& q){
	if(queue_capacity != q.queue_capacity){
		queue_capacity = q.queue_capacity;
		queue_size = q.queue_size;
		queue_front = 0;
		queue_back = q.queue_size-1;
		delete[] value;
		value = new int[q.queue_capacity];
	}

		for(int i = 0, j = q.queue_front; i < q.queue_size; i++, j = (j+1)%q.queue_capacity){
			value[i]=q.value[j];
		}

		return *this;
	}

void queue::push(int number){
	if(queue_size == queue_capacity){

		int *newValue = new int [queue_capacity * 2];

		for (int i = 0, j = queue_front; i < queue_size; i++,  j = (j+1)%queue_capacity){
			newValue[i] = value[j];
			queue_back = i+1;
		}

		newValue[queue_back] = number;
		queue_back++;
		queue_size++;
		delete[] value;
		queue_front = 0;
		queue_capacity = queue_capacity *2;
		value = newValue;
	}else if(queue_back == queue_capacity){
		queue_back = 0;
		value [queue_back] = number;
		queue_back++;
		queue_size++;
	}else{
		value [queue_back] = number;
		queue_back++;
		queue_size++;
	}
}

int queue::peek() const{
	return value[queue_front];
}

void queue::pop() {
	value[queue_front] = 0;
	queue_front++;
	queue_size--;
}

int queue::size() const {
	return queue_size;
}

bool queue::isEmpty() const {
	if(queue_size == 0){
		return true;
	}
	return false;
}

void queue::print()const{
	for(int i = 0, j = queue_front; i < queue_size; i++, j = (j+1)% queue_capacity){
		std :: cout << value[j] << " ";
	}
	std :: cout << std::endl;
}

queue::~queue(){
	delete[] value;
}







