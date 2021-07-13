#include "DSStruct.hpp"
#include "DSStruct.hpp"

DSStruct::DSStruct(int no_sets) : sets {new DSSet[no_sets]}
{
}

DSStruct::~DSStruct()
{
	delete[] sets;
}

void DSStruct::makeSet(int value) // tworzy zbi�r w postaci drzewa (ka�dy wierzcho�ek odwo�uje si� do nast�pcy)
{
	sets[value].up = value; // na pocz�tku tworzony jest cykl - g�rny wierzcho�ek (reprezentant) wskazuje na samego siebie
	sets[value].rank = 0; // ranga wierzcho�ka wykorzystywana przy przypi�ciu do innego zbioru
}

int DSStruct::findSet(int v) // rekurencyjnie znajduje reprezentanta (g�rny wierzcho�ek zbioru)
{
	if (sets[v].up != v) sets[v].up = findSet(sets[v].up);
	return sets[v].up;
}

void DSStruct::unionSets(Edge e) // ��czy zbiory (rozpatruje rang�), przypina do zbioru o wi�kszej randze
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
