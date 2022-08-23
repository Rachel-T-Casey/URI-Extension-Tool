#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <vector>
class Histogram
{
public:
    

    /**
    *   This does not process any data. It only returns a blank
    * histogram.
    * 
    * @return A blank histogram.
    */
    Histogram();

    /**
     * Takes in a vector of data and a maximum number of bins.
     * processes the data, and constructs a normalized histogram
     * from the passed data. An exception will be thrown if there
     * are less than two unique data points, or if there are less
     * than two bins. If the requested maximum number of  bins
     * exceeds the number of elememts the maximum number of bins is
     * reduced to number of elements
     * 
     * @param [in] data : A vector which contains integer datapoints to
     * be graphed.
     * 
     * @param [in] maxBins : The requested number of maximum  bins. 
     * 
     * @return A Histogram which has normalized and plotted the input
     * integers into a maximum number of bins
     */
    Histogram(std::vector<int>& data, int maxBins);

    /**
    * Returns a copy of bins
    * @return A vector which contains all elements that were processed
    * by the fillBins() function 
    */
    std::vector<double> getBins();
   
    /**
    * Returns the magnitude of range of each bin. This is used to display bin 
    * ranges
    * @return A double which represents size of any bin.
    */
    double getBinSize();
    
private:

    /**
    * Returns a normalized value in a dataset given the minimum and maximum
    * value in the dataset. Minimum and maximum must differ or an exception 
    * will be thrown.
    * 
    * @exception If minimum equals maximum an exception will be thrown
    * @param [in] A double from a set of data
    * 
    * @param [in] A double representing the minimum in a set of data
    * 
    * @param [in] A double representing the maximum in a set of data 
    * Maximum must be greater than minimum or an exception is thrown
    * 
    * @returnA double between 0 and 1, representing a normalized value
    * in a dataset
    */
    double normalize(double value, double minimumValue, double maximumValue);
    

     /**
    * Sorts the input vector, then populates m_values and m_occurances 
    * with the unique values present in the input vector, and the number
    * of occurances of each value respectively. 
    * 
    * @param [in] A vector of integers which represent URI response times
    * to be later plotted.
    *
    */
    void parseData(std::vector<int>& data);
     
    /**
    * Iterates through m_values, normalizing elements and storing the normalized
    * elements in m_normalizedValues
    */
    void normalizeData();
    /**
     * Iterates through m_normalized memeber vector and calculates the correct bin
     * to store the normalized data in. Then records the number of occurances from
     * m_occurances in the respective bins
    * @param out 
    */
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