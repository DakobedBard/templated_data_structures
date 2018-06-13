#ifndef _VECTOR_H_
#define _VECTOR_H_


template<class DataType>
class Vector{
	static const int INITIAL_CAPACITY = 100;

	int capacity;
	int size;
	DataType *data;

	void deepCopy(const Vector<DataType> &source){
		capacity = source.size + INITIAL_CAPACITY;	
		this->data = new DataType[capacity];
		for(int i=0; i < source.size; i++){
			data[i] = source.data[i];
		}
		size = source.size;
		
	}

	// Expand the capacity of the vector

	void expandCapacity(){
		DataType *oldData = data;
		capacity *= 2;
		data = new DataType[capacity];
		for(int i=0; i < size; i++){
			data[i] = oldData[i];
		}
		delete[] oldData;
	}


  public:

	Vector();
	Vector(int n, const DataType& value);		//constructor
	Vector(Vector const& vec);			// copy constructor	
	~Vector();
	
	// Overloading operators

	DataType& operator[](int index);
	bool operator==(Vector&) const;
	Vector<DataType>& operator=(Vector<DataType> const& rhs);

	int getSize() const;
	int getCapacity() const;

};


template<class DataType>
Vector<DataType>::Vector(){
	capacity = INITIAL_CAPACITY;
	size = 0;
	data = new DataType(capacity);

}

template<class DataType>
int Vector<DataType>::getSize() const{
	return size;
}

template<class DataType>
int Vector<DataType>::getCapacity() const{
	return capacity;
}



template<class DataType>
bool Vector<DataType>::operator == (Vector& rhs)const{
	if(getSize() != rhs.getSize()){
		return false;
	}
	for(int i=0; i<getSize(); i++){
		if(data[i] != rhs[i]){
			return false;
		}
	}
	return true;
}



template<class DataType>
Vector<DataType>::Vector(Vector const& vec){
	deepCopy(vec);
}


template<class DataType>
Vector<DataType>::~Vector(){
	delete[] data;
}


#endif
