#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <vector>
class Histogram
{
public:
    Histogram(std::vector<int>& data, int maxBins);
    double normalize(double value, double small, double large);
    const int binSize();
    const int maxBins();
    const std::pair<double, double> binRange(int binNumber);
    const double binValue(int binNumber);
    std::vector<double> binData();
    std::vector<int> binRanges();

private:
    void fillBins();
    double m_binSize;
    int m_maxBins;

    std::vector<double> m_bins;
    std::vector<int> m_values;
    std::vector<int> m_occurances;
    std::vector<double> m_normalizedValues;
    std::vector<double> m_normalizedOccurances;

    friend class TestHistogram;

};

#endif