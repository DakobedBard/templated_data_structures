#include "graph.h"
#include <stack>
#include <list>
/*

Implement topological sort

Do it with the regular graph representation first


*/


void Graph::topoligicalSortUtil(int v, bool visited[], std::stack<int> &Stack){
	visited[v]  = true;
	// Recur for all the vertices adjacent to this vertex..
	std::list<int>::iterator i;
}


void Graph::topoligicalSort(){

	std::stack<int> Stack;

	bool *visited = new bool[NumVertices];
	for(int i=0; i < NumVertices; i++)
		visited[i] = false;
	for(int j=0; j < NumVertices; j++)
	{
		if(visited[j] == false){
			topoligicalSortUtil(j , visited, Stack);
		}
	}
	while(Stack.empty() == false){

		std::cout << Stack.top() << " ";
		Stack.pop();
	}

	

}

int main(){
	Graph graph(6,12);


	graph.insert_edge(0,4,1);
	graph.insert_edge(4,0,1);
	
	graph.insert_edge(0,5,1);
	graph.insert_edge(5,0,1);

	graph.insert_edge(5,2,1);
	graph.insert_edge(2,5,1);

	graph.insert_edge(2,3,1);
	graph.insert_edge(3,2,1);

	graph.insert_edge(3,1,1);
	graph.insert_edge(1,3,1);

	graph.insert_edge(4,1,1);
	graph.insert_edge(1,4,1);
	graph.print();

}
