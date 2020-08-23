#pragma once
#include <cmath> // log
#include <iostream>
#include <vector>
#include <deque>
#include <cerrno>
#include <string>
#include <cstring>
#include <algorithm>
namespace code047 {
    /// <summary>
    /// Show v with 20 elements per line if v.size() <= 10000
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="v"></param>
    template<typename T>
    void display(std::vector<T>& v) {
        if (v.size() > 10000) {
            std::cout << "v.size() : " << v.size() << std::endl;
            return;
        }
        int group = 20;
        for (auto it = v.begin(); it != v.end(); it++) {
            auto count = it - v.begin();
            if (count % group == 0) {
                std::cout << std::endl;
            }
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    /********************************** 
     * Function：loga^b = logc^b/logc^a
     * Return ： loga^b
     * ********************************/    
    double mylog(double a, double b); 
    // Get a random value in [low, high)
    size_t getRandInRange(size_t low, size_t high);

    /********************************** 
     * Function ：Fast power to compute a^b
     * return ：  a^b
     * ********************************/  
    size_t fast_pow(size_t a, size_t b);

    /// <summary>
    /// String split
    /// </summary>
    /// <param name="s"></param>
    /// <param name="c"></param>
    /// <returns></returns>
    std::vector<std::string> split(const std::string &s, const std::string &c); 
}