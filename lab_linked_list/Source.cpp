#include<iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> l1;
	l1.GetSize();
	l1.PushBack(1);
	l1[1] = 7;

	for (int i = 1; i < l1.Count; ++i)
	{
		std::cout << l1[i] << std::endl;
	}

	return 0; 
}