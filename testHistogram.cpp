 /*#include "testHistogram.hpp"



 bool testHistogram::testNormalize(){
       try 
       { 
              normalize(1,1,1);
              return false;
       } catch(exception(minIsMax))
       {
              // true
       }
       double value = 1;
       double minimum = 1;
       double maximum = 2;
       double result = normalize(value, minimum, maximum);
       if(result != 0)
              return false;
       value = 2;
       minimum = 2;
       maximum = 1;
       result = normalize(value, minimum, maximum);
       if(result != 1)
              return false;

       value = 2;
       minimum = 1;
       maximum = 5;
       result = normalize(value, minimum, maximum);
       if(result != 0.25)
              return false;
       value = 0;
       minimum = 0;
       maximum = 1;
       result = normalize(value, minimum, maximum);
       if(result != 0)
              return false;
}  

bool testBinSize();
        bool testMaxBins();
        bool testBinRange();
        bool testBinValue();
        bool testBinData();
        bool testBinRanges();
        bool testFillBins();
*/