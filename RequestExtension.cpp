#include "RequestExtension.hpp"
#include <vector>
#include <cmath>
RequestExtension::RequestExtension(int maxBins)
{
    this->m_maxBins = maxBins;
}
void RequestExtension::start(const std::string& uri)
{
    this->m_startTime = std::chrono::steady_clock::now();
    this->m_uriKey = uri;
}
void RequestExtension::finish()
{
    auto endTime = std::chrono::steady_clock::now();
    auto timePassed = (endTime - this->m_startTime) / 1E6;
    int timePassedInt = timePassed.count();
    m_responseMap.insert({m_uriKey, timePassedInt});
    return;
}

long RequestExtension::sumURIResponseTimes(const std::string& uri)
{
    auto range = m_responseMap.equal_range(uri);
    long total = 0;
    for(auto it = range.first; it != range.second; it++)
    {
        total += it->second;
    }
    return total;
}
int RequestExtension::matches(const std::string& uri)
{
    auto range = m_responseMap.equal_range(uri);
    return std::distance(range.first, range.second);
}
const double RequestExtension::mean(const std::string& uri)
{
    int totalMatches = this->matches(uri);
    if(totalMatches < 1)
        return 0;
    long uriResponseSum = this->sumURIResponseTimes(uri);
    return static_cast<double>(uriResponseSum) / static_cast<double>(totalMatches);
}
const double RequestExtension::sd(const std::string& uri)
{   
    int totalMatches = matches(uri);
    if(totalMatches < 1)
        return 0;
    double meanValue = this->mean(uri);
    double standardDeviation = 0.0;
    auto range = m_responseMap.equal_range(uri);
    for(auto it = range.first; it != range.second; it++)
    {
        standardDeviation += std::pow(it->second - meanValue, 2);
    }
    return std::sqrt(standardDeviation / static_cast<double>(totalMatches));
}

Histogram RequestExtension::getHistogram()
{
    std::vector<int> responseTimes;
    for(const auto &it: m_responseMap)
        responseTimes.push_back(it.second);

    Histogram h(responseTimes, m_maxBins);
    return h;
} 

