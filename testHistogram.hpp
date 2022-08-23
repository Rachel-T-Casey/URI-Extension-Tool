#ifndef TESTHISTOGRAM_HPP
#define TESTHISTOGRAM_HPP

#include "Histogram.hpp"
#include <vector>

class TestHistogram: public Histogram {

public:

    TestHistogram(std::vector<int>& data, int maxBins);

    bool testNormalize();
    bool testParseData();
    bool testFillBins();
    
private:
   

};

#endif
