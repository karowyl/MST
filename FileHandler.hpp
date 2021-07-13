#pragma once
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include "Edge.hpp"
using namespace std;
/**The class responsible for file operations*/
class FileHandler
{
public:
	/**Constructor for FileHandler (defalut)*/
	explicit FileHandler() = default;
	/**Destructor for FileHandler*/
	~FileHandler();
	/**The method sets input source
	@param src input file's path*/
	void setInputSource(const char* src);
	/**The method sets output file name
	@param src output file's path*/
	void setOutputFileName(const char* src);
	/**The method checks the number of vertices
	@return number of vertices*/
	size_t getNoVerticesInFile();
	/**The method creates priority queue from file
	@return priority queue made of edges from the graph */
	priority_queue<Edge> readQueueFromFile();
	/**The method saves the minimal spaninng tree to the output file
	@param output path to output file*/
	void saveToFile(string output) const;

private:
	
	set<float> verticesFromFile_; ///< set of vertices from file

	string outputFileName_; ///< Output file name
	ifstream inputSource_; ///< Input source
};

