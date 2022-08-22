#ifndef REQUESTEXTENSION_HPP
#define REQUESTEXTENSION_HPP

#include "Request.hpp"
#include "Histogram.hpp"
#include <map>
#include <string>
#include <vector>

class RequestExtension : public Request
{
public:
    RequestExtension(int maxBins);
    const double mean(const std::string& uri);
    const double sd(const std::string& uri);
    Histogram getHistogram();
protected:
    void start(const std::string& uri);
    void finish();
private:
    std::multimap<std::string, int> m_responseMap;
    int m_maxBins;
};
#endif