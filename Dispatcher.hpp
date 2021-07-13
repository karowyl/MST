#pragma once
#include <iostream>
using namespace std;


/** Class for reading parameters from the console line.*/
class Dispatcher
{
public:
	/** Method that reads the entered parameters 
	@param argc parameter represents the number of command line arguments
	@param argv[] an array of strings representing the individual arguments provided on the command line*/
	void dispatchParameters(int argc, char* argv[]);
	/** Method get the first word in a pair (input path)
	@return input path*/
	const char* getInputParam() const;
	/**Method get the second word in a pair(output path)
	@return output path*/
	const char* getOutputParam() const;

private:
	/* Returns coordinate with the parameters
	@return coordinate with the parameters*/
	pair<const char*, const char*> parameters;
};

