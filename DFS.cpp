#include "graph.h"

int main(){

	AdjList_Graph graph(6);
	graph.insert_edge(0,1,1);
	graph.insert_edge(1,0,1);

	graph.insert_edge(0,2,1);
	graph.insert_edge(2,0,1);

	graph.insert_edge(1,3,1);
	graph.insert_edge(3,1,1);

	graph.insert_edge(1,4,1);
	graph.insert_edge(4,1,1);

	graph.insert_edge(3,5,1);
	graph.insert_edge(5,3,1);

	graph.insert_edge(2,4,1);
	graph.insert_edge(4,2,1);

	graph.insert_edge(3,4,1);
	graph.insert_edge(4,3,1);

	graph.insert_edge(4,5,1);
	graph.insert_edge(5,4,1);

	graph.DFS(0);


}
