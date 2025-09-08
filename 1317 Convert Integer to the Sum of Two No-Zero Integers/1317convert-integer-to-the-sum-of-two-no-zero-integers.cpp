class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            int j = n - i;
            if (isNonZero(i) && isNonZero(j)) {
                return {i, j};
            }
        }

        return {};
    }

    bool isNonZero(int n) {
        while (n > 0) {
            int r = n % 10;
            if (r == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
};