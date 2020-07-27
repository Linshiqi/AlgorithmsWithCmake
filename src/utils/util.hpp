/************************************************* 
Copyright:code047 
Author: code047
Date:2020-05-10
Description: 自己写的好用的函数
**************************************************/ 
#ifndef UTIL_HPP
#define UTIL_HPP
#include <cmath> // log
#include <vector>
#include <deque>
#include <cerrno>
#include <cstring>
#include <algorithm>

// https://www.nowcoder.com/ta/review-c?query=&asc=true&order=&tagQuery=&page=1

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
     * 功能：利用换底公式求loga^b
     * 
     * 输入：@a ：底数；@b ：真数
     *  
     * 返回值：loga^b
     * ********************************/    
    double mylog(double a, double b) {
        return log(b)/log(a);
    }
    // 获取一个[low, high)之间的随机数
    size_t getRandInRange(size_t low, size_t high) {
        if(low+1 == high) return low;
        int res = rand() % (high-1 - low) + low;
        return res;
    }
    /********************************** 
     * 功能：快速幂算法求a^b
     * 
     * 输入：a, b
     *  
     * 返回值：a^b
     * ********************************/  
    size_t fast_pow(size_t a, size_t b)
    {
        size_t  ans = 1;
        size_t base = a;
        while(b)
        {
            if(b & 1) {
                ans *= base;
            }
            base *=base;
            b = b >> 1;
        }
        return ans;
    }


    std::vector<std::string> split(const std::string &s, const std::string &c) {
        std::vector<std::string> res;
        std::string::size_type pos1 = 0;
        std::string::size_type pos2 = s.find(c);
        while(std::string::npos != pos2) {
            res.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2+c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 < s.size()) {
            res.push_back(s.substr(pos1));
        }

        return res;
    }
}
#endif