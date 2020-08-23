#include "util.h"

namespace code047 {
    /********************************** 
     * Function：loga^b = logc^b/logc^a
     * Return ： loga^b
     * ********************************/    
    double mylog(double a, double b) {
        return log(b)/log(a);
    }
    // Get a random value in [low, high)
    size_t getRandInRange(size_t low, size_t high) {
        if(low+1 == high) return low;
        size_t res = rand() % (high-1 - low) + low;
        return res;
    }
    /********************************** 
     * Function ：Fast power to compute a^b
     * return ：  a^b
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

    /// <summary>
    /// String split
    /// </summary>
    /// <param name="s"></param>
    /// <param name="c"></param>
    /// <returns></returns>
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