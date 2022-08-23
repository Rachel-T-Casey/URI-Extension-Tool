#include "Histogram.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

Histogram::Histogram() {
    
}
Histogram::Histogram(std::vector<int>& data, int maxBins)
{
    parseData(data);
    int minVal = m_values.front();
    int maxVal = m_values.back();
    if(minVal == maxVal)
    {
        throw std::length_error("Histogram requires at least two unique values:");
    }
    m_maxBins = maxBins;
    m_binSize = 1 / static_cast<double>(m_maxBins);
    for(int i = 0; i < m_maxBins; i++)
    {   
        m_bins.push_back(0);
    }

    normalizeData();
    fillBins();
}

void Histogram::parseData(std::vector<int>& data)
{
    if(data.size() < 2)
    {
        throw std::length_error("Histogram requires at least two unique values: ");
    }


    sort(data.begin(), data.end());
    m_occurances.clear();
    m_values.clear();

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
}
void Histogram::normalizeData()
{
    for(unsigned int i = 0; i < m_values.size(); i++)
    {
        double value = m_values[i];
        double lowest = m_values.front();
        double largest = m_values.back(); 
        double normalizedValue = normalize(value, lowest, largest);
        m_normalizedValues.push_back(normalizedValue);
    }
}
void Histogram::fillBins()  
{
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
        throw std::length_error("Normalization failed. Histogram requires at least two unique values:"); 
    }
    return (value - minimumValue) / (maximumValue - minimumValue);
}

std::vector<double> Histogram::getBins()
{
    return m_bins;
}

double Histogram::getBinSize()
{
    return m_binSize;
}