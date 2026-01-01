class Solution {
public:
    int countGoodNumbers(long long n) {
        const int ModFactor = std::pow(10, 9) + 7;

        long long even = modularExponentiation(5ll, std::ceil(n/2.0), ModFactor);
        long long odd = modularExponentiation(4ll, n / 2, ModFactor);
        return (even * odd) % ModFactor;
    }

private:
    int modularExponentiation(long long a, long long n, int m) {
        long long result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * a) % m;
            }

            a = (a*a) % m;
            n /= 2;
        }

        return result;
    }
};