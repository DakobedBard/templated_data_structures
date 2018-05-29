#include "heap.h"
#include <iostream>

int main(){
	
	MinHeap<int> minheap(12);
	
	minheap.insert(3);
	minheap.insert(6);

	minheap.insert(9);

	minheap.insert(7);
	

	minheap.insert(4);

	minheap.insert(13);
	minheap.insert(8);

	minheap.print_minheap();

	int a = minheap.delete_min();
	//std::cout << "The minimum value in the heap is " << a << std::endl;


	minheap.print_minheap();
//	std::cout << "The capacity of the min heap is.. " << minheap.getCapacity() << std::endl;

//	std::cout << "The size of the min heap is.. " << minheap.getSize() << std::endl;

//	std::cout << "the minimum element of the min heap is " << minheap.min_element() << std::endl;
}
