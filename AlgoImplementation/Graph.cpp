#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <cassert>
#include "Graph.h"

using namespace std;

Graph::Graph(int n) :
		size(n), adjMatrix(0) {
	adjMatrix = new vector<int> [size];
}

Graph::Graph(int n, vector<pair<int, int>>& edges) :
		size(n), adjMatrix(0) {
	adjMatrix = new vector<int> [size];
	//iterate through edges and get pair
	for (std::vector<pair<int, int>>::iterator it = edges.begin();
			it != edges.end(); ++it) {
		int u = (*it).first;
		int v = (*it).second;
		//assert(u < size && v < size);
		adjMatrix[u].push_back(v);
		adjMatrix[v].push_back(u);
	}
}

Graph::~Graph() {
	delete[] adjMatrix;
}

vector<int>* Graph::DFS(int node) {
	stack<int> s;
	vector<int>* component = new vector<int>;
	bool explored[size];
	for (int i = 0; i < size; i++) {
		explored[i] = false;
	}
	s.push(node);
	while (!s.empty()) {
		int current = s.top();
		s.pop();
		//explored[current];
		if (!explored[current]) {
			explored[current] = true;
			component->push_back(current);
			for (std::vector<int>::iterator it = adjMatrix[current].begin();
					it != adjMatrix[current].end(); ++it) {
				s.push(*it);
			}
		}
	}
	return component;
}

vector<int>* Graph::BFS(int node) {
	queue<int> q;
	vector<int>* component = new vector<int>;
	bool discovered[size];
	for (int i = 0; i < size; i++) {
		discovered[i] = false;
	}
	discovered[node] = true;
	q.push(node);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		component->push_back(u);
		for (std::vector<int>::iterator it = adjMatrix[u].begin();
				it != adjMatrix[u].end(); ++it) {
			if (!discovered[*it]) {
				discovered[*it] = true;
				q.push(*it);
			}
		}
	}
	return component;

}

vector<vector<int>> * connectedComponent() {	/*
	bool connected[size];
	for (int i = 0; i < size; i++) {
		connected[i] = false;
	}*/

	return 0;
}
