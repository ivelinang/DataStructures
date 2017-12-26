//*****************************************************************
//  Graph.cpp
//  
//*****************************************************************

#include "Graph.h"
#include <iostream>
#include <set>
#include "Queue.h"

Graph::Graph()
{
	manyVertices = 0;
}

Graph::~Graph()
{}

int Graph::size() const
{
	return manyVertices;
}

void Graph::addVertex(const std::string value)
{

	//assert(size() < MAXMIMUM);
	int newVertexNumber = manyVertices;
	manyVertices++;

	for (int otherVertexNumber = 0; otherVertexNumber < manyVertices; otherVertexNumber++)
	{	
		//default to zero, or -1, i.e no connection
		adjacencyMatrix[otherVertexNumber][newVertexNumber] = 0;
		adjacencyMatrix[newVertexNumber][otherVertexNumber] = 0;
	}
	//assign the label
	Labels[newVertexNumber] = value;

}

void Graph::addEdge(int src, int target)
{	
	//assign the matrix cell to be 1, i.e. there is a connection
	adjacencyMatrix[src][target] = 1;
}

bool Graph::isEdge(int src, int target) const
{
	bool isEdge = false;
	int isAnEdge = adjacencyMatrix[src][target];

	return isEdge;
}

std::string& Graph::operator[](int vertex)
{
	return Labels[vertex];
}

std::string Graph::operator[](int vertex) const
{
	return Labels[vertex];
}

std::set<int> Graph::neighbours(int vertex) const
{
	std::set<int> vertexNeighbours;
	for (int index = 0; index < size(); index++)
	{
		if (adjacencyMatrix[vertex][index]!=0)
		{
			vertexNeighbours.insert(index);
		}
				
	}

	return vertexNeighbours;
}

void Graph::removeEdge(int src, int target)
{
	adjacencyMatrix[src][target] = 0;
}

void Graph::dft(int i, bool visited[])
{
	visited[i] = true; //we are visiting it
	std::cout << "visited: " << i << "\n";
	std::set<int> nb = neighbours(i);
	for (auto iter = nb.begin(); iter!= nb.end(); ++iter)
	{
		int w = *iter;
		// if neighbour not visited, visit it
		if (!visited[w])
		{
			dft(w, visited);
		}
	}

}

void Graph::depthFirstTraversal()
{
	bool *visited; //pointer to array of visited
	visited = new bool[size()];
	for (int index = 0; index < size(); index++)
		visited[index] = false;

	for (int index = 0; index < size(); index++)
	{
		if (!visited[index])
			dft(index, visited);
	}
	delete[] visited;


}

void Graph::breadthFirstTraversal()
{
	Queue<int> queue;
	bool* visited;
	visited = new bool[size()];
	for (int index = 0; index < size(); index++)
		visited[index] = false;
	for (int index = 0; index < size(); index++)
	{
		if (!visited[index])
		{
			queue.add(index); //add the index
			visited[index] = true;
			std::cout << "visited: " << index << "\n";
			while (!queue.isEmpty())
			{
				int u = queue.pop(); //get first element + remove it from queue
				std::set<int> nb = neighbours(u); //get the neighbours of this node
				for (auto iter = nb.begin(); iter != nb.end(); ++iter)
				{
					int w = *iter;
					// if neighbour not visited, visit it
					if (!visited[w])
					{
						queue.add(w);
						visited[w] = true;
						std::cout << "visited: " << w << "\n";
					}
				}
			}
		}
	}

}
