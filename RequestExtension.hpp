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
    * @param [out] The mean response time measured in
    * milliseconds for the given URI
    */
    const double mean(const std::string& uri);

    /**
    * Returns the standard deviation between responses
    * for a a given URI measured in milliseconds
    * 
    * @param [in] The URI being measured
    * 
    * @param [out] The standard deviation between 
    * responses measured in milliseconds time in for 
    * the given URI
    */
    const double sd(const std::string& uri);
   

    /**
    * NOT IMPLEMENTED YET 
    */
    Histogram getHistogram();

protected:
    /**
    * Sets member variable m_startTime with
    * current time.
    * Sets member variable m_uriKey with requested uri
    * 
    * @param [in] The URI of the request endpoint
    */
    void start(const std::string& uri);
    /**
    * Start processing the request in the child class
    *
    * @param [in] The URI being processed
    */
    void finish();
    /**
    * Calculates the uri processing time in milliseconds
    * using current time, and m_startTime. Then builds 
    * a pair<string int> with m_uriKey and the calculated 
    * time and inserts it into m_responseMap
    *
    * @param [in] The URI being processed
    */
private:
    /**
    * Scans through m_responseMap and returns the
    * number of times a uri has been processed
    *
    * @param [in] The URI being processed
    * 
    * @param [out] The total number of occurances
    * of the given URI
    */
    int matches(const std::string& uri);
   
    /**
    * Scans through m_responseMap and returns the 
    * aggregate total time of responses for a given
    * uri
    *
    * @param [in] The URI being processed
    * 
    * @param [out] The aggregate total response time
    * for the given URI
    */
    long sumURIResponseTimes(const std::string& uri);
    
    //Member Variables:

    // Stores processed URIs with the response time 
    std::multimap<std::string, int> m_responseMap;

    // The time point when processing began for last uri 
    std::chrono::time_point<std::chrono::steady_clock> m_startTime;
    
    // Maximum number of bins for histogram
    int m_maxBins;

    // The last uri processed
    std::string m_uriKey;

};
#endif