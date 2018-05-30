
/*

This file implements the shortest path algorithms



*/




/*

Dijstra's algorithm is very similar to Prim's algorithm for MST.  Like Prim, we generate a SPT (shortest path tree) with given source as root.  We maintain two sets, one set contains vertices included in shortest path tree, other sdet includes vertices not yet included in shortst path tree. 

1) Initiailize an empty set sptSet that keeps track of vetices included in shortest path tree, i.e, whose minimum distance from source is calculated and finalized.

2) Assign a distance value to all vertices in the input graph.  Initialize all distances values as INFINITE.  


*/

#include "graph.h"
#include <limits.h>
#include "heap.h"
#include <unordered_map>
#include <iostream>
#define V 4

// utility function tind the index of the vertex with the minimum distance.. from the set of vertices not yet included in the shortest path tree
// 
int minDistance(int dist[], bool sptSet[], int V_){


	int min = INT_MAX;
	int min_index;

	for(int v =0; v < V_; v++){
		if(sptSet[v] == false && dist[v] <= min)
			min = dist[v];
			min_index =v; 
	}

	return min_index;

}

int printSolution(int dist[], int n){

	std::cout << "Vertex    Distance from Source\n";
	for(int v = 0; v<V; v++){
		std::cout << v << " tt " << dist[v]<<std::endl;
	}
}









void adjmatrix_dijikstra(int graph[V][V], int src){
	
	
	int dist[V];
	bool sptSet[V]; // sptSet[i] will be true if vertex i is in the shortest path tree

	//int **adj_mat = graph->adjMatrix;

	for(int i =0; i < V; i++){
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0

	dist[src] = 0;
	std::cout << "I am the source: " << src <<std::endl;
	for(int count =0; count < V-1; count ++){
		int u = minDistance(dist, sptSet, V);
		std::cout << "The minimum distance index u: " << u << std::endl;
		sptSet[u] = true;

		for(int v=0; v < V; v++){

			// update dist[v] only if it is not in sptSet, there is an edge from u to v, and total weight of path from src to v  through u is smaller than the current value of dist[v]

			std::cout << "inside the first loop " << std::endl;
			if(!sptSet[v] && graph[u][v] && dist [u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				std::cout << "inside the second loop " << std::endl;
				dist[v] = dist[u]+graph[u][v];

		}
	}	
	printSolution(dist, V);
}


class HeapNode{
	int v;
	int dist;
  public:
	HeapNode(int v_, int dist_):v(v_), dist(dist_){}
	HeapNode(){
		v=0;
		dist = INT_MAX;
	}

	HeapNode(int c){

	}
	

	void decreaseDist(MinHeap<HeapNode> *heap, int v, int dist){

		int index = heap->pos;

	}

	bool operator <(const HeapNode &h2){
		return this->dist < h2.dist;
	}

	friend std::ostream & operator << (std::ostream &out, const HeapNode &h);
	

};


std::ostream & operator << (std::ostream &out, const HeapNode &h)
{
    	out << "v: " << h.v;
    	out << " distance " << h.dist << std::endl;
    	return out;
}



void adjlist_dijikstra(AdjList_Graph *graph, int src){
	
	int numVertices = graph->getV();

	MinHeap<HeapNode> *minheap = new MinHeap<HeapNode>(numVertices);
	
	GraphNode current_node;
	std::unordered_map<int, GraphNode*> list = graph->return_nodelist();
	for(auto it:list){
		current_node = *(it.second);
		std::cout << "node id: " << current_node.id << " adjacency list: " <<std::endl;
		current_node.print_adjlist();

	
		if (current_node.id == src){
			HeapNode *new_node = new HeapNode(current_node.id,0);
			minheap->insert(*new_node);

		}else{

			HeapNode *new_node = new HeapNode(current_node.id,INT_MAX);
			minheap->insert(*new_node);
		}
	
		
	}

	int size = minheap->getsize();
	std::cout << "The size of the minheap is " << size << std::endl;
	HeapNode min_node = minheap->delete_min();
	min_node = minheap->delete_min();
	std::cout << "The minimum element is " << min_node << std::endl;

	minheap->print_minheap();

	HeapNode *src_node = new HeapNode(src, 0);

	
	//minheap->decreaseKey(src,dist[src]);		

	
	// Iterate through the vertices...

}

void printArr(int dist[], int n){

	for(int i =0; i < n; ++i){

		std::cout << "Vertex Distance from source " << std::endl;
		std::cout << i << "\t\t" << dist[i] << std::endl;
	}

}


/*

We have implemented BellmanFord for our basic Graph implementation, which is simply a set of edges..



*/


void BellmanFord(Graph *graph, int src){
	int numvertices = graph->NumVertices;
	int numedges = graph->E;

	int dist[numvertices];

	// Initialize distances from src to all other vertices as INFINITE

	for(int i=0; i < numvertices; i++){
		dist[i] = INT_MAX;
	}
	dist[src] = 0;

	for(int i =1; i < numvertices -1; i++){
		for(int j =0; j < numedges; j++){
			int u = graph->get_src(j);
			int v = graph->get_dest(j);
			int weight = graph->get_weight(j);
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}


	// Step 3:  Check for negative-weight cycles.  The above step guarantees shortest distances if graph doesn't contain negative weight cycles.  If we get a shorter path, then there is 		// a cycle

	for(int j =0; j < numedges; j++){
		int u = graph->get_src(j);
		int v = graph->get_dest(j);
		int weight = graph->get_weight(j);
		if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("graph contains negative weight cycle\n");

	}

	printArr(dist, numvertices);
	
}

/*

This looks a little bit convoluted....

We are going to loop through all of the vertices... and within this loop we will loop 



*/

void BellmanFord_List(AdjList_Graph *graph, int src){

	int numVertices = graph->getV();
	int E = graph->number_of_edges();
	int dist[numVertices];

	std::cout << "The number of edges for this graph is : " <<E << std::endl;
	//for(int i =0; i < numVertices ; i ++){

	//}


}
	





