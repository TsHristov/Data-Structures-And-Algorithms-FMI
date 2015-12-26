#include<iostream>
#pragma once
template<class T>
class DynamicArray
{
private:
	size_t size;
	size_t capacity;
	T* phead;

public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);

public:
	void insert(T);
	void resize();
	void removeElement();
	T& operator[](int);
	void free();
	size_t GetSize() const;
public:
	void print() const;
};

template<class T>
DynamicArray<T>::DynamicArray()
{
	size = 0;
	capacity = 3;
	phead = new T[capacity];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	free();
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& o){
	phead = new T[o.capacity];
	for (size_t i = 0; i <= o.size; ++i){
		phead[i] = o.phead[i];
	}
	size = o.size;
	capacity = o.capacity;
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& o){
	if (this == &o){
		return *this;
	}
	else{
		free();
		phead = new T[o.capacity];
		for (size_t i = 0; i < o.capacity; ++i){
			phead[i] = o.phead[i];
		}
		size = o.size;
		capacity = o.capacity;
	}
	return *this;
}

template<class T>
T& DynamicArray<T>::operator[](int index){
	if (index < 0 || index > capacity - 1){
		std::cout << "Index out of bounds!" << '\n';
		exit(1);
	}
	return phead[index];
}

template<class T>
void DynamicArray<T>::insert(T element){
	if (size == capacity)
	{
		this->resize();
	}
	phead[size++] = element;
}

template<class T>
void DynamicArray<T>::resize(){
	T* pToResized = new T[capacity * 2];
	for (size_t i = 0; i < capacity; ++i){
		pToResized[i] = phead[i];
	}
	delete[] phead;
	capacity *= 2;
	phead = pToResized;
}

template<class T>
void DynamicArray<T>::removeElement(){
	--size;
}

template<class T>
void DynamicArray<T>::free(){
	if (phead){
		delete[] phead;
		phead = NULL;
	}
	size = 0;
	capacity = 0;
}

template<class T>
void DynamicArray<T>::print() const{
	for (int i = 0; i < capacity; ++i){
		std::cout << phead[i];
	}
	std::cout << '\n';
}

template<class T>
size_t DynamicArray<T>::GetSize() const{
	return size;
}