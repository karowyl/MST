#include "DSStruct.hpp"
#include "DSStruct.hpp"

DSStruct::DSStruct(int no_sets) : sets {new DSSet[no_sets]}
{
}

DSStruct::~DSStruct()
{
	delete[] sets;
}

void DSStruct::makeSet(int value) // tworzy zbiór w postaci drzewa (ka¿dy wierzcho³ek odwo³uje siê do nastêpcy)
{
	sets[value].up = value; // na pocz¹tku tworzony jest cykl - górny wierzcho³ek (reprezentant) wskazuje na samego siebie
	sets[value].rank = 0; // ranga wierzcho³ka wykorzystywana przy przypiêciu do innego zbioru
}

int DSStruct::findSet(int v) // rekurencyjnie znajduje reprezentanta (górny wierzcho³ek zbioru)
{
	if (sets[v].up != v) sets[v].up = findSet(sets[v].up);
	return sets[v].up;
}

void DSStruct::unionSets(Edge e) // ³¹czy zbiory (rozpatruje rangê), przypina do zbioru o wiêkszej randze
{
	int parentV1 = findSet(e.v1_), parentV2 = findSet(e.v2_);

	if (parentV1 != parentV2 && sets[parentV1].rank > sets[parentV2].rank) {
		sets[parentV2].up = parentV1;
	}
	else if (parentV1 != parentV2 && sets[parentV1].rank <= sets[parentV2].rank) {
		sets[parentV1].up = parentV2;
		if (sets[parentV1].rank == sets[parentV2].rank) ++sets[parentV2].rank;
	}
}
