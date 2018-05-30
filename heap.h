
#include <vector>
#include <climits>
#include <iostream>

/*

Temoplated Min heap implementation.



Things to do:

	Heap Sort


	Decrease key...

*/




template <class DataType>
class MinHeap{
  private:
	int capacity;
	int heap_size;
	DataType* min_element_;
	std::vector<DataType> array;

  public:
	int pos;
	MinHeap(int capacity_):capacity(capacity_){
		std::vector<DataType>* arr = new std::vector<DataType>(capacity);

		array = *arr;
		pos =0;
	}

	int getsize(){
		return heap_size;
	}


	// Heapify a subtree with root at given index



	// Return the index of the left child of node at index i



	void print_minheap(){
		for(int i =0; i < heap_size; i++){
			std::cout << array[i] << " " ;
		}
		std::cout << std::endl;
	}

	int left_child(int i){
	
		return(2*i+2);

	}
	int right_child(int i){
		return(2*i+1);
	}	

	int parent(int i){
		return (i-1)/2;
	}


	DataType min_element(){
		return array[0];
	}

	DataType pop_min(){
		DataType min = array[0];
		return min;
	}

	void insert(DataType i){
	
		int hole = heap_size;
		if(heap_size ==0){
			array[0] = i;

		}

		while( i < array[parent(hole)] && hole>1){
		//	std::cout << "I am on i : " << i << " the hole is at " << hole << std::endl; 
			array[hole] = array[parent(hole)];
			hole = parent(hole);
			
			
		}
		array[hole] = i;
		heap_size++;
				
	}

/*

When deleting the minimum element, the size of the heap will be one smaller afterwards.  

The implementation in the book uses a while loop to percolate the hole down while the minheapify method from geeksforgeeks uses a recursive implemenation.  


*/

	
	DataType delete_min(){
		
		if(heap_size == 0)
			return (DataType) NULL;

		if(heap_size == 1){
			heap_size--;	
			return array[0];
		}

		DataType return_value = array[0];
		array[0] = array[heap_size-1];
		heap_size --;

		MinHeapify(0);

		return return_value;

	}

	void percolateDown(int hole){
		int child;
		DataType tmp = array[hole];
		std::cout << "tmp: " << tmp << std::endl;
		
		while(hole*2 <= heap_size){

		}

	}

	// Recursive method to heapify a subtree with the root at index i.  This method assumes that the subtrees already heapified

	void MinHeapify(int i){

		int l = left_child(i);
		int r = right_child(i);
		int smallest = i;
		if( l < heap_size && array[l] < array[i])		// compare the hole to the left then the right child
			smallest = l;					// if smaller than both go to right, if smaller 
		if(r<heap_size && array[r] < array[smallest])
			smallest = r;
		if(smallest != i)
		{
			swap(&array[i], &array[smallest]);		// swap the elements in the array...
			MinHeapify(smallest);				// recursivly call MinHeapify..
		}
	

	}



	void swap(DataType *x, DataType *y){
		DataType temp = *x;
		*x = *y;
		*y = temp;

	}

	int getCapacity(){
		return array.size();
	}

	int getSize(){
		return heap_size;
	}


};
