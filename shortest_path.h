
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


	minheap->print_minheap();

	//HeapNode *src_node = new HeapNode(list[src], 0);

	
		
	
	// Iterate through the vertices...



}



