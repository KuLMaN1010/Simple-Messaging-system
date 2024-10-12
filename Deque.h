#pragma once
#include "DequeNode.h"
#include <iostream>
using std::cout;
template<class T>
class Deque
{
private:
	DequeNode<T>* front = nullptr;
	DequeNode<T>* back = nullptr;
	int count = 0;
public:
	void PushBack(T data)
	{
		//Create a New Node
		DequeNode<T>* vtx = new DequeNode<T>();
		vtx->data = data;
		//Check if the Deque is empty
		if (count == 0)
		{
			front = back = vtx;
			count++;
			return;
		}
		//Connect the node to the Deque
		vtx->prev = back;
		back->next = vtx;
		//Update the back pointer to refer to the new node.
		back = vtx;
		count++;
	}
	void PushFront(T data)
	{
		//Create a New Node
		DequeNode<T>* vtx = new DequeNode<T>();
		vtx->data = data;
		//Check if the Deque is empty
		if (count == 0)
		{
			front = back = vtx;
			count++;
			return;
		}
		//Connect the node to the Deque
		vtx->next = front;
		front->prev = vtx;
		//Update the back pointer to refer to the new node.
		front = vtx;
		count++;
	}
	bool PopBack(T& ret_data)
	{
		if (count == 0)
			return false;
		else
		{
			//Set aside the node to remove.
			DequeNode<T>* temp = back;
			//Update the back pointer.
			back = back->prev;
			if (back != nullptr)
			{ //Disconnect it from the list.
				back->next = nullptr;
				temp->prev = nullptr;
			}
			//return the data and clean up memory.
			ret_data = temp->data;
			delete temp;
			count--;
			return true;
		}
	}
	bool PopFront(T& ret_data)
	{
		if (count == 0)
			return false;
		else
		{
			//Set aside the node to remove.
			DequeNode<T>* temp = front;
			//Update the front pointer.
			front = front->next;
			if (front != nullptr)
			{ //Disconnect it from the list.
				front->prev = nullptr;
				temp->next = nullptr;
			}
			//return the data and clean up memory.
			ret_data = temp->data;
			delete temp;
			count--;
			return true;
		}
	}
	void PrintDeque()
	{
		DequeNode<T>* temp = front;
		while (temp != nullptr)
		{
			cout << temp->data << " <-> ";
			temp = temp->next;
		}
	}
	void ClearDeque()
	{
		T dummy;
		while (PopFront(dummy));
	}
	void CloneDeque(const Deque<T>& deque)
	{
		DequeNode<T>* temp = deque.front;
		ClearDeque();
		while (temp != nullptr)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
	}
};

