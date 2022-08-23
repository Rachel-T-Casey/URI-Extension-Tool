#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <vector>
class Histogram
{
public:
    Histogram(std::vector<int>& data, int maxBins);
    double normalize(double value, double small, double large);
private:
    void parseData(std::vector<int>& data);
    void normalizeData();
    void fillBins();
    double m_binSize;
    int m_maxBins;

    std::vector<double> m_bins;
    std::vector<int> m_values;
    std::vector<int> m_occurances;
    std::vector<double> m_normalizedValues;

    friend class TestHistogram;

};

#endif