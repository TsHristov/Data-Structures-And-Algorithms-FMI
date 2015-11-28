#pragma once
template<class T>
class Queue{

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
	Queue() :head(nullptr), tail(nullptr), size(0){}
	~Queue(){ delete head; }

public:
	void Enqueue(const T&);
	void Dequeue();
	bool IsEmpty() const{
		return head == nullptr;
	}
	T Peek() const;
	size_t GetSize() const{ return this->size; }
};


template<class T>
void Queue<T>::Enqueue(const T& value){
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
	//std::cout << newElem->data;
}


template<class T>
void Queue<T>::Dequeue(){
	Node *removed = head;
	head = removed->next;
	delete removed;
	--size;
	if (size == 0){
		head = nullptr;
		tail = nullptr;
	}
}


template<class T>
T Queue<T>::Peek() const{
	return head->data;
}