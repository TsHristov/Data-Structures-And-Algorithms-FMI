#pragma once
template<class T>
class QueueLinkedList{

private:
	struct Node{
		T data;
		Node *next;
		Node(const T& v, Node *n) :next(n), data(v){}
		~Node(){
			if (!next){
				delete next;
			}
		}
	};

private:
	Node *head, *tail;
	size_t size;

public:
	QueueLinkedList():head(nullptr), tail(nullptr),size(0){}
	~QueueLinkedList(){delete head;}
	
public:
	void Enqueue(const T&);
	void Dequeue();
	T Peek() const;
	size_t GetSize() const{ return this->size; } 
};


template<class T>
void QueueLinkedList<T>::Enqueue(const T& value){
	Node *newElem = new Node(value, nullptr);
	if (!tail){
		tail = newElem;
	}
	else{
		tail->next = newElem;
		tail = newElem;
	}
	if (!head){
		head = newElem;
	}
	++size;
	std::cout << newElem->data;
}


template<class T>
void QueueLinkedList<T>::Dequeue(){
	Node *removed = head;
	head = removed->next;
	delete removed;
	--size;
}


template<class T>
T QueueLinkedList<T>::Peek() const{
	return head->data;
}