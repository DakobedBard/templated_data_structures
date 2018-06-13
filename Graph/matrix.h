
#include <vector>
template<class DataType>
class Matrix{

	std::vector<DataType> **cell;

	int columns;
	int rows;
  public:

	Matrix(int columns, int rows);

	//virtual ~Matrix();

	void insert(int row, int column, const DataType& entry);
	virtual std::vector<DataType>* getCell(int row, int column);
	void clearMatrix();

};

template <class DataType>
Matrix<DataType>::Matrix(int columns, int rows){

	this->columns = columns;
	this->rows = rows;

	cell = new std::vector<DataType>* [columns];

	for(int i=0; i< columns; i++){
		cell[i] = new std::vector<DataType>[rows];
	}

}

/*
template<class DataType>
Matrix<DataType>::~Matrix(){


}

*/

template<class DataType>
std::vector<DataType>* Matrix<DataType>::getCell(int row, int column){
	return &cell[row][column];
}


