#pragma once
/**The structure creates a new list with edges*/
struct Edge
{	
	int v1_, ///< v1_ first vertex
		v2_; ///< v2_ second vertex

	float weight_; ///< weight of conection two vertices
	/*Constructor for Edge  (default)*/
	explicit Edge() = default;
	/*Constructor for Edge
	@param v1 first vertex
	@param v2 second vertex
	@param weight weight of conection two vertices*/
	explicit Edge(int v1, int v2, float weight) : v1_{ v1 }, v2_{ v2 }, weight_{ weight } {}
	/**The comparison operator used in creation priorityQueue
	@param edge2 second edge of comparison
	@return true or false*/
	bool operator<(const Edge& edge2) const { // operator porównania wykorzystywany przy tworzeniu priorityQueue
		return weight_ > edge2.weight_;
	}
};
