/*

This is my implementation of LinkedList...


*/





template <class DataType>
class Node{
	DataType data;

  public:
	Node* next;
	Node<DataType>(DataType data_): data(data_){}
	DataType getData(){
		return data;
	}
};


template <class DataType>
class LinkedList{

 	
	Node<DataType>* head;
	Node<DataType>* tail;
	int size;
  public:
	LinkedList():head(nullptr), tail(nullptr){}			// Base constructor setting the head and the tail to nullptrs
	int getSize();
	Node<DataType>* gethead(){
		return head;
	}
	Node<DataType>* gettail(){
		return tail;
	}


	void insert_tail(DataType item);
	void insert_head(DataType item);

};


template<class DataType>
int LinkedList<DataType>::getSize(){
		return size;
}





template <class DataType>
void LinkedList<DataType>::insert_head(DataType item){

	
	
	
}

/*

Insert an element to the tail of the LinkedList

*/

template <class DataType>
void LinkedList<DataType>::Inserttail(DataType item){
		
	
	Node<DataType> *new_node = new Node<DataType>(item);
		
	if(tail == nullptr){
		head = new_node;
		tail = new_node;
		return ;
	}
	
	tail->next = new_node;
	tail = tail->next;
	size++;
}

