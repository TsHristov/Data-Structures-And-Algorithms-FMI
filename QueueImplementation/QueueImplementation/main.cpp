#include<iostream>
#include "QueueLinkedList.h"
int main(){
	QueueLinkedList<int> obj;
	obj.Enqueue(1);
	obj.Enqueue(2);
	obj.Enqueue(3);
	obj.Enqueue(4);

	int x = obj.Dequeue();
	std::cout << x << '\n';

	return 0;
}