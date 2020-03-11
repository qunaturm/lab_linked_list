#pragma once
#include <cassert>
#include "Node.h"

template <typename T> class LinkedList : public Node<T>
{
private:
	Node<T>* Head;
	Node<T>* Tail;

public:
	int Count = 0;

	LinkedList()
	{
		Head = 0; 
		Tail = 0;
		Count = 0;
	}

	LinkedList(T data)

	{
		Node<T> item = new Node<T>(data);
		Head = Tail = item;
		Count = 1;
	}

	LinkedList<T> operator[](int index)
	{
		assert(index < Count);
		int i = 0;
		Node<T> curr = Head->Next;
		Node<T> prev = Head;
		while (i != index)
		{
			prev = curr;
			curr = curr->Next;
		}
		return &curr;
	}

	int GetSize()
	{
		return Count;
	}

	void PushBack(T data)
	{
		if (Head != 0)
		{
			Node<T> item = new Node<T>(data);
			Tail->Next = item;
			Tail = item;
			Count += 1;
			return;
		}
		else
		{
			Node<T> item = new Node<T>(data);
			Head = Tail = item;
			Count = 1;
			return;
		}
	}
};

