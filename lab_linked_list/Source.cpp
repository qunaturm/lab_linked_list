#include<iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> l1;
	l1.GetSize();
	l1.PushBack(1);
	l1[1] = 7;

	std::cout << l1 << std::endl;

	return 0; 
}