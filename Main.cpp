#include "RequestExtension.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
int main(int argc, char const *argv[])
{

	for(int i = 2; i < 10; i++)
	{
		std::cout << "Number of bins: " << i << std::endl;
		std::ifstream input;
		input.open("data.txt");
		RequestExtension r(i);
		while(input.good())
		{
			std::string uri;
			std::getline(input, uri);
			r.process(uri);
		}
		input.close();
		Histogram h = r.getHistogram();
		std::vector<double> data;
		data = h.binData();
		for(int n = 0; n < data.size(); n++)
		{
			std::cout << std::fixed;
			std::cout << std::setprecision(2) << data[n] << std::endl;
		}
	}
	
}
