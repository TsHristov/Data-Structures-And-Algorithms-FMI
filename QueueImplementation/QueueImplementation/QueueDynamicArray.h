#pragma once
//circular array
template<class T>
class QueueDynamicArray{
private:
	T *q;
	int head, tail;
	size_t capacity;
	size_t size;

public:
	QueueDynamicArray(){
		capacity = 10;
		head = -1;
		tail = -1;
		size = 0;
		q = new T[capacity];
	}
	~QueueDynamicArray(){ delete q; }
	
public:
	void Enqueue(const T&);
	void Dequeue();
	T Peek() const;

public:
	int GetNextPosition(int pos) const{ 
		return (pos + 1) % capacity;
	}

public:
	size_t GetSize() const{ return size; }
	bool IsFull() const;
	bool IsEmpty() const;

private:
	void resize();
};


template<class T>
void QueueDynamicArray<T>::Enqueue(const T& value){
	if (IsFull() || size == capacity - 1){
		this->resize();
	}
	tail = GetNextPosition(tail);
	q[tail] = value;
	++size;
	std::cout << q[tail] << '\n';
}


template<class T>
void QueueDynamicArray<T>::Dequeue(){
	if (IsEmpty()){
		return;
	}
	else{
		head = GetNextPosition(head);
		--size;
	}
}


template<class T>
T QueueDynamicArray<T>::Peek() const{
	if (head != -1)
		return q[head];
}


template<class T>
bool QueueDynamicArray<T>::IsFull() const{
		return (tail + 1) % capacity == head;
}


template<class T>
bool QueueDynamicArray<T>::IsEmpty() const{
	return head == -1 && tail == -1;
}

template<class T>
void QueueDynamicArray<T>::resize(){
	capacity *= 2;
	T *newarr = new T[capacity];
	for (size_t h = head; head != tail; head = GetNextPosition(head))
	{
		newarr[head] = q[head];
	}
	delete q;
}