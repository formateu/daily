class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int n: nums) {
            int divisors = 2, sum = n+1;
            for (int i = 2; i*i <= n; ++i) {
                if (n % i == 0) {
                    ++divisors;
                    sum += i;
                    if (int d2 = n / i; d2 != i) {
                        ++divisors;
                        sum += d2;
                    }
                }
                if (divisors > 4) break;
            }

            if (divisors == 4) {
                result += sum;
            }
        }

        return result;
    }
};