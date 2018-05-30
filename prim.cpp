/*

Prim's algorithm


1) create a set mstSet that keeps track of vertices already dincluded in MST

2)  Assign a key value to all vertices in the input graph.  Initialize all key values as INFINITE.  assign key value as 0 for the first vertex.




*/


#include "heap.h"
#include "graph.h"
#include <limits.h>

// Aparantly when we use an adjacency lsit representation we use a priority queue 


int minWeight(int key[], bool mstSet[], int V){
	int min = INT_MAX;
	int min_index;
	
	for(int v =0; v<V; v++){
		if(mstSet[v] == false && key[v] < min)
			min = key[v];
			min_index = v;
	}
	return min_index;

}




void PrimMST(AdjMatrix_Graph *graph, int s){
	int V = graph->get_numVertices();
	graph->print();


	int parent[V];  // Array to store constructed MST
	int key[V];   	// Key values used to pick minimum weight edge in cut
	bool mstSet[V];


	for(int i =0; i < V; i++){

		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	
	key[0] =0;		// Make key 0 so that this vertex is picked as first vertex
	parent[0] = -1;		//first node is always root of MST


	for(int count=0; count < V-1; count++){

		int min_weight = minWeight(key, mstSet, V);
		std::cout << "min weight " << min_weight << std::endl;
		//Pick the minimum key vertex from the set of vertices not yet included 

		mstSet[min_weight] = true;
		// Update the key value and parent index of the adjacent vertices of the picked vertex.  Consider only thse vertices which are no included in the MST

		for(int v=0; v<V; v++){

			// graph[u][v] is non zero only for adjacent vertices  while mstSet[v] is false for verties not yet included in MST

			if((graph->adjMatrix)[min_weight][v] && mstSet[v] == false && (graph->adjMatrix)[min_weight][v]){
				parent[v] = min_weight;
				key[v] = (graph->adjMatrix)[min_weight][v];
			}

		}

	}

	std::cout << "Edge   Weight " << std::endl;
	for(int i =0; i < V; i++){
		std::cout << parent[i] << "  " << i << "  ";// << (graph->adjMatrix)[i][parent[i]] ;
		
		std::cout << std::endl;
	}

	std::cout << std::endl;


}




void PrimMST_adjlist(AdjList_Graph *graph){
	int V = graph->getV();				// Get the number of vertides in graph
	int parent[V];					// Array to store construct MST
	int key[V];

	MinHeap<GraphNode> minheap(V) ;
	for(int v = 1; v < V; ++v){
		parent[v] = -1;
		key[v] = INT_MAX;
	//	minheap.insert(
	
	}

}



int main(){
	AdjMatrix_Graph adj_mat(5);
	
	adj_mat.addEdge(0,1,2);
	adj_mat.addEdge(1,0,2);

	adj_mat.addEdge(1,2,3);
	adj_mat.addEdge(2,1,3);

	adj_mat.addEdge(2,4,7);
	adj_mat.addEdge(4,2,7);

	adj_mat.addEdge(1,4,5);
	adj_mat.addEdge(4,1,5);

	adj_mat.addEdge(1,3,8);
	adj_mat.addEdge(3,1,8);

	adj_mat.addEdge(0,3,6);
	adj_mat.addEdge(3,0,6);


	adj_mat.addEdge(3,4,9);
	adj_mat.addEdge(4,3,9);

	PrimMST(&adj_mat, 0);


	AdjList_Graph graph(9);

/*
	graph.insert_edge(0,1,4);
	graph.insert_edge(0,7,8);
	graph.insert_edge(1,2,8);
	graph.insert_edge( 1, 7, 11);
   	graph.insert_edge( 2, 3, 7);
  	graph.insert_edge( 2, 8, 2);
    	graph.insert_edge(2, 5, 4);
    	graph.insert_edge( 3, 4, 9);
    	graph.insert_edge(3, 5, 14);
    	graph.insert_edge( 4, 5, 10);
   	graph.insert_edge( 5, 6, 2);
   	graph.insert_edge( 6, 7, 1);
   	graph.insert_edge(6, 8, 6);
 	graph.insert_edge( 7, 8, 7);

	//graph.print_map(); 
	PrimMST(&graph);
*/
}
