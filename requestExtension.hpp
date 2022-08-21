#ifndef REQUESTEXTENSION_HPP
#define REQUESTEXTENSION_HPP

#include "request.hpp"
#include "histogram.hpp";

class RequestExtension : public Request
{

public:
    RequestExtension::RequestExtension(const int maxBins);
    const double Mean(const std::string& uri);
    const double SD(const std::string& uri);
    Histogram GetHistogram();
protected:

private:
    void start(const std::string& uri);
    void finish();

    std::multimap<std::string, int> m_responseMap;
    int m_maxBins;

};
#endif