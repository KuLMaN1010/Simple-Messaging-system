#pragma once
#include "Deque.h"
template<class T>
class Queue : public Deque<T> {
public:
	void Enqueue(T data)
	{
		Deque<T>::PushBack(data);
	}
	bool Dequeue(T& data)
	{
		return Deque<T>::PopFront(data);
	}
	void PrintQueue()
	{
		Deque<T>::PrintDeque();
	}
};
