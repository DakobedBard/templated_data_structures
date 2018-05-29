
#include <iostream>
#include <vector>
template <class DataType>
class Node{
  public: 

	DataType data;
	Node<DataType> *next;
	Node<DataType>(const DataType& data_):data(data_), next(){}
	Node<DataType>(const Node<DataType>& copyNode): data(copyNode.data), next(){}

};


template <class DataType>
class LinkedList{
  public:
	Node<DataType> *head;
	Node<DataType> *tail;
	LinkedList(Node<DataType> * newNode):head(newNode), tail(newNode){}
	 LinkedList():head(NULL), tail(NULL){}
	void print();
	int InsertTail(DataType val);
	int InsertHead(DataType val);
	int size;	

};


template <class DataType>
void LinkedList<DataType>::print(){
	Node<DataType> *current_node = head;
	while(current_node){
		std::cout << current_node->data<< "-->";
		current_node = current_node->next;

	}	

	std::cout<<"NULL"<< std::endl;
}

template <class DataType>
int LinkedList<DataType>::InsertTail(DataType data){
	Node<DataType> *new_node = new Node<DataType>(data);
	if(tail == NULL){
		head = new_node;
		tail = new_node;
		return 0;
	}
	tail->next = new_node;
	tail = tail->next;
	size++;

	return 0;

}
template <class DataType>
int LinkedList<DataType>::InsertHead(DataType data){
	Node<DataType> new_node = new Node<DataType>(data);
	return 1;

}


/*

This is adding a 1 to the begnninning of the merged linked_list.... pretty ugly..


*/


template <class DataType>
LinkedList<DataType> mergeTwoLists(LinkedList<DataType>* firstlist, LinkedList<DataType>* secondlist){
	LinkedList<DataType> merged_list(new Node<DataType>(1));
	//LinkedList<DataType> merged_list();
	Node<DataType>* tail1 = firstlist->head;
	Node<DataType>* tail2 = secondlist->head;

	while(tail1 != NULL && tail2 != NULL){
		

		if(tail1->data < tail2->data){
			merged_list.InsertTail(tail1->data);
			tail1 = tail1->next;
		}else{
			merged_list.InsertTail(tail2->data);
			tail2 = tail2->next;
		}
	}
/*
At this point atleast one of the input lists has no more elements in it.  Append to the list the remaining elements of the list with elements remaining.  


*/
	while(tail1 != NULL){
		merged_list.InsertTail(tail1->data);		
		tail1 = tail1->next;
	}

	while(tail2 !=NULL){
		merged_list.InsertTail(tail2->data);
		tail2 = tail2->next;	
	}

	return merged_list;

}

template <class DataType>
LinkedList<DataType> mergeKLists(std::vector<LinkedList<DataType>> list_array){

	LinkedList<DataType> merged_list(new Node<DataType>(1));

	std::cout << "The length of the vector is " << list_array.size() << std::endl;

	while(list_array.size() >1){
		list_array.push_back(mergeTwoLists(&list_array[0],&list_array[1]));
		list_array.erase(list_array.begin());
		list_array.erase(list_array.begin());

	}
	merged_list = list_array.front();
	return merged_list;

}


template <class DataType>
bool detectCycle_Hash(LinkedList<DataType>* list){

	return false;
}

template <class DataType>
bool detectCycle_TwoPointers(LinkedList<DataType>* list){

	return false;
}



