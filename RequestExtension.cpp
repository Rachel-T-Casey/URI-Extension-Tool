#include "RequestExtension.hpp"
#include <vector>

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
    long uriResponseSum = this->sumURIResponseTimes(uri);
    int matches = this->matches(uri);
    return static_cast<double>(uriResponseSum) / static_cast<double>(matches);
}
const double RequestExtension::sd(const std::string& uri)
{
    return 0;
}



Histogram RequestExtension::getHistogram()
{
    int * ptr;
    Histogram h(ptr, 0);
    return h;
} 

