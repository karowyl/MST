#include <iostream>
#include <fstream>

#include "Dispatcher.hpp"
#include "FileHandler.hpp"
#include "MST.hpp"



using namespace std;

/*
	Uwaga! W pliku input'owym spodziewaymy siê wierzcho³ków numerowanych >= 1
*/

int main(int argc, char* argv[]) {	

	
	Dispatcher dispatcher{}; // stworz obiekt klasy wypakowujacej parametry
	FileHandler fileHandler{}; // stworz obiekt klasy odpowiedzialnej za operacje na pliku

	try {
		dispatcher.dispatchParameters(argc, argv); // spróbuj wypakowaæ parametry podane przy wywo³aniu
	}
	catch (std::invalid_argument e) { // z³ap wyj¹tek, jeœli nie powiód³ siê proces odczytu parametrów
		cout << e.what();
		return 0;
	}

	try { // spróbuj otworzyæ œcie¿kê do podanego pliku do odczytu
		fileHandler.setInputSource(dispatcher.getInputParam());
	}
	catch (std::runtime_error e) {
		cout << e.what();
		return 0;
	}

	fileHandler.setOutputFileName(dispatcher.getOutputParam()); // ustaw œcie¿kê pliku do odczytu

	priority_queue<Edge> prioQueue = fileHandler.readQueueFromFile(); // pobierz kolejkê priorytetow¹ wszystkich krawêdzi ustawionych wg wag (from min to max)

	// Poni¿ej operacje konieczne do wywo³ania algorytmu MST
	MST mstAlgorithm{fileHandler.getNoVerticesInFile()};
	mstAlgorithm.setPrioQueue(prioQueue);
	
	mstAlgorithm.createSets();
	mstAlgorithm.findMST();
	fileHandler.saveToFile(mstAlgorithm.getOutputTree());

}