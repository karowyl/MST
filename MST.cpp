#include "MST.hpp"

MST::MST(unsigned int noVertices) : noVertices_{ noVertices }, disjointSets_{ noVertices }, msTree{noVertices}{}

void MST::setPrioQueue(priority_queue<Edge> queue) { // zapamiêtuje odczytan¹ kolejkê priorytetow¹
	prioQueue_ = queue;
}

void MST::createSets() { // tworzy tyle zbiorów, ile jest wierzcho³ków
	for (int i = 0; i < noVertices_; ++i) {
		disjointSets_.makeSet(i);
	}
}

void MST::findMST() { // wyszukuje MST
	for (int i = 0; i < noVertices_ - 1; ++i) {
		Edge edge;
		do { // wykonuj dopoki nie znajdzie wierzcholka nalezacego do innego zbioru	
			edge = prioQueue_.top();
			prioQueue_.pop();
		} while (disjointSets_.findSet(edge.v1_) == disjointSets_.findSet(edge.v2_));
	
		// po znalezieniu niezaleznego wierzcholka, dolacz go do mst
		msTree.addEdge(edge);
		disjointSets_.unionSets(edge);
	}
}

string MST::getOutputTree() { // pobiera reprezentacje string drzewa MST
	return msTree.get();
}