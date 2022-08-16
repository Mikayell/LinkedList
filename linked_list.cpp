#include <iostream>
#include <vector>
#include "linked_list.h"
int main()
{
	List<int> list;
	list.insertFront(37);
	list.insertBack(38);
	list.insertFront(1);
	std::cout << list;
}
