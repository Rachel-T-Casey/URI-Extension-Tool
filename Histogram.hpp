#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <vector>
class Histogram
{
public:
    Histogram(int* data, int bins);
    void Normalize();
    const int BinSize();
    const int MaxBins();
    const int BinRange(int binNumber);
    std::vector<int> BinData();
    std::vector<int> BinRanges();

private:
    int m_binSize;
    int m_maxBins;

};

#endif