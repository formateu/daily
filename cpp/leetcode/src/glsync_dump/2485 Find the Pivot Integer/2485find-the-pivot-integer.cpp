#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        const double flN = static_cast<double>(n);

        const double piv = sqrt(flN*(flN+1)/2);

        if (std::floor(piv) == piv) {
            return static_cast<int>(piv);
        }

        return -1;
    }
};