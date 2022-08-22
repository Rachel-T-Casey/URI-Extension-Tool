#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <vector>
class Histogram
{
public:
    Histogram(std::vector<int>& data, int maxBins);
    void normalize();
    const int binSize();
    const int maxBins();
    const int binRange(int binNumber);
    std::vector<int> binData();
    std::vector<int> binRanges();

private:
    void fillBins();
    double m_binSize;
    int m_maxBins;

    std::vector<int> m_bins;
    std::vector<int> m_values;
    std::vector<int> m_occurances;

};

#endif