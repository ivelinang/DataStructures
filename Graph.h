#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>

//using namespace std;

class Graph
{
private:
	//max size of matrix
	static const int MAXMIMUM = 20;
	//matrix to hold the weights/distance between nodes
	int adjacencyMatrix[MAXMIMUM][MAXMIMUM];
	//array to hold the names of the nodes
	std::string Labels[MAXMIMUM];
	int manyVertices;

public:
	Graph();
	~Graph();

	void addVertex(const std::string value);
	void addEdge(int src, int target);
	void removeEdge(int src, int target);
	std::string& operator [] (int vertex); //reference to the value
	std::string operator [] (int vertex) const; //copy of the value
	int size() const;
	bool isEdge(int src, int target) const;
	std::set<int> neighbours(int vertex) const;
	void dft(int i, bool visited[]);
	void depthFirstTraversal();
	void breadthFirstTraversal();


};


#endif // !GRAPH_H

