#pragma once
template<class T>
struct DequeNode
{
	T data;
	DequeNode<T>* next = nullptr;
	DequeNode<T>* prev = nullptr;
};
