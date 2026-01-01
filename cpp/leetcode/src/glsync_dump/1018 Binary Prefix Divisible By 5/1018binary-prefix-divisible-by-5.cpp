class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int N = nums.size();
        std::int64_t value = 0;
        std::vector<bool> result(N, false);

        for (int i = 0; i < N; ++i) {
            value *= 2;
            if (nums[i]) ++value;
            value %= 5;
            if (value == 0) result[i] = true;
        }

        return result;
    }
};