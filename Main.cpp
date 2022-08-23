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
	tre.testAll();

	std::vector<int> foo;
	foo.push_back(1);
	foo.push_back(2);
	foo.push_back(3);

	TestHistogram th(foo, 2);
	th.testNormalize();
	th.testParseData();
	th.testFillBins();
	return 0;
}
