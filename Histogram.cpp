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
    }
    if(maxBins > m_values.size())
        m_maxBins = m_values.size();
    else
        m_maxBins = maxBins;
    fillBins();

}
void Histogram::fillBins()
{
    
    int minVal = m_values.front();
    int maxVal = m_values.back() + 1;
    double unroundedBinSize = (maxVal - minVal) / static_cast<double>(m_maxBins);
    int roundedBinSize = (maxVal - minVal) / m_maxBins;
    double roundingError = unroundedBinSize - roundedBinSize;
    std::cout << "MAX BINS BEFORE: " << m_maxBins << std::endl;
    while(roundingError * m_maxBins > roundedBinSize)
    {
        m_maxBins--;
        unroundedBinSize = (maxVal - minVal) / static_cast<double>(m_maxBins);
        roundingError = unroundedBinSize - roundedBinSize;
    }
    std::cout << "MAX BINS AFTER: " << m_maxBins << std::endl;
    for(int i = 0; i < m_maxBins; i++)
    {
        m_bins.push_back(0);
    }
    m_binSize = roundedBinSize;

    std::cout << "M size: " << m_values.size() << std::endl;
    std::cout << "Max bins: " << m_maxBins << std::endl;
    std::cout << "Max - minVal % m_maxBins: " << (maxVal - minVal) % m_maxBins << std::endl;
    std::cout << "Bin size: " << m_binSize << std::endl;
    std::cout <<"Range: " << maxVal - minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    for(int i = 0; i < m_values.size(); i++)
    {
        int targetBin = ((m_values[i] - minVal) / m_binSize);
        m_bins[targetBin] += m_occurances[i];
    }
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
