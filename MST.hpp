#pragma once
#include <queue>
#include "Edge.hpp"
#include "DSStruct.hpp"
#include "MSTree.hpp"

using namespace std;
/**The class needed for creating minimal spanning tree and other related operations.*/
class MST
{
public:
	/**Constructor for MST
	@param noVertices number of vertices*/
	explicit MST(unsigned int noVertices);
	/**The method saves the priority queue to the class
	@param queue priority queue*/
	void setPrioQueue(priority_queue<Edge> queue);
	/**The method creates as many sets as there are vertices*/
	void createSets();
	/**The method finds the minimal spanning tree*/
	void findMST();
	/**Gets the string representations of an MST tree
	@return  minimal spanning tree*/
	string getOutputTree();
	
private:
	size_t noVertices_; ///< number of vertices

	MSTree msTree; ///< tree representation
	priority_queue<Edge> prioQueue_; ///< priority queue
	DSStruct disjointSets_; ///< set representation
};

