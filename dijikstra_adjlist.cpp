

#include "graph.h"
#include "shortest_path.h"

int main(){
	
	AdjList_Graph graph(9);

	

	graph.insert_edge(0, 1,4);
	graph.insert_edge(1, 0,4);

	graph.insert_edge(0, 7,8);
	graph.insert_edge(7, 0,8);

	graph.insert_edge(1, 2,8);
	graph.insert_edge(2, 1,8);

	graph.insert_edge(1, 7,11);
	graph.insert_edge(7, 1,11);

	graph.insert_edge(2, 3,7);
	graph.insert_edge(3, 2,7);

	graph.insert_edge(2, 8,2);
	graph.insert_edge(8, 2,2);

	graph.insert_edge(2, 5,4);
	graph.insert_edge(5, 2,4);

	graph.insert_edge(3, 4,9);
	graph.insert_edge(4, 3,9);

	graph.insert_edge(3, 5,14);
	graph.insert_edge(5, 3,14);

	graph.insert_edge(4, 5,10);
	graph.insert_edge(5, 4,10);



	graph.insert_edge(5, 6,2);
	graph.insert_edge(6, 5,2);


	graph.insert_edge(6, 7,1);
	graph.insert_edge(7, 6,1);

	graph.insert_edge(6, 8,6);
	graph.insert_edge(8, 6,6);

	graph.insert_edge(7, 8,7);
	graph.insert_edge(8, 7,7);


	adjlist_dijikstra(&graph, 0);

	//graph.print();



}
