
#include "RequestExtension.hpp"
class TestRequestExtension : public RequestExtension
{
    public:
        TestRequestExtension(int bins);
        bool testMean();
        bool testSD();
        bool testSumURIResponseTimes();
        bool testMatches();
        bool testGetHistogram();
        bool testStart();
        bool testFinish();

};


