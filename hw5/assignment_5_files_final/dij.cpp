//---------------------------------------------------------------------
// Name:Kishan Patel
// Email: kpp5282@psu.edu
// Class: CMPSC 122, Section 2
// Program 5.1 - 
//
// Description: Is the implemantation for Dijkostras Algorithm
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include "graph.h"
#include "min_heap.h"
#include "set.h"
#include "stack.h"
#include <queue>

using namespace std;

		void Dijkstra(Graph, int source, int target){
		MinHeap Q;
		int V;
		int distance[V], previous[V];
		distance[source] = 0;
		//create min-heap Q
		MinHeap * minHeap = min_heapify(v);
		//for each vertex v in Graph:
		for (int v = 0; v < V; ++v){
		if (v != source)
		distance[v] = 999;
		previous[v] = -1;
		Q.add_with_priority(v, distance[v])
		//end for
		}
		//while Q is not empty:
		while(IsEmpty(Q)){
		int u;
		u = Q.extract_min();
		if (u == target)
		//break out of while
		
		for each neighbor v of u: // only consider v that are still in Q
		alt = distance[u] + length(u, v)
		if alt < distance[v]
		distance[v] = alt
		previous[v] = u
		Q.decrease_priority(v, alt)
		end for
		//end while
		}
		// Determine the shortest path from source to target using previous array
		//create stack S
		u = target
		while previous[u] is defined:
		push u onto S
		u = previous[u]
		push u onto S
		// Output path ordering with distance between each node
		// Output total distance of smallest path from source to target
		//end function

		
int main()
{
	Graph g;
	string path;
	MinHeap h;
	int startingVector, targetVector;

		
	cout << "Please enter location of graph file to load: ";
	cin >> path;

	
	cout << "Please enter the index of the starting vector: ";
	cin >> startingVector;

	
	cout << "Please enter the index of the target vector: ";
	cin >> targetVector;

	cout << "The shortest path from vertex " << startingVector << " to vertex " << targetVector << " is: ";
	g.create_graph(path);
	cout << g.dimension() << endl;
	g.print_adj_matrix();
	return 0;
}
