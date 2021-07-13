#pragma once
#include "TNode.hpp"
#include "Edge.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
/**The class responsible for creating the minimal spanning tree in the output form*/
class MSTree
{
public:
	/**Constructor for MSTree
	@param noVertices number of vertices*/
	explicit MSTree(unsigned int noVertices);
	/**Destructor for MSTree*/
	~MSTree();
	/**The method adds a new edge to the neighborhood list
	@param e new edge*/
	void addEdge(Edge e);
	/**Returns the program's output in the form of a string*/
	string get() const;

private:
	float treeWeight_{0.f};  ///< Tree weight
	unsigned int noElements_; ///< number of elements
	TNode** listOfNodes_; ///< Linked list of nodes
};

