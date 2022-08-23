#include "RequestExtension.hpp"
#include "testRequestExtension.hpp"
#include "testHistogram.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

void testMode();
void manualMode();
int main(int argc, char const *argv[])
{

	int selection = 0;
	while(selection != 3)
	{
		do {
			std::cout << "1: Enter Manual Mode" << std::endl;
			std::cout << "2. Enter Automatic Test Mode " << std::endl;
			std::cout << "3. Exit Program" << std::endl;
			std::cin >> selection;
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}	while(selection < 1 || selection > 3);
	if(selection == 1)
		manualMode();
	if(selection == 2)
		testMode();
	}
	TestRequestExtension tre(10);


	std::vector<int> foo;
	
	return 0;
}
void manualMode()
{
	unsigned int numberOfBins;
	std::cout << "Enter number of bins:" << std::endl;
	std::cin >> numberOfBins;
	TestRequestExtension tre(numberOfBins);
	int selection;
	while(selection != 5) 
	{
		do {
			std::cout << "1. Process new uri" << std::endl;
			std::cout << "2. Get mean" << std::endl;
			std::cout << "3. Get sd" << std::endl;
			std::cout << "4. Get histogram" << std::endl;
			std::cout << "5. Exit manual mode" << std::endl;
			std::cin >> selection;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (selection < 1 || selection > 5);

		if(selection == 1)
		{
			std::string uri;
			std::cout << "Enter uri:" << std::endl;
			std::getline(std::cin, uri);
			tre.process(uri);
		}
		if(selection == 2)
		{
			std::string uri;
			std::cout << "Enter uri:" << std::endl;
			std::getline(std::cin, uri);
			double mean = tre.mean(uri);
			std::cout << "Mean: " << mean << "ms" << std::endl;
		}
		if(selection == 3)
		{
			std::string uri;
			std::cout << "Enter uri:" << std::endl;
			std::getline(std::cin, uri);
			double sd = tre.sd(uri);
			std::cout << "SD: " << sd << "ms" << std::endl;
		}
		if(selection == 4)
		{ 
			int histogramSelection;
			do {
				std::cout << "1: Get histogram for specific uri:" << std::endl;
				std::cout << "2. Get combined histogram for all uris:" << std::endl;
				std::cin >> histogramSelection;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} while(histogramSelection != 1 && histogramSelection != 2);
			Histogram h;
			if(histogramSelection == 1)
			{
				std::string uri;
				std::cout << "Enter the uri to be graphed:" << std::endl;
				std::getline(std::cin, uri);
				 h = tre.getHistogram(uri);
			}
			else
			{
			 	h = tre.getHistogram();
			}
			std::vector<double> data = h.getBins();
			double binSize = h.getBinSize();
			for(int i = 0; i < data.size(); i++)
			{
				double low = binSize * i;
				double high = binSize * (i+1);
				std::cout << std::setprecision(2) << std::fixed;
				std::cout << "Bin range: " << low << "-" << high << ": ";
				std::cout << std::setprecision(2) << std::fixed;
				std::cout << std::defaultfloat;
				std::cout << data[i] << std::endl; 
			
			}
		}
		if(selection == 5)
		{
			return;
		}
	}
}
void testMode()
{
	TestRequestExtension tre(10);
	std::vector<int> foo;
	foo.push_back(1);
	foo.push_back(2);
	foo.push_back(3);
	TestHistogram th(foo, 2);
	int selection;
	do {
		std::cout << "1: Run All Automated Tests for RequestExtension" << std::endl;
		std::cout << "2. Run Specific Test for TestRequestExtension" << std::endl;
		std::cout << "3. Run All Automated Tests for Histogram" << std::endl;
		std::cout << "4. Run Specific Test for Request Extension" << std::endl;
		std::cout << "5. Exit test mode" << std::endl;
		std::cin >> selection;
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while(selection < 1 || selection > 5);
	if(selection == 1)
	{
		tre.testAll();
		return;
	}
	if(selection == 2)
	{
		do {
			std::cout << "1. Test mean()" << std::endl;
			std::cout << "2. Test sd()" << std::endl;
			std::cout << "3. Test sumURIResponseTimes()" << std::endl;
			std::cout << "4. Test matches()" << std::endl;
			std::cout << "5. Test getHistogram()" << std::endl;
			std::cout << "6. Exit test mode" << std::endl;
			std::cin >> selection;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while(selection < 1 || selection > 6);

		if(selection == 1)
		{
			tre.testMean();
			return;
		}
		if(selection == 2)
		{
			tre.testSD();
			return;
		}
		if(selection == 3)
		{
			tre.testSumURIResponseTimes();
			return;
		}
		if(selection == 4)
		{
			tre.testMatches();
			return;
		}
		if(selection == 5)
		{
			tre.testGetHistogram();
			return;
		}
		if(selection == 6)
		{
			return;
		}
	}
	if(selection == 3){
		th.testAll();
		return;
	}
	if(selection == 4)
	{
		
		do {
			std::cout << "1. Test testNormalize()" << std::endl;
			std::cout << "2. Test testParseData()" << std::endl;
			std::cout << "3. Test testFillBins()" << std::endl;
			std::cout << "4. Exit test mode" << std::endl;
			std::cin >> selection;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while(selection < 1 || selection > 4);
		if(selection == 1)
		{
			th.testNormalize();
			return;
		}
		if(selection == 2) {
			th.testParseData();
			return;
		}
		if(selection == 3) {
			th.testFillBins();
			return;
		}
		if(selection == 4) {
			th.testFillBins();
			return;
		}
	}
	if(selection == 5)
		return;
}
