class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        std::vector<long long> min(k, std::numeric_limits<long long>::max());
        long long result = std::numeric_limits<long long>::min();
        long long prefix = 0;
        min[0] = 0;

        for (int i = 0; i < N; ++i) {
            prefix += nums[i];
            int mod = (i+1) % k;

            if (min[mod] != std::numeric_limits<long long>::max()) {
                result = std::max(result, prefix - min[mod]);
            }

            min[mod] = std::min(min[mod], prefix);
        }

        return result;
    }
};