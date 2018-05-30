

/*

Insert edges into the adjacency list...


Can i implement one of the graph algorithms using my Graph class?



Do BFS and DFS on each of the implementations... write code to transition from one representation to another.. 





*/


#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

#define adj_V 5

struct Edge{

	int src, dest ,weight;
	Edge* edge;

	Edge():src(0),dest(0),weight(0){}
	Edge(int s, int d, int w):src(s), dest(d), weight(w){}
	
	friend std::ostream & operator << (std::ostream &out, const Edge &h);
	

};


std::ostream & operator << (std::ostream &out, const Edge &h)
{
    	out << "The edge between " << h.src << " and " << h.dest << "with a weight of " << h.weight;

    	return out;
}


/*

The basic implementation of a graph simply uses a set of edges


*/
class Graph{

  	Edge* edge;
	int edge_count;
  public:
	int NumVertices,E;
	Graph(int V_, int E_):NumVertices(V_), E(E_){
		edge = new Edge[E];
		edge_count =0;
	}
	void insert_edge(int s, int d, int w){
		
		edge[edge_count].src = s;
		edge[edge_count].dest = d;
		edge[edge_count].weight = w;
		edge_count++;	
	}

	int get_src(int j){
		return edge[j].src;
	}

	int get_dest(int j){
		return edge[j].dest;
	}

	int get_weight(int j){
		return edge[j].weight;
	}

	void print(){
		for(int i =0; i < edge_count; i++){

			std::cout << edge[i] << std::endl;
		}
	}

	void topoligicalSortUtil(int v, bool visited[], std::stack<int> &Stack);
	void topoligicalSort();

	

};


class GraphNode{
  public:
	struct AdjListNode{
		int dest;
		int weight;
		AdjListNode(int dest_, int weight_):dest(dest_), weight(weight_){}
	};

	std::vector<AdjListNode> adjList;
	
	int id;
	GraphNode(int id_):id(id_){}
	GraphNode(){}
	void print_adjlist(){
		if (adjList.size() == 0)
			std::cout << " NULL" << std::endl; 

		for(int i= 0; i < adjList.size(); i++){

			std::cout << adjList[i].dest << "   with weight: " << adjList[i].weight <<std::endl;
		}
	}

	std::vector<AdjListNode> return_adjlist(){
		return adjList;

	}

	void insert(int k){
		AdjListNode adj_node(k , 1);
		adjList.push_back(adj_node);
	}

	/*
	Overload insert for weighted graphs.  

	*/

	void insert(int k, int w){
		AdjListNode adj_node(k , w);
		adjList.push_back(adj_node);
	}


};



class AdjList_Graph{

	int V;
	std::unordered_map<int, GraphNode*> nodeList;
	int edge_count;
  public:

	AdjList_Graph(int V_) : V(V_){
		for(int i =0; i < V_ ; i++){
			nodeList[i] = new GraphNode(i);
		}

		edge_count = 0;
	}
	int getV(){
		return V;
	}

	GraphNode* get_Node(int k){
		return nodeList[k] ;
	}
	std::unordered_map<int, GraphNode*> &return_nodelist(){
		return nodeList;
	}
	int number_of_edges(){
		return edge_count;
	}

	

	void print(){
		GraphNode current_node;
		for (auto it: nodeList){
			current_node = *(it.second);
			std::cout << "node id: " << current_node.id << " adjacency list: " <<std::endl;
			current_node.print_adjlist();
		//	std::cout << "node id: "  << it.first;
		}

	}


	void insert_edge(int first_vertex, int second_vertex, int w){
		
		// Get pointers to respective nodes

		GraphNode *node1 = nodeList[first_vertex];
		GraphNode *node2 = nodeList[second_vertex];
		node1->insert(second_vertex, w);
		edge_count++;
	}



	/*

Here is implementation of depth first search


	*/
	
	// Recursive util;ity function... 
	void DFS_Util(int v, bool visited[]){
		visited[v] = true;
		std::cout << v <<  " ";

		// Recur for all vertices adjacent to this vertex.
		GraphNode* node =nodeList[v];
		std::vector<GraphNode::AdjListNode> list = node->return_adjlist(); 
		for(int i =0; i < list.size(); i++){
			if(!visited[list[i].dest]){
				DFS_Util(list[i].dest, visited);
			}
		}

	}

	void DFS(int v){
		bool *visited = new bool[V];
		for(int i =0; i < V; i++){
			visited[i] = false;
		}
		DFS_Util(v, visited);


	}

	void BFS(){

	}


	

	/*


	Here is the implementation of DFS on the graph...

	my implementation seems convoluted as hell...

	*/

	void BFS(int s){

		bool *visited = new bool[V];

		for(int i=0; i < V; i++)
			visited[i] = false;
		visited[s] = true;

		std::list<GraphNode*> queue;
		// Mark the current node as visited and enqueue it

		queue.push_back(get_Node(s));

		GraphNode *current_node = queue.front();	

		std::vector<GraphNode::AdjListNode> list;

		

		while(!queue.empty()){

			current_node = queue.front();
			list= current_node->return_adjlist();
			//std::cout << "I am node" << current_node->id <<std::endl;
			for(int i = 0; i < list.size(); i++){
				
			}
			queue.pop_front();

			// We will loop through all the adjacent vertices of the dequeued vertex 

			for(int i = 0; i < list.size(); i++){
				//std::cout << "Has this been" << list[i].dest << std::endl;

			//	std::cout << "I am node " << current_node->id << " and I am adjacent to " << list[i].dest << std::endl;
				if(!visited[list[i].dest]){
					visited[list[i].dest] = true;
					queue.push_back(nodeList[list[i].dest]);
					std::cout << " I am getting queued " << list[i].dest << std::endl;


	
				}
						
			}
		
	
			//std::cout << li << " ";
			//queue.pop_front();
			//std::cout << "the size of" << *(nodeList[i])->
// nodeList is the unordered map
			//for(int i =0; i < nodeList[i].size(); i++){


			//}
		}
		



	}



};

/*

Worry about templating the Nodes in the graph later...


do BFS... DFS...


Write a function that will 




*/



class AdjMatrix_Graph{
  private:

	int numVertices;

  public:
	int **adjMatrix;
	AdjMatrix_Graph(int numVertices_){

		this->numVertices = numVertices_;
		adjMatrix = new int*[numVertices];
		for(int i=0; i < numVertices; i++){
			adjMatrix[i] = new int[numVertices];
			for(int j=0; j < numVertices; j++)
				adjMatrix[i][j] = 0;
		}
	}

	AdjMatrix_Graph(int **input_array, int V):adjMatrix(input_array), numVertices(V){
	
		


	}


	void construct_from_array(int** input_array){
		
	}
	


	int get_numVertices(){

		return numVertices;
	}

	void print(){
		for(int i =0; i < numVertices; i++){
			
			for(int j=0; j < numVertices; j++){
				std::cout << adjMatrix[i][j] << " ";
			}
			std::cout << std::endl;
		}

		
	}

	void addEdge(int i, int j, int w){
		adjMatrix[i][j] = w;
		adjMatrix[j][i] = w;
	}
	

	void removeEdge(int i, int j){
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
	}

	~AdjMatrix_Graph(){
		for(int i=0; i< numVertices; i++)
			delete[] adjMatrix[i];
	}



};





#endif
