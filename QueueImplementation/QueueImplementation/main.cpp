#include<iostream>
#include "QueueLinkedList.h"

int main(){
	QueueLinkedList<char> obj;
	
	std::cout << "Enqueued: \n";
	for (size_t i = 0; i < 20; ++i){
		obj.Enqueue('a' + i);
	}
	std::cout << "\nDequeued: \n";

	size_t i = obj.GetSize();
	while (i)
	{
		std::cout << obj.Peek() << '\n';
		obj.Dequeue();
		--i;
	}

	return 0;
}