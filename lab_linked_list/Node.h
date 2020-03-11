#include <string>
#pragma once

template <typename T> class Node
{
	T data = 0;
	Node* Next;
	Node(T d) : data(d) {}
};

