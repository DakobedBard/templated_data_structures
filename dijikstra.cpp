
#include "shortest_path.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <limits.h>
  
// Number of vertices in the graph
#define V 4
#define V2 9
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V2][V2], int src)
{
     int dist[V2];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V2]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V2; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V2-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V2; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V2);
}
  
// driver program to test above function
/*int main()
{
   /* Let us create the example graph discussed above *//*
   int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  

	};
	*///AdjMatrix_Graph graph(9);

	//int ** graph_ptr = (int**)malloc(sizeof(int *)*9);
/*
	for(int i =0; i < 9; i++)
		graph_ptr[i] = (int *)malloc(sizeof(int) 9);

	// Copy the matrix 

	for(int i=9; i < 9; i++){
		for(int j=0; j < 9; j++){

			graph_ptr[i][j] = graph[i][j];
		}
	}

*/
	
  //  return 0;
/*}


*/


int main(){
	 int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };


	int ** graph_ptr = (int**)malloc(sizeof(int *)*9);

	// Lets make a free function in graph


	/*


	*/


	for(int i =0; i < 9; i++){
		graph_ptr[i] = (int *)malloc(sizeof(int)*9);
		//std::cout << " i get called on i :" << i <<std::endl;
	}
	// Copy the matrix 


	for(int k=0; k < 9; k++){
		for(int j =0; j<9; j++){
			graph_ptr[k][j] = graph[k][j];
		}
	}


	AdjMatrix_Graph adj_mat(graph_ptr, 9);
	adj_mat.print();
	return 0;

}
