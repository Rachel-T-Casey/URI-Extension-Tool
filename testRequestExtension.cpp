#include "RequestExtension.hpp"
#include "testRequestExtension.hpp"
#include <exception>

TestRequestExtension::TestRequestExtension(int bins) : RequestExtension(bins){

}

bool TestRequestExtension::testAll() {

    bool anyFailed = false;

    if(!testMean()){
        anyFailed = true;
    }
    if(!testSD()){
        anyFailed = true;
    }
    if(!testMatches()){
        anyFailed = true;
    }
    if(!testSumURIResponseTimes()){
        anyFailed = true;
    }
    if(!testGetHistogram()){
        anyFailed = true;
    }
    return !anyFailed;
}   
bool TestRequestExtension::testMean(){
    m_responseMap.clear();
    double result = mean("empty");
    if(result != 0){
        std::cout << "Mean failed test case 0" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 1});
    result = mean("a");
    if(result != 1){
        std::cout << "Mean failed test case 1" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 0});
    result = mean("a");
    if(result != 0.5){
        std::cout << "Mean failed test case 2" << std::endl;
        return false;
    }
    m_responseMap.insert({"b", 10});
    result = mean("a");
    if(result != 0.5){
        std::cout << "Mean failed test case 3" << std::endl;
        return false;
    }
    result = mean("b");
    if(result != 10){
        std::cout << "Mean failed test case 4" << std::endl;
        return false;
    }
    std::cout << "Mean passed all test cases" << std::endl;
    return true;
}
bool TestRequestExtension::testMatches(){   
    m_responseMap.clear();
    if(matches("test") != 0){
        std::cout << "Matches failed 0" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 1});
    m_responseMap.insert({"a", 2});
    m_responseMap.insert({"A", 3});
    if(matches("a") != 2){
        std::cout << "Matches failed test case 1" << std::endl;
        return false;
    }
    if(matches("A") != 1){
        std::cout << "Matches failed test case 2" << std::endl;
        return false;
    }
    if(matches("aA") != 0){
        std::cout << "Matches failed test case 3" << std::endl;
        return false;
    }
    std::cout << "Matches passed all test cases" << std::endl;
    return true;
}
bool TestRequestExtension::testSD(){
    m_responseMap.clear();
    double result = sd("a");
    //empty case
    if(sd("a") != 0){
        std::cout << "SD failed test case 0" << result << std::endl;
        return false;
    }
    //size one
    m_responseMap.insert({"a", 1});
    result = sd("a");
    if(result != 0){
        std::cout << "SD failed test case 1" << result << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 2});
    result = sd("a");
    if(result != 0.5){
        std::cout << "SD failed test case 2" << result << std::endl;
    }
    m_responseMap.insert({"b", 3});
    result = sd("a");
    if(result != 0.5){
        std::cout << "SD failed test case 3" << result << std::endl;
    }
    std::cout << "SD passed all test cases " << std::endl;
    return true;
}
bool TestRequestExtension::testSumURIResponseTimes(){
    m_responseMap.clear();
    long result = sumURIResponseTimes("empty");
    //empty case
    if(result != 0){
        std::cout << "sumURIResponseTimes failed test case 0" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 0});
    result = sumURIResponseTimes("a");
    if(result != 0){
        std::cout << "sumURIResponseTimes failed test case 1" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 10});
    result = sumURIResponseTimes("a");
    if(result != 10){
        std::cout << "sumURIResponsetTimes failed test case 2" << std::endl;
        return false;
    }
    m_responseMap.insert({"a", 30});
    result = sumURIResponseTimes("a");
    if(result != 40){
        std::cout << "sumURIResponseTimes failed test case 3" << std::endl;
        return false;
    }
    m_responseMap.insert({"b", 50});
    result = sumURIResponseTimes("b");
    if(result != 50){
        std::cout << "sumURIResponseTimes failed test case 4" << std::endl;
    }
    std::cout << "sumURIResponseTimes passed all test cases" << std::endl;
    return true;
}
bool TestRequestExtension::testGetHistogram(){
    m_responseMap.clear();
    
    try {
        getHistogram();
        std::cout << "getHistogram failed test case 0" << std::endl;
        return false;
    } catch(std::length_error) {}

    this->m_maxBins = 3;
    m_responseMap.insert({"a", 1});
    
    try {
        getHistogram();
        std::cout << "getHistogram failed test case 1" << std::endl;
        return false;
    } catch(std::length_error) {}

    m_responseMap.insert({"a", 1});
    try {
        getHistogram();
        std::cout << "getHistorgam failed test case 2" << std::endl;
        return false;
    } catch(std::length_error) {}

    m_responseMap.insert({"b", 3});
    getHistogram();

    std::cout << "getHistogram passed all test cases" << std::endl;
    return true;
}
