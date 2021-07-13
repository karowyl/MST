#include <iostream>
#include <fstream>

#include "Dispatcher.hpp"
#include "FileHandler.hpp"
#include "MST.hpp"



using namespace std;

/*
	Uwaga! W pliku input'owym spodziewaymy si� wierzcho�k�w numerowanych >= 1
*/

int main(int argc, char* argv[]) {	

	
	Dispatcher dispatcher{}; // stworz obiekt klasy wypakowujacej parametry
	FileHandler fileHandler{}; // stworz obiekt klasy odpowiedzialnej za operacje na pliku

	try {
		dispatcher.dispatchParameters(argc, argv); // spr�buj wypakowa� parametry podane przy wywo�aniu
	}
	catch (std::invalid_argument e) { // z�ap wyj�tek, je�li nie powi�d� si� proces odczytu parametr�w
		cout << e.what();
		return 0;
	}

	try { // spr�buj otworzy� �cie�k� do podanego pliku do odczytu
		fileHandler.setInputSource(dispatcher.getInputParam());
	}
	catch (std::runtime_error e) {
		cout << e.what();
		return 0;
	}

	fileHandler.setOutputFileName(dispatcher.getOutputParam()); // ustaw �cie�k� pliku do odczytu

	priority_queue<Edge> prioQueue = fileHandler.readQueueFromFile(); // pobierz kolejk� priorytetow� wszystkich kraw�dzi ustawionych wg wag (from min to max)

	// Poni�ej operacje konieczne do wywo�ania algorytmu MST
	MST mstAlgorithm{fileHandler.getNoVerticesInFile()};
	mstAlgorithm.setPrioQueue(prioQueue);
	
	mstAlgorithm.createSets();
	mstAlgorithm.findMST();
	fileHandler.saveToFile(mstAlgorithm.getOutputTree());

}