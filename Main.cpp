#include "RequestExtension.hpp"

#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char const *argv[])
{
	RequestExtension R(3);
	for(int i = 0; i < 1000; i++)
	{
		std::cout << "Enter a uri:" << std::endl;
		std::string uri;
		std::cin >> uri;
		R.process(uri);
		int meanValue = R.mean(uri);
		std::cout << "Mean: " << meanValue << std::endl;

	}
	return 0;
}