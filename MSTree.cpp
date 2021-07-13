#include "MSTree.hpp"

MSTree::MSTree(unsigned int noVertices) : noElements_{ noVertices }
{
	listOfNodes_ = new TNode * [noVertices] {};
}

MSTree::~MSTree()
{
	for (int i = 0; i < noElements_; ++i) { // usun wszystkie nodes z drzewa MST z listy s¹siedztwa 
		TNode* curr = listOfNodes_[i];
		TNode* prev;

		while (curr) { // usuwa node
			prev = curr;
			curr = curr->next;
			delete prev;
		}

	}
	delete[] listOfNodes_; // i na koniec cala liste sasiedztwa
}

void MSTree::addEdge(Edge e) // dodaje do listy s¹siedztwa now¹ krawêdŸ
{
	treeWeight_ += e.weight_;
	TNode* newNode = new TNode{};
	newNode->v = e.v2_;
	newNode->weight = e.weight_;
	newNode->next = listOfNodes_[e.v1_];
	listOfNodes_[e.v1_] = newNode;
}

string MSTree::get() const { // Zwraca output programu w postaci string
	string output{};

	for (int i = 0; i < noElements_; ++i) {
		TNode* curr = listOfNodes_[i];
		
		while (curr) {
			output += "(" + std::to_string(i + 1) + ", " + std::to_string(curr->v + 1) + ", " + std::to_string(curr->weight) + "), ";
			
			curr = curr->next;
		}
	}

	return output.substr(0, output.size() - 2); // substr aby usunac na koncu ,
}
