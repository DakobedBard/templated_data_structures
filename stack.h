#ifndef _STACK_H_
#define _STACK_H_


template <class DataType, int MaxStack>
class Stack{

	int EmptyStack;
	DataType items[MaxStack];
	int top;

  public:
	Stack();
	~Stack();

	void push(DataType data);
	DataType pop();
	int empty();
	int full();

};

/*

I will want to seperate this out... or do I need instantiation functions for this?



*/



template<class DataType, int MaxStack>
Stack<DataType, MaxStack>::Stack(){
	EmptyStack = -1;
	top = EmptyStack;

}


/*

This line in the destructor causes everything to get completely fucked...

delete[] items,    Has items been initialized... 

*/


template<class DataType, int MaxStack>
Stack<DataType, MaxStack>::~Stack(){
	//delete[] items;		
}

template<class DataType, int MaxStack>
void Stack<DataType, MaxStack>::push(DataType data){
	items[++top ] = data;
}

template<class DataType, int MaxStack>
DataType Stack<DataType, MaxStack>::pop(){
	return items[top--];
}

template <class DataType, int MaxStack>
int Stack<DataType, MaxStack> ::empty(){
	return top == EmptyStack;
}



#endif
