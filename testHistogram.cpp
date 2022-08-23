
#include "testHistogram.hpp"
#include <vector>
#include <exception>
#include <iostream>
TestHistogram::TestHistogram(std::vector<int>& data, int maxBins) : Histogram(data, maxBins)
{

}

bool TestHistogram::testNormalize() 
{
       try {
        normalize(1,1,1);
        std::cout << "Test normalize failed test case 0" << std::endl;
        return false;
    } catch(std::length_error) {}

       double value = 1;
       double minimum = 1;
       double maximum = 2;
       double result = normalize(value, minimum, maximum);
       if(result != 0){
              std::cout << "Test normalize failed test case 1" << std::endl;
              return false;
       }
       value = 2;
       minimum = 1;
       maximum = 2;
       result = normalize(value, minimum, maximum);
       if(result != 1){
              std::cout << "Test normalize failed test case 2" << result << std::endl;
              return false;
       }

       value = 2;
       minimum = 1;
       maximum = 5;
       result = normalize(value, minimum, maximum);
       if(result != 0.25){
              std::cout << "Test normalize failed test case 3" << std::endl;
              return false;
       }
       value = 0;
       minimum = 0;
       maximum = 1;
       result = normalize(value, minimum, maximum);
       if(result != 0){
              std::cout << "Test normalize failed test case 4" << std::endl;
              return false;
       }
       std::cout << "Test normalize has passed test cases " << std::endl;
       return true;
}

bool TestHistogram::testParseData()
{      
       m_values.clear();
       m_occurances.clear();
       m_normalizedValues.clear();
       std::vector<int> data;
      
        try {
        parseData(data);
        std::cout << "Test parse data failed test case 0" << std::endl;
        return false;
    } catch(std::length_error) {}

       data.push_back(1);
       data.push_back(1);
       data.push_back(2);
       parseData(data);
       if(m_occurances[0] != 2 || m_values[0] != 1)
       {
              std::cout << "Test parse data failed test case 1" << std::endl;
              return false;
       }
       data.push_back(1);
       data.push_back(11);
       data.push_back(5);
       data.push_back(0);
       parseData(data);
       if(m_occurances[0] != 1 || m_values[0] != 0)
       {
              std::cout << "Test parse data failed test case 2" << std::endl;
              return false;
       }
       std::cout << "Test parse data passed test cases" << std::endl;
       return true;
}

bool TestHistogram::testFillBins()
{
       m_occurances.clear();
       m_normalizedValues.clear();
       m_values.clear();

       
}
