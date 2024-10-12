#pragma once
#include "Deque.h"
template<class T>
class Stack : public Deque<T> {
public:
	void Push(T data)
	{
		Deque<T>::PushFront(data);
	}
	bool Pop(T& data)
	{
		return Deque<T>::PopFront(data);
	}
	void PrintStack()
	{
		Deque<T>::PrintDeque();
	}
};
