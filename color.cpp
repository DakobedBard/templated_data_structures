#include "graph.h"
#include <iostream>

void printSolution(int color[], int V){

	std::cout << "Solution exists: Following are the assignec colors " << std::endl;
	for( int  i=0; i < V ; i++){
		std::cout << "node: " << i << " has color " << color[i] <<std::endl;
	}
	std::cout << std::endl;
}





/*

It seems to be a little bit awkward to keep passing around V like an idiot..



I'm having trouble with the recursion for this... WHAT THE HELL??



*/


bool isSafe(int v, int **graph, int color[], int c, int V){
	bool ** bool_graph = (bool **)graph;
	for( int  i=0; i < V ; i++){
		if(graph[v][i]  &&  c == color[i])
			return false;
	}
	return true;
}

bool graphColoringUtil(int ** graph , int k, int color[], int v,int V){

	std::cout << "I am calling the recursive function on " << v << std::endl;

	if(v == V)			// this is the base case at which point we are done...
		return true;


	
	for(int c = 1;c<= k; c++){
		if(isSafe(v,graph,color,c,V)){

			color[v]  = c;
/*
Recur to assign colors to rest of vertices

*/
			if(graphColoringUtil(graph, k, color, v+1, V) == true)
				return true;
			color[v] = 0;


		}
	}


	return false;
}



/*

This function returns true if it possible to color the graph using k colors

*/
bool graphColoring(AdjMatrix_Graph *graph, int k){
	
	int numV = graph->get_numVertices();

	int *color = new int[numV];

	for(int i =0; i < numV; i++){
		color[i] = 0;
	}
	// Call the recursive util function for vertex 0
	if(graphColoringUtil(graph->adjMatrix,k, color, 0, numV) == false){

		std::cout << "Solution does not exist " << std::endl;
		return false;
	} 

	printSolution(color, numV);


	return true;
}



int main(){


	//AdjMatrix_Graph adj_mat(4);

	 int graph[4][4] = {{0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}};
	
	int ** graph_ptr = (int**)malloc(sizeof(int *)*4);

	for(int i =0; i < 4; i++)
		graph_ptr[i] = (int *)malloc(sizeof(int) *4);

	// Copy the matrix 

	for(int i=0; i < 4; i++){
		for(int j=0; j < 4; j++){

			graph_ptr[i][j] = graph[i][j];
		}
	}
	

	AdjMatrix_Graph adj_mat(graph_ptr, 4);

	adj_mat.print();

	int k = 3;
	bool is_colorable = graphColoring(&adj_mat, k);
	
	






}
