#include "RequestExtension.hpp"
#include <vector>

RequestExtension::RequestExtension(int maxBins)
{
    this->m_maxBins = maxBins;
}
void RequestExtension::start(const std::string& uri)
{

}
void RequestExtension::finish()
{
    
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

