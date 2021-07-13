#pragma once
#include "Edge.hpp"
#include "DSSet.hpp"
/**Class representing sets*/
class DSStruct
{
public:
	/*Constructor for DSStruct
	@param no_sets number of sets*/
	DSStruct(int no_sets);
	/*Destructor for DSStruct*/
	~DSStruct();
	/**Function creates a tree-like set (each node relates to a successor)
	@param value value of node*/
	void makeSet(int value);
	/**The method recursively finds a representative 
	@param v vertex
	@return top vertex of the set*/
	int findSet(int v);
	/**The method connects sets (examines the rank), pins to a set of greater rank
	@param e edge connecting two sets */
	void unionSets(Edge e);

private:
	DSSet* sets; ///< List of sets
};

