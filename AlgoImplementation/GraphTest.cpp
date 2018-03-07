#include <iostream>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

#include "Graph.h"
using namespace std;

TEST(DFS, Test1) {
	vector<pair<int, int>> edges;
	pair<int, int> p1(3, 4);
	edges.push_back(p1);
	ASSERT_TRUE(0 == 0);
}

TEST(DFS, Test2) {
	vector<pair<int, int>> edges;
	pair<int, int> p1(1, 2);
	pair<int, int> p2(2, 3);
	pair<int, int> p3(1, 3);
	edges.push_back(p1);
	edges.push_back(p2);
	edges.push_back(p3);
	ASSERT_TRUE(0 == 0);
	Graph g(6, edges);
	vector<int>* DFSTest = g.DFS(2);
	ASSERT_EQ(2, DFSTest->front());
	vector<int>* DFS2Test = g.DFS(1);
	ASSERT_EQ(1, DFS2Test->front());
	vector<int>* DFS3Test = g.DFS(3);
	ASSERT_EQ(3, DFS3Test->front());

}

TEST(BFS, Test1) {
	vector<pair<int, int>> edges;
	pair<int, int> p1(3, 4);
	edges.push_back(p1);
	Graph g(6, edges);
	ASSERT_TRUE(0 == 0);
}

TEST(BFS, Test2) {
	vector<pair<int, int>> edges;
	pair<int, int> p1(1, 2);
	pair<int, int> p2(2, 3);
	pair<int, int> p3(1, 3);
	edges.push_back(p1);
	edges.push_back(p2);
	edges.push_back(p3);
	ASSERT_TRUE(0 == 0);
	Graph g(6, edges);
	vector<int>* BFSTest = g.BFS(2);
	ASSERT_EQ(2, BFSTest->front());
	vector<int>* BFS2Test = g.BFS(1);
	ASSERT_EQ(1, BFS2Test->front());
	vector<int>* BFS3Test = g.BFS(3);
	ASSERT_EQ(3, BFS3Test->front());
}

