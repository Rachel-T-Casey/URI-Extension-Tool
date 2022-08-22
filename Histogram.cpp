#include "Histogram.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
Histogram::Histogram(std::vector<int>& data, int maxBins)
{
    if(data.size() == 0)
    {
        //edge case
    }
    sort(data.begin(), data.end());
    m_occurances.push_back(1);
    m_values.push_back(data[0]);
    for(int i = 1; i < data.size(); i++)
    {
        if(data[i] != data[i-1])
        {
            m_occurances.push_back(1);
            m_values.push_back(data[i]);
            continue;
        }
        m_occurances.back()++;
    }/*
    if(maxBins > m_values.size())
        m_maxBins = m_values.size();
    else
        m_maxBins = maxBins;

    */
        m_maxBins = maxBins;
    fillBins();

}


void Histogram::fillBins()  
{
    
    int minVal = m_values.front();
    int maxVal = m_values.back() + 1;
    double range = maxVal - (minVal-1);

    int binCount = m_maxBins;
    m_binSize = range / binCount;
    std::cout << "Bin Count: " << m_maxBins << std::endl;
    for(int i = 0; i < m_maxBins; i++)
    {
        m_bins.push_back(0);
    }
    for(int i = 0; i < m_values.size(); i++)
    {  
        int targetBin = (m_values[i] - minVal) / m_binSize;
     //   targetBin = floor(targetBin);
        m_bins[targetBin] += m_occurances[i];
    } 
    for(int i = 0; i < m_bins.size(); i++)
    {   
        std::cout << "Bin: " << i << " Range: " << minVal + (i * m_binSize) << "-" << minVal + ((i+1) * m_binSize) << std::endl;
    }
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    //final bin might fail


}

void Histogram::normalize()
{

}
const int Histogram::binSize()
{
    return this->m_binSize;
}
const int Histogram::maxBins()
{
    return this->m_maxBins;
}
const int Histogram::binRange(int binNumber)
{
    return 0;
}
std::vector<int> Histogram::binData()
{
    return m_bins;
}
std::vector<int> Histogram::binRanges()
{
    std::vector<int> n;
    return n;
}




/*

        I. 









*/