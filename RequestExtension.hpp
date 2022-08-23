#ifndef REQUESTEXTENSION_HPP
#define REQUESTEXTENSION_HPP

#include "Request.hpp"
#include "Histogram.hpp"
#include <map>
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
class RequestExtension : public Request
{
public:

    RequestExtension(int maxBins);

    /**
    * Returns the mean response time for a given URI
    * measured in milliseconds
    * 
    * @param [in] The URI being measured
    * 
    * @return The mean response time measured in
    * milliseconds for the given URI
    */
    const double mean(const std::string& uri);

    /**
    * Returns the standard deviation between responses
    * for a a given URI measured in milliseconds
    * 
    * @param [in] The URI being measured
    * 
    * @return The standard deviation between 
    * responses measured in milliseconds time in for 
    * the given URI
    */
    const double sd(const std::string& uri);
   
    /**
     * Builds histogram by combining all parsed URIs. 
     * Histogram will normalize and process the response
     * time for all uris processed by this class
     * 
     * @return A histogram which has normalized and stored all
     * uris that have been processed 
     */

    Histogram getHistogram();

    /**
     * Takes in a uri and builds a histogram using data only 
     * corresponding to the parsed uri
     * 
     * @return [in] A histogram which has normalized and stored 
     * response times for the parsed uri
     */
    Histogram getHistogram(std::string& uri);
    
private:

    /**
    * Sets member variable m_startTime with
    * current time.
    * Sets member variable m_uriKey with requested uri
    * 
    * @param [in] The URI of the request endpoint
    */
    void start(const std::string& uri);
    
    /**
    * Subtracts current time from m_startTime and converts
    * this into an int with ms units. The  Inserts a pair <string, int> 
    * into m_responseMap ith the string being the uri being processed 
    * and the int being the response time
    */

    void finish();


    /**
    * Scans through m_responseMap and returns the
    * number of times a uri has been processed
    *
    * @param The URI being processed
    * 
    * @return The total number of occurances
    * of the given URI
    */
    int matches(const std::string& uri);

    /**
    * Scans through m_responseMap and returns the 
    * aggregate total time of responses for a given
    * uri
    *
    * @param A uri 
    * 
    * @return The sum of all response times for a given uri
    */
    long sumURIResponseTimes(const std::string& uri);
    

    // Stores processed URIs with the response time 
    std::multimap<std::string, int> m_responseMap;

    // The time point when processing began for last uri 
    std::chrono::time_point<std::chrono::steady_clock> m_startTime;
    
    // Maximum number of bins for histogram
    int m_maxBins;

    // The last uri processed
    std::string m_uriKey;

    friend class TestRequestExtension;
};
#endif