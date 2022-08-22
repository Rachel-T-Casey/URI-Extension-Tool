#include "RequestExtension.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main(int argc, char const *argv[])
{

	for(int i = 1; i < 16; i++)
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
		std::vector<int> data;
		data = h.binData();
		for(int n = 0; n < data.size(); n++)
		{
			std::cout << data[n] << std::endl;
		}
	}
	
}
