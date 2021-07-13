#include "Dispatcher.hpp"

void Dispatcher::dispatchParameters(int argc, char* argv[]) {
	const char* inputSource{}; 
	const char* outputSource{};

	for (int i = 0; i < argc - 1; ++i) {
		if (strcmp(argv[i], "-i") == 0) {
			inputSource = argv[i + 1]; // Pobierz argument wystêpuj¹cy po -i
		}
		else if (strcmp(argv[i], "-o") == 0) { // Pobierz argument wystêpuj¹cy po -o
			outputSource = argv[i + 1];
		}
	}

	if (!inputSource || !outputSource) throw std::invalid_argument("Program called with invalid arguments!"); // rzuæ wyj¹tek, je¿eli nie odczytano oczekiwanych parametrów

	parameters = make_pair(inputSource, outputSource); // odczytane parametry przechowuj w formie pary
}

const char* Dispatcher::getInputParam() const {
	return parameters.first; // pobierz pierwszy wyraz z pary (sciezka do inputu)
}

const char* Dispatcher::getOutputParam() const {
	return parameters.second; // pobierz drugi wyraz z pary (sciezka do outputu)
}
