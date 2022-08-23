#include "Histogram.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
Histogram::Histogram(std::vector<int>& data, int maxBins)
{
    if(data.size() < 2)
    {
        throw std::length_error("Histogram requires at least two unique values: ");
    }
    sort(data.begin(), data.end());
    m_occurances.push_back(1);
    m_values.push_back(data[0]);
    for(unsigned int i = 1; i < data.size(); i++)
    {
        if(data[i] != data[i-1])
        {
            m_occurances.push_back(1);
            m_values.push_back(data[i]);
            continue;
        }
        m_occurances.back()++;
    }

    int minVal = m_values.front();
    int maxVal = m_values.back();
    if(minVal == maxVal)
    {
        throw std::length_error("Histogram requires at least to unique values:");
    }
    m_maxBins = maxBins;
    fillBins();
}


void Histogram::fillBins()  
{

    for(unsigned int i = 0; i < m_values.size(); i++)
    {
        double value = m_values[i];
        double lowest = m_values.front();
        double largest = m_values.back();

        double normalizedValue = normalize(value, lowest, largest);
        m_normalizedValues.push_back(normalizedValue);
    }

    double binCount = m_maxBins;
    m_binSize = 1 / binCount;

    for(int i = 0; i < m_maxBins; i++)
    {   
        m_bins.push_back(0);
    }

    for(unsigned int i = 0; i < m_normalizedValues.size(); i++)
    {  

        int targetBin = (m_normalizedValues[i]) / m_binSize;
        if(targetBin == m_maxBins)
            targetBin--;
        m_bins[targetBin] += m_occurances[i];
    } 
}

double Histogram::normalize(double value, double minimumValue, double maximumValue)
{
    if(minimumValue == maximumValue)
    {
        throw;
    }
    return (value - minimumValue) / (maximumValue - minimumValue);
}
const int Histogram::binSize()
{
    return this->m_binSize;
}
const int Histogram::maxBins()
{
    return this->m_maxBins;
}
const std::pair<double, double> Histogram::binRange(int binNumber)
{
    double low = binNumber * m_binSize;
    double high = (binNumber + 1) * m_binSize;
    return {low, high};
}
const double Histogram::binValue(int binNumber)
{
    return m_bins[binNumber];
}
std::vector<double> Histogram::binData()
{
    return m_bins;
}
std::vector<int> Histogram::binRanges()
{
    std::vector<int> n;
    return n;
}