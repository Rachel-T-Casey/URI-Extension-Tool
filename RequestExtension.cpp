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
}

const double RequestExtension::mean(const std::string& uri)
{
    return 0;
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

