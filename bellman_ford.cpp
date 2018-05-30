
#include "shortest_path.h"


int main(){

	Graph graph(5, 8);

	graph.insert_edge(0,1,-1);
	graph.insert_edge(0,2,4);
	graph.insert_edge(1,2,3);
	graph.insert_edge(1,3,2);
	graph.insert_edge(1,4,2);
	graph.insert_edge(3,2,5);
	graph.insert_edge(3,1,1);
	graph.insert_edge(4,3,-3);
	//graph.print();
	//BellmanFord(&graph, 0);


	AdjList_Graph list_graph(5);

	list_graph.insert_edge(0,1,-1);
	list_graph.insert_edge(0,2,5);
	list_graph.insert_edge(1,2,3);
	list_graph.insert_edge(1,3,2);
	list_graph.insert_edge(1,4,2);
	list_graph.insert_edge(3,2,5);
	list_graph.insert_edge(3,1,1);
	list_graph.insert_edge(4,3,-3);

	BellmanFord_List(&list_graph, 0);
	
}
