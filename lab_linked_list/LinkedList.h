#pragma once
#include <cassert>
#include "Node.h"

//удалять ли временно созданные curr и prev?

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

	int GetSize()
	{
		return Count;
	}

	Node<T>* GetTail()
	{
		return Tail;
	}

	void Del(int index)
	{
		assert(0 < index < Count);
		if (index == 0)
		{
			Head = Head->Next;
			Count -= 1;
		}
		if (index == (Count - 1))
		{
			int i = 0;
			Node<T> curr = Head;
			while (i != (Count - 2))
			{
				curr = curr->Next;
			}
			Tail = curr;
			Count -= 1;
		}
		else 
		{
			int i = 0;
			Node<T> prev = Head;
			Node<T> curr = Head->Next;
			while (i != index)
			{
				prev = curr;
				curr = curr->Next;
			}
			curr = curr.Next;
			prev.Next = curr;
			Count -= 1;

		}
	}

	void PushBack(T data)
	{
		if (Head != 0)
		{
			Node<T>(data) item;
			Tail->Next = item;
			Tail = item;
			Count += 1;
		}
		else
		{
			Node<T>(data) item;
			Head = Tail = item;
			Count = 1;
		}
	}

	void Insert(int index, T data)
	{
		assert(0 < index < Count);
		Node<T>(data) item;
		if (index == 0)
		{
			item.Next = Head;
			Head = item;
			Count += 1;
		}
		if (index == (Count - 1))
		{
			PushBack(item);
			Count += 1;
		}
		else
		{
			int i = 0;
			Node<T> curr = Head->Next;
			Node<T> prev = Head;
			while (i != index)
			{
				prev = curr;
				curr = curr->Next;
			}
			prev.Next = item;
			curr = curr.Next;
			item.Next = curr;
			Count += 1;
		}
	}


	//LinkedList<T> operator[](int index)
	//{
	//	assert(0 < index < Count);
	//	int i = 0;
	//	Node<T> curr = Head->Next;
	//	Node<T> prev = Head;
	//	while (i != index)
	//	{
	//		prev = curr;
	//		curr = curr->Next;
	//	}
	//	delete prev;
	//	return &curr;
	//	delete curr; //оно сработает или нет?
	//}

	/*std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
	{
		int i = 0;
		while (i != list.Count)
		{
			out << list[i];
			i += 1;
			return out;
		}
	}*/
};

