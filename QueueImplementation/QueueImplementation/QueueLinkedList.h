#pragma once
template<class T>
class QueueLinkedList{
	struct Node{
		T data;
		Node *next;
		Node(const T& v, Node *n) :next(n), data(v){}
		~Node(){
			delete next;
		}
	};
	Node *head, *tail;
	//size_t size;
public:
	QueueLinkedList(){
		head = nullptr;
		tail = nullptr;
		//size = 0;
	}
	~QueueLinkedList(){ 
		delete head; 
	}
	void Enqueue(const T& v){
		Node *n = new Node(v, NULL);
		tail->next = n;
		tail = n;
		//++size;
		if (!head){
			head = n;
		}
	}
	T& Dequeue(){
		T headData = head->data;
		Node *newHead = head->next;
		delete head;
		head = newHead;
		return headData;
	}
	/*bool IsEmpty(){
		return size == 0;
	}*/
	bool IsFull(){
		return head == tail;
	}
};