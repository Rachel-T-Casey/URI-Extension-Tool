#include "RequestExtension.hpp"
#include "testRequestExtension.hpp"
#include "testHistogram.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

int main(int argc, char const *argv[])
{
	
	TestRequestExtension tre(10);
	tre.testMean();
	tre.testMatches();
	tre.testSD();
	tre.testSumURIResponseTimes();
	tre.testGetHistogram();

	return 0;
}
