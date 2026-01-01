class Solution {
public:
    int countLargestGroup(int n) {
        std::array<int, 36+1> sums{0};

        int max = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            int curr = i;
            while (curr > 0) {
                sum += curr % 10;
                curr /= 10;
            }
            ++sums[sum];

            if (sums[sum] > max) {
                max = sums[sum];
            }
        }

        int result = 0;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] == max) {
                ++result;
            }
        }

        return result;
    }
};