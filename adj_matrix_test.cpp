#include "graph.h"

int main(){

		AdjMatrix_Graph adj_mat(4);


	
	adj_mat.addEdge(0,1,1);
	adj_mat.addEdge(0,2,2);
	//adj_mat.addEdge(1,2,1);
	//adj_mat.addEdge(2,0,1);
	adj_mat.addEdge(2,3,3);
	adj_mat.print();



}
