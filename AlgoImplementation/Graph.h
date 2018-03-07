#include <iostream> // std::ostream/istream
#include <utility>  // std::pair
#include <vector>   // vector



#ifndef GRAPH_H
#define GRAPH_H


class Graph {
	std::vector<int>* adjMatrix;
	int size;
public:
	Graph(int n);
	Graph(int n, std::vector<std::pair<int, int>>& edges);
	~Graph();

	std::vector<int>* DFS (int node); //use stack
	std::vector<int>* BFS (int node); //use queue

	std::vector<std::vector<int>>* connectedComponent();
};



#endif //GRAPH_H
