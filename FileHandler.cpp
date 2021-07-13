#include "FileHandler.hpp"

FileHandler::~FileHandler() {
	if (inputSource_.is_open()) inputSource_.close();
}

size_t FileHandler::getNoVerticesInFile() {
	return verticesFromFile_.size();
}

void FileHandler::setInputSource(const char* src) {
	inputSource_.open(src);

	if (!inputSource_.good())
	{
		throw runtime_error("Could not open the file!");
	}
}

void FileHandler::setOutputFileName(const char* src) {
	outputFileName_ = src;
}


priority_queue<Edge> FileHandler::readQueueFromFile() {
	priority_queue <Edge> outputQueue{};

	if (!inputSource_.good()) throw runtime_error("Could not open the file!");

	string buffer{};
	vector<float> numbersFromFile;

	while (inputSource_ >> buffer) {
		std::replace(buffer.begin(), buffer.end(), ',', ' ');
		std::replace(buffer.begin(), buffer.end(), ')', ' ');
		std::replace(buffer.begin(), buffer.end(), '(', ' ');

		numbersFromFile.push_back(std::stof(buffer)); //stof pobiera pierwszy nie bia³y znak
	}
	
	for (int i = 0; i < numbersFromFile.size(); i += 3) {
		float v1 = numbersFromFile.at(i), v2 = numbersFromFile.at(i + 1), weight = numbersFromFile.at(i + 2);

		Edge newEdge{static_cast<int>(v1) - 1, static_cast<int>(v2) - 1, weight};
		
		verticesFromFile_.insert(v1);
		verticesFromFile_.insert(v2);
		
		outputQueue.push(newEdge);
	}
	
	return outputQueue;
}

void FileHandler::saveToFile(string output) const {
	ofstream outputSource{outputFileName_};
	if (!outputSource.good()) throw runtime_error("Could not open the file!");

	outputSource << output << endl;

	cout << "Properly saved content to file: " << outputFileName_ << endl;
	outputSource.close();
}