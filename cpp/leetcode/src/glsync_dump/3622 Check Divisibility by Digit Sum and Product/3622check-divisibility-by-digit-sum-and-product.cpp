class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1, originalN = n;
        while (originalN) {
            int cur = originalN % 10;
            digitSum += cur;
            digitProduct *= cur;
            originalN /= 10;
        }

        return n % (digitSum+digitProduct) == 0;
    }
};