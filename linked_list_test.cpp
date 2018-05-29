#include "linked_list.h"



int main(){
	LinkedList<int> ll1(new Node<int>(1));
	ll1.InsertTail(5);
	ll1.InsertTail(10);
	ll1.InsertTail(20);

//	ll1.print();


	
	LinkedList<int> ll2(new Node<int>(3));
	ll2.InsertTail(6);
	ll2.InsertTail(8);
	ll2.InsertTail(15);
	//ll2.print();

	LinkedList<int> ll3(new Node<int>(2));
	ll3.InsertTail(4);
	ll3.InsertTail(9);
	ll3.InsertTail(19);
	ll3.InsertTail(32);
//	ll3.print();


	LinkedList<int> merged_list =  mergeTwoLists(&ll2, &ll3);
	merged_list.print();

	std::vector<LinkedList<int>> vector_of_lists;
	vector_of_lists.push_back(ll1);
	vector_of_lists.push_back(ll2);
	vector_of_lists.push_back(ll3);
	LinkedList<int> merged_k_list =  mergeKLists(vector_of_lists);
	merged_k_list.print();

	
	LinkedList<int> cyclic_list(new Node<int>(2));

	

}
